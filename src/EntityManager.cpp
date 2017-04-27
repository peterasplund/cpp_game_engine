#include "EntityManager.h"
#include "Display.h"

#include <iostream>

EntityManager::EntityManager()
{
}

void EntityManager::add(std::string name, Entity * entity)
{
	std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(name);
	while (found != this->entities.find(name))
	{
		name += "0";
		found = this->entities.find(name);
	}
	this->entities.insert(std::make_pair(name, entity));
}

Entity * EntityManager::get(std::string name)
{
	std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(name);

	if (found == this->entities.end())
	{
		return NULL;
	}
	else
	{
		return found->second;
	}
}

bool EntityManager::update(float dt)
{
	std::vector<std::string> toRemove;

	for (auto& iterator : this->entities)
	{
		switch (iterator.second->getActive())
		{
		case 0:
			toRemove.push_back(iterator.first);
			break;
		default:
			if (!iterator.second->update(dt))
			{
				return false;
			}
			break;
		}

		if (iterator.second->getGroupID() != GroupIDS::STATIC)
		{
			for (auto& iterator2 : this->entities)
			{
				if (iterator.first != iterator2.first)
				{
					if (iterator.second->getActive() && iterator2.second->getActive())
					{
						if (iterator.second->checkCollision(iterator2.second))
						{
							iterator.second->collision(iterator2.second);
						}
					}
				}
			}
		}

	}

	for (auto& iterator : toRemove)
	{
		std::unordered_map<std::string, Entity*>::const_iterator found = this->entities.find(iterator);

		if (found != this->entities.end())
		{
			delete found->second;
			this->entities.erase(iterator);
		}
	}
	toRemove.clear();

	return true;
}

void EntityManager::draw()
{
	for (auto& iterator : this->entities)
	{
		iterator.second->draw();
		Display::draw(iterator.second->texture);
	}
}

EntityManager::~EntityManager()
{
	for (auto& iterator : this->entities)
	{
		delete iterator.second;
	}
	this->entities.clear();
}
