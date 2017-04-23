#pragma once
#include "Entity.h"
#include "Animation.h"

class Collectible : public Entity {
public:
	Collectible() : Entity() {
		init();
	};
	virtual void init();
	virtual void draw();
	void collision(Entity * entity);
	virtual bool update(float dt);

	Animation idleAnimation;
	Animation* currentAnimation;
};