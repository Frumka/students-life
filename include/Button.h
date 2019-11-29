#pragma once

#include "Head.h"
#include "Draw_windows.h"
using namespace sf;

RenderWindow window(sf::VideoMode::getDesktopMode() , "Lesson 3. kychka-pc.ru", sf::Style::Fullscreen);
//RenderWindow window(sf::VideoMode(1900, 1000), "Lesson 3. kychka-pc.ru", sf::Style::None);

float x = ((float)window.getSize().x) / 1920.;
float y = ((float)window.getSize().y) / 1080.;

void button_extit()
{
	window.close();
}


class Button
{
public:
	Button() = default;
	Button(std::string path, float _x, float _y)
	{
		texture.loadFromFile(path);
		sprite.setTexture(texture);
		sprite.scale(x, y);
		x_pos = _x * x;
		y_pos = _y * y;
	}
	void draw(RenderWindow& window)
	{
		sprite.setPosition(x_pos, y_pos);
		if (sprite.getGlobalBounds().contains((float)Mouse::getPosition().x, (float)Mouse::getPosition().y))
		{
			sprite.setColor(Color::Cyan);
		}
		else
			sprite.setColor(Color::White);
		window.draw(sprite);
	}
	bool is_click()
	{
		if (sprite.getGlobalBounds().contains((float)Mouse::getPosition().x, (float)Mouse::getPosition().y) && Mouse::isButtonPressed(Mouse::Left))
		{
			while (Mouse::isButtonPressed(Mouse::Left))
			{
				continue;
			}
			return true;
		}
		else return false;
	}
private:
	float x_pos;
	float y_pos;
	Sprite sprite;
	Texture texture;
};