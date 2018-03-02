#include "Ship.h"

Ship::Ship()
{
	state = IDLE;
	speed = 5;
	shotTimer = 0;
	shotCD = 25;
	rect = { WIDTH / 6,HEIGHT / 6,WIDTH / 4,HEIGHT / 4 };
	for (bool &dir : directions) {
		dir = false;
	}
}

Ship::~Ship()
{
	projectiles.clear();
}

void Ship::update()
{
	movement();
	shotCooldown();
	if (!projectiles.empty()) {
		for (it = projectiles.begin(); it != projectiles.end();)
		{
			(*it)->update();
			if ((*it)->getDestroyed()) it = projectiles.erase(it);
			else ++it;
		}
	}
}

void Ship::render()
{
	sVideoManager->renderRect(&rect, 255, 0, 0, 255);
	for (Projectile* &proj : projectiles) {
		proj->render();
	}
}

void Ship::shoot()
{
	if (canShoot()) {
		Projectile* proj = new Projectile(rect.x + rect.w, rect.y + (rect.h/2 - 25));
		projectiles.push_back(proj);
		shotTimer = shotCD;
	}
}

void Ship::shotCooldown()
{
	if (shotTimer > 0) shotTimer--;
}

bool Ship::canShoot() {
	if (shotTimer == 0) return true;
	else return false;
}

void Ship::movement()
{
	if (state == MOVING) {
		if (directions[UP]) rect.y -= speed;
		if (directions[DOWN]) rect.y += speed;
		if (directions[RIGHT]) rect.x += speed;
		if (directions[LEFT]) rect.x -= speed;
	}
}

void Ship::setState(int state) {
	this->state = state;
}
int Ship::getState() {
	return state;
}

void Ship::setDirection(int direction, bool state) {
	directions[direction] = state;
}

