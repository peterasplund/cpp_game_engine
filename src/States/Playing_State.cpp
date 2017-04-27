#pragma once

#include "Playing_State.h"


namespace State
{
	State::Playing::Playing(Application& application)
	: Game_State(application)
	{
		entityManager = new EntityManager();

		Player *player = new Player(Texture_Name::Player, { 30, 100 });
		entityManager->add("player", player);
		
		TestBlock *block1 = new TestBlock(Texture_Name::Block, { 30, 550 });
		entityManager->add("block1", block1);
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
