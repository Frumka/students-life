#pragma once

#include "Head.h"

using namespace sf;

extern double x;
extern double y;

class Background
{
public:
	Background() = default;
	Background(std::string p)
	{
		texture.loadFromFile(p);
		sprite.setTexture(texture);
		//sprite.scale(x, y);
		is_active = 0;
	}
	Background(const Background& a)
	{
		arr = a.arr;
		sprite = a.sprite;
		is_active = a.is_active;
	}

	Background& operator = (const Background& a)
	{
		arr = a.arr;
		sprite = a.sprite;
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
private:
	sf::Texture texture;
	std::vector<Button*> arr;
	sf::Sprite sprite;
	bool is_active = false;
};