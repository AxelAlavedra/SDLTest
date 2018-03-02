#include "Ship.h"

Ship::Ship()
{
	direction = RIGHT;
	state = IDLE;
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
	sVideoManager->renderRect(&rect, 255, 0, 0, 255);
}

void Ship::movement()
{
	if (state == MOVING) {
		switch (direction) {
			case RIGHT: {
				rect.x += 4;
			}break;
			case DOWN: {
				rect.y += 4;
			}break;
			case LEFT: {
				rect.x -= 4;
			}break;
			case UP: {
				rect.y -= 4;
			}break;
		}
	}
}

void Ship::setState(int state) {
	this->state = state;
}
int Ship::getState() {
	return state;
}

void Ship::setDirection(int direction) {
	this->direction = direction;
}
int Ship::getDirection() {
	return direction;
}

