#pragma once
#include "Utilities.h"
#include "Projectile.h"
#include <list>

class Ship
{
public:
	Ship();
	~Ship();
	void update();
	void render();
	void shoot();

	int xVelocity;
	int yVelocity;
private:
	void shotCooldown();
	bool canShoot();
	SDL_Rect rect;
	int speed;
	int shotCD;
	int shotTimer;
	void movement();
	std::list<Projectile*> projectiles;
	std::list<Projectile*>::iterator it;
};

