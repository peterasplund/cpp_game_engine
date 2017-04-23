#pragma once

#include "Playing_State.h"


namespace State
{
	State::Playing::Playing(Application& application)
	: Game_State(application)
	{
		entityManager = new EntityManager();
		Player *player = new Player();
		entityManager->add("player", player);

		Collectible *collectible = new Collectible();
		collectible->texture.setPosition({ 100, 100 });
		std::cout << collectible->getGroupID() << std::endl;
		entityManager->add("collectible", collectible);

		Collectible *collectible2 = new Collectible();
		collectible2->texture.setPosition({ 220, 450 });
		entityManager->add("collectible2", collectible2);

		Collectible *collectible3 = new Collectible();
		collectible3->texture.setPosition({ 420, 250 });
		entityManager->add("collectible3", collectible3);
	}

	void State::Playing::input()
	{

	}

	bool State::Playing::update(float dt)
	{
		return entityManager->update(dt);
	}

	void State::Playing::draw()
	{
		entityManager->draw();
	}
}
