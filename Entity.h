#pragma once

#include <SFML\Graphics.hpp>

enum GroupIDS
{
	STATIC      = 0,
	NORMAL      = 1,
	COLLECTIBLE = 2,
	COLLISION   = 5
};

class Entity {
public:
	Entity();
	~Entity();
	virtual void init() {};
	virtual void draw() {};
	virtual bool update(float dt);

	bool checkCollision(Entity* entity);
	virtual void collision(Entity* entity);
	int getGroupID();
	int getActive();

	void destroy();

	sf::Vector2<float> velocity;
	sf::RectangleShape texture;

protected:
	int groupID = GroupIDS::STATIC;
	int active;
};