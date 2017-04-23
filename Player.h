#pragma once
#include "Entity.h"
#include "Animation.h"

class Player : public Entity {
public:
	Player() : Entity() {
		init();
	};
	virtual void init();
	virtual void draw();
	virtual bool update(float dt);
	virtual void collision(Entity* entity);

	float walkSpeed;

	Animation walkRightAnimation;
	Animation walkLeftAnimation;
	Animation walkUpAnimation;
	Animation walkDownAnimation;

	Animation* currentAnimation;
};