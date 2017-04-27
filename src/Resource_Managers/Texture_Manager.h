#pragma once

#include <SFML/Graphics.hpp>
#include <map>

#include "Resource_Manager.h"

enum class Texture_Name
{
	Player,
	Coin,
	Block
};

class Texture_Manager : public Resource_Manager<Texture_Name, sf::Texture>
{
public:
	Texture_Manager();
};
