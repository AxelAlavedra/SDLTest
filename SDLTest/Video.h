#pragma once
#include "Utilities.h"

class Video
{
public:
	~Video();
	static Video* instance;
	void renderBackground();
	void renderRect(SDL_Rect* rect, int r, int g, int b, int a);
	static Video* getInstance();
	void render();
private:
	SDL_Renderer * renderer;
	SDL_Window*		window;
	Video();
};

