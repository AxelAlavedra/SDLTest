#include "Video.h"


Video* Video::instance = NULL;

Video::Video()
{
	window = SDL_CreateWindow("SDLTest", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, 0);
}

Video::~Video()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void Video::renderBackground()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);
}

void Video::renderRect(SDL_Rect* rect, int r, int g, int b, int a)
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, rect);
}

Video* Video::getInstance()
{
	if (!instance)
	{
		instance = new Video();
	}
	return instance;
}

void Video::render()
{
	SDL_RenderPresent(renderer);
}
