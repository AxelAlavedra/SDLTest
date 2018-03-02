#pragma once
#include "Utilities.h"
#include "Singletons.h"
class Ship
{
public:
	Ship();
	~Ship();
	void update();
	void render();
private:
	int direction;
	int state;
	SDL_Rect rect;
	void movement();
};

