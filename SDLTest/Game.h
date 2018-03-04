#pragma once
#include "Utilities.h"

class Game
{
public:
	Game();
	~Game();

	void init();
	void handleEvents();
	void update();
	void render();
	void close();

	bool running() { return isRunning; };
	static SDL_Renderer* renderer;
private:
	bool isRunning;
	SDL_Window* window;

};

