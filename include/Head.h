#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/Audio.hpp>
#include <string>
#include "Hero.h"
#include "Button.h"
#include "Window.h"
#include "Player.hpp"

std::wstring str_to_wstr(const std::string& str){
    std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
    return converter.from_bytes(str);
}

