#pragma once

#include "Head.h"
//#include "event_processor.h"
#include <fstream>

//using json = nlohmann::json;

using namespace sf;

extern float x;
extern float y;

void draw_ivent(RenderWindow& window, std::string s,float wid,float x_pos,float y_pos,size_t size,Color a)
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
	Font font;//����� 
	font.loadFromFile("CyrilicOld.ttf");
	Text text;
	text.setPosition(x * x_pos + 5, y * y_pos);
	text.setFont(font);
	text.setFillColor(a);
	std::string str = "";
	text.setCharacterSize((unsigned int)size*y);
	for (size_t i = 0; i < words.size(); i++)
	{
		str += words[i];
		if (text.getLocalBounds().width <= wid)
		{
			text.setString(str);
		}
		else
		{
			y_pos += text.getCharacterSize() * y;
			window.draw(text);
			text.setString("");
			text.setPosition(x * x_pos, y * y_pos);
			str = "";
		}
	}
	window.draw(text);
}

void draw_money(RenderWindow& window, int a)
{
	Font font;//����� 
	font.loadFromFile("CyrilicOld.ttf");//�������� ������ ������ ���� ������
	Text text(std::to_string(a), font, 40*y);//������� ������ �����. ���������� � ������ ����� ������, �����, ������ ������(� ��������);//��� ������ ����� (�� ������)
	text.setFillColor(Color(0,145,26,255));
//	text.setStyle(sf::Text::Bold | sf::Text::Underlined);//������ � ������������ �����. �� ��������� �� "�����":)) � �� ������������
	text.setPosition(1717*x, 285*y);
	window.draw(text);
}

class Background
{
public:
	Background() = default;
	Background(std::string path)
	{
		texture.loadFromFile(path);
		sprite.setTexture(texture);
		is_active = 0;
		sprite.setScale(x,y);
	}
	Background(const Background& a)
	{
		arr = a.arr;
		sprite = a.sprite;
		is_active = a.is_active;
	}

	Background& operator = (Background& a)
	{
		sprite = a.sprite;
		arr = a.arr;
		texture = a.texture;
		is_active = a.is_active;
		return *this;
	}
	void draw(RenderWindow& window)
	{
		window.draw(sprite);
		for (size_t i = 0; i < arr.size(); i++)
		{	
			arr[i]->draw(window);
		}
	}
	bool get_status()
	{
		return is_active;
	}
	void set_status(bool a)
	{
		is_active = a;
	}
	void push_button(Button &a)
	{
		Button* ptr = &a;
		arr.push_back(ptr);
	}
	operator bool() const
	{
		return is_active;
	}
	std::vector<Button*> vec()
	{
		return arr;
	}
	Sprite get_sprite() const
	{
		return sprite;
	}
	bool is_active = false;
private:
	sf::Texture texture;
	std::vector<Button*> arr;
	sf::Sprite sprite;
};