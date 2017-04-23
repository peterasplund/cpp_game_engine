#pragma once

#include "Entity.h"
#include <iostream>

Entity::Entity()
{
	active = 1;

	init();
}

bool Entity::update(float dt)
{
	texture.move(this->velocity);
	return true;
}

void Entity::collision(Entity* entity)
{
}

bool Entity::checkCollision(Entity* entity)
{
	return texture.getGlobalBounds().intersects(entity->texture.getGlobalBounds());
}

int Entity::getGroupID()
{
	return groupID;
}

int Entity::getActive()
{
	return active;
}

void Entity::destroy()
{
	active = 0;
}

Entity::~Entity()
{
}
