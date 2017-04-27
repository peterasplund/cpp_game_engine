/*
#pragma once
#include "Collectible.h"
#include "Display.h"
#include "Resource_Managers/Resource_Holder.h"

#include <iostream>

Collectible::Collectible(Texture_Name sprite, sf::Vector2f position)
	: Entity(sprite, position) {
{
	groupID = GroupIDS::COLLECTIBLE;

	int tw = 32;
	int th = 32;

	texture.setTexture(&Resource_Holder::get().getTexture(Texture_Name::Coin));
	texture.setSize({ (float)tw * 2, (float)th * 2 });

	idleAnimation.addFrame({ 0,      0, tw, th }, 0.1);
	idleAnimation.addFrame({ tw,     0, tw, th }, 0.1);
	idleAnimation.addFrame({ tw * 2, 0, tw, th }, 0.1);
	idleAnimation.addFrame({ tw * 3, 0, tw, th }, 0.1);
	idleAnimation.addFrame({ tw * 4, 0, tw, th }, 0.1);
	idleAnimation.addFrame({ tw * 5, 0, tw, th }, 0.1);
	idleAnimation.addFrame({ tw * 6, 0, tw, th }, 0.1);
	idleAnimation.addFrame({ tw * 7, 0, tw, th }, 0.1);

	currentAnimation = &idleAnimation;
}

bool Collectible::update(float dt)
{
	texture.setTextureRect(currentAnimation->getFrame());
	return true;
}
*/
