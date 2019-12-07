#pragma once
#include <string>
#include <vector>
#include "Head.h"

using namespace sf;



class product
{
public:
	product(int _price, int _health, int _mood)
	{
		price = _price;
		health = _health;
		mood = _mood;
	}
	int price;
	int health;
	int mood;
};

std::vector<product*> products;

extern Background shop;

extern float x;
extern float y;
extern RenderWindow window;
extern Sprite price;

void draw_shop(int &money,int &mood,int &health)
{
	shop.draw(window);
	for (size_t i = 0; i < products.size(); i++)
	{
		Text str;
		Font font;
		font.loadFromFile("CyrilicOld.ttf");
		str.setFillColor(Color::Yellow);
		str.setCharacterSize(30 * y);
		str.setFont(font);
		str.setPosition(shop.arr[i]->x_pos + 120*x, shop.arr[i]->y_pos + 142 * y);
		str.setString(std::to_string(products[i]->price) + ".ð");
		price.setPosition(shop.arr[i]->x_pos + 110*x , shop.arr[i]->y_pos + 130*y);
		price.setScale(x, y);
		window.draw(price);
		window.draw(str);
		if (shop.arr[i]->is_click())
		{
			if (products[i]->price <= money)
			{
				money -= products[i]->price;
				mood += products[i]->mood;
				health += products[i]->health;
			}
		}
	}

}