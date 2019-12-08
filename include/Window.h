#pragma once

#include "Head.h"
#include "Player.hpp"
#include <event_processor.hpp>
#include <fstream>
#include <codecvt>

using namespace sf;

extern float x;
extern float y;

void draw_ivent(RenderWindow& window, std::string s, float wid, float x_pos, float y_pos, size_t size, Color a)
{

	s += " ";
	size_t pos1 = 0;
	size_t pos2 = 0;
	std::vector<std::string> words;
	for (size_t i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
		{
			pos2 = i;
			words.push_back(s.substr(pos1, pos2 - pos1));
			pos1 = pos2;
		}
	}
	Font font;
	font.loadFromFile("CyrilicOld.TTF");
	Text text;
	text.setPosition(x * x_pos + 5, y * y_pos);
	text.setFont(font);
	text.setFillColor(a);
	std::string str = "";
	text.setCharacterSize(static_cast<unsigned int>(size));
	for (size_t i = 0; i < words.size(); i++)
	{
		str += words[i];
		if (text.getLocalBounds().width <= wid)
		{
			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
			std::wstring wstr = converter.from_bytes(str);
			text.setString(wstr);
		}
		else
		{
			y_pos += text.getCharacterSize() * y;
			window.draw(text);
			text.setString(words[i]);
			text.setPosition(x * x_pos, y * y_pos);
			str = words[i];
		}
	}
	window.draw(text);
}

void draw_money(RenderWindow &window, const Player &player) {
    Font font;//�����
    font.loadFromFile("CyrilicOld.TTF");//�������� ������ ������ ���� ������
    Text text(std::to_string(player.get_money()), font, 45 *
                                                        y);//������� ������ �����. ���������� � ������ ����� ������, �����, ������ ������(� ��������);//��� ������ ����� (�� ������)
    text.setFillColor(Color(0, 145, 26, 255));
//	text.setStyle(sf::Text::Bold | sf::Text::Underlined);//������ � ������������ �����. �� ��������� �� "�����":)) � �� ������������
    text.setPosition(1690 * x, 372 * y);
    window.draw(text);
}

void draw_mood(RenderWindow &window, const Player &player) {
    Font font;//�����
    std::string str;
    str = std::to_string(player.get_mood());
    str += " / 100";
    font.loadFromFile("CyrilicOld.TTF");//�������� ������ ������ ���� ������
    Text text(str, font, 45 *
                         y);//������� ������ �����. ���������� � ������ ����� ������, �����, ������ ������(� ��������);//��� ������ ����� (�� ������)
    text.setFillColor(Color(252, 247, 22, 255));
    //	text.setStyle(sf::Text::Bold | sf::Text::Underlined);//������ � ������������ �����. �� ��������� �� "�����":)) � �� ������������
    text.setPosition(1690 * x, 440 * y);
    window.draw(text);
}

void draw_health(RenderWindow &window, const Player &player) {
    Font font;//�����
    std::string str;
    str = std::to_string(player.get_health());
    str += " / 100";
    font.loadFromFile("CyrilicOld.TTF");//�������� ������ ������ ���� ������
    Text text(str, font, 45 *
                         y);//������� ������ �����. ���������� � ������ ����� ������, �����, ������ ������(� ��������);//��� ������ ����� (�� ������)
    text.setFillColor(Color(251, 46, 23, 255));
    //	text.setStyle(sf::Text::Bold | sf::Text::Underlined);//������ � ������������ �����. �� ��������� �� "�����":)) � �� ������������
    text.setPosition(1690 * x, 515 * y);
    window.draw(text);
}

class Background {
public:
    Background() = default;

    Background(std::string path) {
        texture.loadFromFile(path);
        sprite.setTexture(texture);
        sprite.scale(x, y);
        is_active = 0;
    }

    Background(const Background &a) {
        arr = a.arr;
        sprite = a.sprite;
        is_active = a.is_active;
    }

    Background &operator=(Background &a) {
        sprite = a.sprite;
        arr = a.arr;
        texture = a.texture;
        is_active = a.is_active;
        return *this;
    }

    void draw(RenderWindow &window) {
        window.draw(sprite);
        for (size_t i = 0; i < sprites.size(); i++) {
            window.draw(sprites[i]);
            //std::cout << "Sprite";
        }
        for (size_t i = 0; i < arr.size(); i++) {
            arr[i]->draw(window);
        }
    }

    void push_sprite(std::string path, double x_pos, double y_pos) {
        Texture t;
        textures.push_back(t);
        textures[textures.size() - 1].loadFromFile(path);
        Sprite sprite;
        sprites.push_back(sprite);
        sprites[sprites.size() - 1].setTexture(textures[textures.size() - 1]);
        sprites[sprites.size() - 1].setPosition(x_pos * x, y_pos * y);
        sprites[sprites.size() - 1].scale(x, y);
    }

    bool get_status() {
        return is_active;
    }

    void set_status(bool a) {
        is_active = a;
    }

    void push_button(Button &a) {
        Button *ptr = &a;
        arr.push_back(ptr);
    }

    operator bool() const {
        return is_active;
    }

    std::vector<Button *> vec() {
        return arr;
    }

    Sprite get_sprite() const {
        return sprite;
    }

    bool is_active = false;
    std::vector<Button *> arr;
private:
    sf::Texture texture;
    std::vector<Sprite> sprites;
    std::vector<Texture> textures;
    sf::Sprite sprite;
};