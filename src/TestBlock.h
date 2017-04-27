#pragma once
#include <iostream>
#include "Entity.h"
#include "Animation.h"
#include "Display.h"
#include "Resource_Managers/Resource_Holder.h"

class TestBlock : public Entity {
public:
	TestBlock(Texture_Name sprite, sf::Vector2f position);
};