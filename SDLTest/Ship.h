#pragma once
#include "Utilities.h"
#include "Singletons.h"
#include "Projectile.h"
#include <list>

class Ship
{
public:
	Ship();
	~Ship();
	void update();
	void setState(int st);
	int getState();
	void setDirection(int direction, bool state);
	void render();
	void shoot();
private:
	void shotCooldown();
	bool canShoot();
	bool directions[4];
	int state;
	SDL_Rect rect;
	int speed;
	int shotCD;
	int shotTimer;
	void movement();
	std::list<Projectile*> projectiles;
	std::list<Projectile*>::iterator it;
};

