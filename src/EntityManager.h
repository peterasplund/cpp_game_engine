#pragma once

#include "Entity.h"

#include <string>
#include <unordered_map>
#include <vector>

class EntityManager
{
public:
	EntityManager();

	void add(std::string name, Entity* entity);
	Entity* get(std::string name);

	bool update(float dt);
	void draw();
	~EntityManager();
private:
	std::unordered_map<std::string, Entity*> entities;
};
