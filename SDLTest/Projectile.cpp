#include "Projectile.h"
#include "Game.h"


Projectile::Projectile()
{

}

Projectile::Projectile(int x, int y)
{
	speed = 25;
	rect = { x , y, 30, 5};
	destroyed = false;
}


Projectile::~Projectile()
{

}

void Projectile::update()
{
	rect.x += speed;
	if (rect.x > WIDTH) destroyed = true;
}

void Projectile::render()
{
	SDL_SetRenderDrawColor(Game::renderer, 0, 255, 0, 255);
	SDL_RenderFillRect(Game::renderer, &rect);
}

bool Projectile::getDestroyed() 
{
	return destroyed;
}