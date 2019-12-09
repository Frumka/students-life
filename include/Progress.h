#pragma once

#include <iostream>
#include <Head.hpp>

using namespace sf;

extern Sprite riska2;

void draw_relations(RenderWindow& window, int math, int phis, int info)
{
	riska2.setPosition((342 + 329 + (float)math * 810 / 100) * x, (172 + 184) * y);
	std::cout << riska2.getPosition().x << std::endl;
	std::cout << riska2.getPosition().y << std::endl;
	window.draw(riska2);
	riska2.setPosition((342 + 329 + (float)phis * 810 / 100) * x, (172 + 194 + 180) * y);
	window.draw(riska2);
	riska2.setPosition((342 + 329 + (float)info * 810 / 100) * x, (172 + 184 + 382) * y);
	window.draw(riska2);
}