#include "Ship.h"

Ship::Ship()
{
	direction = RIGHT;
	state = MOVING;
	rect = { WIDTH / 6,HEIGHT / 6,WIDTH / 4,HEIGHT / 4 };
}


Ship::~Ship()
{
}

void Ship::update()
{
	movement();	
}

void Ship::render() 
{
	VideoManager->renderRect(&rect, 255, 0, 0, 255);
}

void Ship::movement()
{
	if (state == MOVING) {
		switch (direction) {
			case RIGHT: {
				rect.x += 4;
				if (rect.x == WIDTH - (WIDTH / 6 + rect.w)) direction = DOWN;
			}break;
			case DOWN: {
				rect.y += 4;
				if (rect.y == HEIGHT - (HEIGHT / 6 + rect.h)) direction = LEFT;
			}break;
			case LEFT: {
				rect.x -= 4;
				if (rect.x == WIDTH / 6) direction = UP;
			}break;
			case UP: {
				rect.y -= 4;
				if (rect.y == HEIGHT / 6) direction = RIGHT;
			}break;
		}
	}
}
