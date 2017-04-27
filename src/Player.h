#pragma once
#include <iostream>
#include "Entity.h"
#include "Animation.h"
#include "Resource_Managers/Resource_Holder.h"

enum Direction
{
	LEFT,
	RIGHT
};

class Player : public Entity {
public:
	Player(Texture_Name sprite, sf::Vector2f position);
	virtual bool update(float dt);
	virtual void collision(Entity* entity);

	float walkSpeed;
	float gravity = 0.5;
	float maxVelocityY = 5;
	float maxVelocityX = 3;
	bool grounded = false;

	Animation walkAnimation;
	Animation jumpAnimation;

	Animation* currentAnimation;

	Direction direction = Direction::RIGHT;
};