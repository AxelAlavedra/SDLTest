#include "Projectile.h"



Projectile::Projectile()
{

}

Projectile::Projectile(int x, int y)
{
	speed = 15;
	rect = { x , y, 30, 25};
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
	sVideoManager->renderRect(&rect, 0, 255, 0, 255);
}

bool Projectile::getDestroyed() 
{
	return destroyed;
}