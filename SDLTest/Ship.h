#pragma once
#include "Utilities.h"
#include "Singletons.h"
class Ship
{
public:
	Ship();
	~Ship();
	void update();
	void setState(int st);
	int getState();
	void setDirection(int direction);
	int getDirection();
	void render();
private:
	int direction;
	int state;
	SDL_Rect rect;
	void movement();
};

