#pragma once
class Ship
{
public:
	Ship();
	~Ship();
	void update();
private:
	int direction = 0;
	int state = 0;
};

