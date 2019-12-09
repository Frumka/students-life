//
// Created by atrum on 09.12.19.
//

#ifndef STUDENT_LIFE_MAIN_WSTR_CAST_HPP
#define STUDENT_LIFE_MAIN_WSTR_CAST_HPP

#include <codecvt>

std::wstring str_to_wstr(const std::string &str) {
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.from_bytes(str);
}

#endif //STUDENT_LIFE_MAIN_WSTR_CAST_HPP
