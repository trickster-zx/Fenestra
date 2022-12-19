/*
 * Copyright © Windower Dev Team
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation files
 * (the "Software"),to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef WINDOWER_ADDON_MODULES_CHAT_HPP
#define WINDOWER_ADDON_MODULES_CHAT_HPP

#include "addon/lua.hpp"
#include "addon/modules/event.hpp"

#include <string>
#include <string_view>

namespace windower
{

namespace detail
{

struct text_added_result_data
{
    text_added_result_data(
        std::u8string text, std::uint8_t type, bool indented) :
        text{text},
        type{type}, indented{indented}
    {}

    std::u8string text;
    std::uint8_t type;
    bool indented;
};

}

class text_added_result : public basic_result<detail::text_added_result_data>
{
public:
    using basic_result::basic_result;

    std::u8string_view text() const noexcept;
    std::uint8_t type() const noexcept;
    bool indented() const noexcept;
};

text_added_result
trigger_text_added(std::u8string_view text, std::uint8_t type, bool indented);

int load_chat_module(lua::state);

}

#endif
