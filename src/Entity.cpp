#pragma once

#include "Entity.h"

Entity::Entity(Texture_Name sprite, sf::Vector2f position)
{
	this->sprite.setTexture(Resource_Holder::get().getTexture(Texture_Name::Player));
	this->sprite.setScale({ 2, 2 });
	body.setSize({ this->sprite.getGlobalBounds().width, this->sprite.getGlobalBounds().height });

	active = 1;
}

void Entity::draw()
{
	Display::draw(sprite);
}

bool Entity::update(float dt)
{
	body.move(this->velocity);
	sprite.setPosition(body.getPosition());
	return true;
}

void Entity::collision(Entity* entity)
{
}

bool Entity::checkCollision(Entity* entity)
{
	return body.getGlobalBounds().intersects(entity->body.getGlobalBounds());
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
