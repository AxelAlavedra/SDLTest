#pragma once
#include "Utilities.h"

class Projectile
{
public:
	Projectile();
	Projectile(int x, int y);
	~Projectile();
	void update();
	void render();
	bool getDestroyed();
private:
	bool destroyed;
	int speed;
	SDL_Rect rect;
};

