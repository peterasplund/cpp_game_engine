#pragma once

#include <SFML/Graphics.hpp>

namespace Display
{
	void init();

	void clear();
	void display();

	void draw(const sf::Drawable& drawable);

	void checkWindowEvents();

	bool isOpen();

	constexpr int HEIGHT = 720;
	constexpr int WIDTH  = 1280;
}
