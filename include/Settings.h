#pragma once

#include "Head.h"
#include "Draw_windows.h"
using namespace sf;
extern Background nastroyki;
extern float x;
extern float y;
extern RenderWindow window;
extern std::vector<std::string> com;

void sound_volume(float y_pos, Sprite& riska, int& volume)
{
	riska.setScale(x, y);
	float x_pos = ((volume * 477. / 100) + 1028) * x;
	Event event;
	window.pollEvent(event);
	if (riska.getGlobalBounds().contains((float)Mouse::getPosition().x, (float)Mouse::getPosition().y))//� ��� ���� ���������� ������� �������� � ������
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			volume = ((float)Mouse::getPosition().x - (float)1030 * x) * 100. / (470. * x);
			std::cout << volume;
			if (volume <= 4)
			{
				std::cout << "++";
				volume = 0;
			}
			if (volume >= 100)
			{
				std::cout << "--";
				volume = 100;
			}
			std::cout << volume;
		}

	}
	riska.setPosition((1030 + volume * 470. / 100 - 30) * x, y_pos * y);
	window.draw(riska);
}

void Complexity(RenderWindow& window, int& index)
{
	if (nastroyki.arr[0]->is_click())
	{
		if (index == 0)
		{
			index = 2;
		}
		else
		{
			index--;
		}
	}
	if (nastroyki.arr[1]->is_click())
	{
		index = (index + 1) % 3;
	}
	Text str;
	Font font;
	font.loadFromFile("CyrilicOld.TTF");
	str.setFillColor(Color::Black);
	str.setCharacterSize(80);
	str.setFont(font);
	str.setScale(x, y);
	str.setPosition((638 + 342) * x, (184 + 554) * y);
	str.setString(str_to_wstr(com[index]));
	window.draw(str);
}