#include <iostream>

#include "Application.h"
#include "Util/Random.h"

int main()
{
	Random::init();

	Application app;
	app.runMainLoop();

	return 0;
}