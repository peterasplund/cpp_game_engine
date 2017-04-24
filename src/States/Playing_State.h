#pragma once

#include <iostream>

#include "Game_State.h"
#include "../EntityManager.h"
#include "../Application.h"
#include "../Display.h"
#include "../Player.h"
#include "../Collectible.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

namespace State
{
	class Playing : public Game_State
	{
	public:
		Playing(Application& application);

		void input  () override;
		bool update (float dt) override;
		void draw   () override;
	private:
		EntityManager *entityManager;
	};
}
