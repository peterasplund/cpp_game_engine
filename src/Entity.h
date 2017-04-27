#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Collider.h"
#include "Display.h"
#include "Resource_Managers/Resource_Holder.h";

enum GroupIDS
{
	STATIC      = 0,
	NORMAL      = 1,
	COLLECTIBLE = 2,
	COLLISION   = 5
};

class Entity {
public:
	Entity(Texture_Name sprite, sf::Vector2f position);
	~Entity();
	virtual void draw();
	virtual bool update(float dt);

	bool checkCollision(Entity* entity);
	virtual void collision(Entity* entity);
	int getGroupID();
	int getActive();

	void destroy();

	sf::Vector2<float> velocity;
	sf::RectangleShape texture;
	sf::Sprite sprite;
	sf::RectangleShape body;
	Collider getCollider() { return Collider(body); }

protected:
	int groupID = GroupIDS::STATIC;
	int active;
};
