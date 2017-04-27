/*
#pragma once
#include "Entity.h"
#include "Animation.h"

class Collectible : public Entity {
public:
	Collectible(Texture_Name sprite, sf::Vector2f position);
	virtual void draw();
	void collision(Entity * entity);
	virtual bool update(float dt);

	Animation idleAnimation;
	Animation* currentAnimation;
};
*/