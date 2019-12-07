#pragma once
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Window.h"
#include <string>
using namespace sf;


int mont(Player &player)
{

	int money = player.get_money();
	extern RenderWindow window;
	srand(time(0));
	Clock clock;
	Time timer = seconds(1);
	Font font;
	font.loadFromFile("CyrilicOld.TTF");
	std::cout << " fafaf " << std::endl;
	clock.restart();
	window.setKeyRepeatEnabled(false);
	Background game("images/Job_play.png");
	size_t k = 0;
	Text _k;
	_k.setCharacterSize(100);
	_k.setFillColor(Color::Black);
	_k.setFont(font);
	_k.setPosition(1325, 425);
	Texture texture;
	Sprite text;
	while (timer.asSeconds() < 20)
	{
		game.draw(window);
		bool flag = true;
		
		//bool push = true;
		size_t i = std::rand() % 4;
		if (i == 0)
		{
			texture.loadFromFile("images/Game__but0.png");
			text.setTexture(texture);
		}
		if (i == 1)
		{
			texture.loadFromFile("images/Game__but1.png");
			text.setTexture(texture);
		}
		if (i == 2)
		{
			texture.loadFromFile("images/Game__but2.png");
			text.setTexture(texture);
		}
		if (i == 3)
		{
			texture.loadFromFile("images/Game__but3.png");
			text.setTexture(texture);
		}
		text.setPosition(800, 430);
		window.draw(text);
		window.draw(_k);
		window.display();
		while (timer.asSeconds() < 20)
		{
			//window.display();
			std::cout << money << std::endl;
			Event event;
			window.pollEvent(event);
			if (event.type == Event::KeyPressed)
			{
				if (i == 0 && event.key.code == Keyboard::Left)
				{
					timer = clock.getElapsedTime();
					while (event.type == event.KeyPressed)
					{
						if (timer.asSeconds() > 20)
							break;
						window.pollEvent(event);
						continue;
					}
					k++;
					_k.setString(std::to_string(k));
					money += 100;
					break;
				}
				if (i == 1 && event.key.code == Keyboard::Up)
				{
					//window.display();
					timer = clock.getElapsedTime();
					while (event.type == event.KeyPressed)
					{
						if (timer.asSeconds() > 20)
							break;
						window.pollEvent(event);
						continue;
					}
					k++;
					_k.setString(std::to_string(k));
					money += 100;
					break;
				}
				if (i == 2 && event.key.code == Keyboard::Right)
				{
					//window.display();
					timer = clock.getElapsedTime();
					while (event.type == event.KeyPressed)
					{
						if (timer.asSeconds() > 20)
							break;
						window.pollEvent(event);
						continue;
					}
					k++;
					_k.setString(std::to_string(k));
					money += 100;
					break;
				}
				if (i == 3 && event.key.code == Keyboard::Down)
				{
					//window.display();
					timer = clock.getElapsedTime();
					while (event.type == event.KeyPressed)
					{
						if (timer.asSeconds() > 20)
							break;
						window.pollEvent(event);
						continue;
					}
					k++;
					_k.setString(std::to_string(k));
					money += 100;
					break;
				}
				else
				{
					//window.display();
					while (event.type == event.KeyPressed)
					{
						timer = clock.getElapsedTime();
						if (timer.asSeconds() > 20)
							break;
						window.pollEvent(event);
						continue;
					}

					money -= 100;
					break;
				}
			}
			timer = clock.getElapsedTime();

			if (timer.asSeconds() > 20)
				break;
		}
		timer = clock.getElapsedTime();
		// window.display();
	}
	return money;
}
