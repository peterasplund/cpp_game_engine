#pragma once

#include <SFML/Audio.hpp>
#include <map>

#include "Resource_Manager.h"

enum class Sound_Name
{
	Test
};

class Sound_Manager : public Resource_Manager<Sound_Name, sf::SoundBuffer>
{
public:
	Sound_Manager();
};
