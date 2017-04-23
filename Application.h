#pragma once

#include <memory>
#include <stack>

#include "States\Game_State.h"
#include "Resource_Managers\Resource_Holder.h"

class Application
{
public:
	Application();

	void runMainLoop();

	void pushState(std::unique_ptr<State::Game_State> state);
	void popState();

	void changeState(std::unique_ptr<State::Game_State> state);
private:
	std::stack<std::unique_ptr<State::Game_State>> m_states;
};