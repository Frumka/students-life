#pragma once
#include <iostream>
#include <Head.h>

using namespace sf;

extern Sprite riska2;

void draw_relations(RenderWindow &window,int family, int friends, int girlfriend)
{
	riska2.setPosition((328 + 324 + (float)family * 810 / 100)*x,(172 + 184) * y);
	std::cout << riska2.getPosition().x <<std::endl;
	std::cout << riska2.getPosition().y << std::endl;
	window.draw(riska2);
}