#pragma once

#include "Head.h"
#include "Draw_windows.h"
using namespace sf;

RenderWindow window(sf::VideoMode::getDesktopMode(), "Lesson 3. kychka-pc.ru",sf::Style::Fullscreen);

double x = window.getSize().x / 1920.;
double y = window.getSize().y / 1080.;

void button_extit()
{
	window.close();
}

void* ptr = button_extit;

class Button
{
public:
	Button() = default;
	Button(std::string path,double _x,double _y)
	{
		texture.loadFromFile(path);
		sprite.setTexture(texture);
		sprite.scale(x, y);
		x_pos = _x*x;
		y_pos = _y*y;
	}
	void draw(RenderWindow& window)
	{
		sprite.setPosition(x_pos, y_pos);
		if (sprite.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y))
		{
			sprite.setColor(Color::Cyan);
		}
		else
			sprite.setColor(Color::White);
		window.draw(sprite);
	}
	bool is_click()
	{
		if (sprite.getGlobalBounds().contains(Mouse::getPosition().x, Mouse::getPosition().y) && Mouse::isButtonPressed(Mouse::Left))
		{
			return true;
		}
		else false;
	}
private:
	double x_pos;
	double y_pos;
	Sprite sprite;
	Texture texture;
};