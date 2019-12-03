#pragma once

#include "Head.h"
#include "Draw_windows.h"
using namespace sf;

extern float x;
extern float y;
extern RenderWindow window;

void sound_volume(float y_pos, Sprite& riska, int& volume)
{
	riska.setScale(x, y);
	float x_pos = ((volume * 477. / 100) + 1028) * x;
	Event event;
	window.pollEvent(event);
	if (riska.getGlobalBounds().contains((float)Mouse::getPosition().x, (float)Mouse::getPosition().y))//и при этом координата курсора попадает в спрайт
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


/*void sound_volume(float y_pos, Sprite& riska, int& volume)
{
	bool isMove = false;
	float dX = 0;
	float dY = 0;
	Event event;
	float x_pos;
	x_pos = 1234;
	bool is_move = false;
	while (window.pollEvent(event))
	{
		float x_pos = ((volume * 477. / 100) + 1028) * x;
		//float x_pos = 1028;
		Event event;
		window.pollEvent(event);
		if (riska.getGlobalBounds().contains((float)Mouse::getPosition().x, (float)Mouse::getPosition().y))//и при этом координата курсора попадает в спрайт
		{
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				is_move = true;
				volume = (Mouse::getPosition().x - (float)1030 * x) * 100. / 470;
				std::cout << volume;
				if (volume <= 0)
				{
					std::cout << "++";
					volume = 1;
				}
				if (volume >= 99)
				{
					std::cout << "--";
					volume = 95;
				}
				if (event.type == Event::MouseButtonReleased)
				{
					is_move = false;
				}
			}

		}
	}
	window.draw(riska);
	window.display();
}*/
