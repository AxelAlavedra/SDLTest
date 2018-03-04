#include "Ship.h"
#include "Game.h"

Ship::Ship()
{
	speed = 5;
	shotTimer = 0;
	shotCD = 10;
	xVelocity = 0;
	yVelocity = 0;
	rect = { WIDTH / 6,HEIGHT / 6,WIDTH / 4,HEIGHT / 4 };
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
	SDL_SetRenderDrawColor(Game::renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(Game::renderer, &rect);
	for (Projectile* &proj : projectiles) {
		proj->render();
	}
}

void Ship::shoot()
{
	if (canShoot()) {
        Projectile* proj = new Projectile(rect.x + rect.w, rect.y + (rect.h/2 - 5));
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
	rect.x += xVelocity * speed;
	rect.y += yVelocity * speed;
}

