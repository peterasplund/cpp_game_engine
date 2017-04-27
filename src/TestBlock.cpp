#pragma once
#include "TestBlock.h"

TestBlock::TestBlock(Texture_Name sprite, sf::Vector2f position)
	: Entity(sprite, position) {
	groupID = GroupIDS::COLLISION;
}