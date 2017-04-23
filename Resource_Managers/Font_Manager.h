#pragma once

#include <SFML\Graphics.hpp>
#include <map>

#include "Resource_Manager.h"

enum class Font_Name
{
	Test
};

class Font_Manager : public Resource_Manager<Font_Name, sf::Font>
{
public:
	Font_Manager();
};
