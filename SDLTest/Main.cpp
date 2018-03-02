#include "Utilities.h"

void renderBackground(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);
}

void renderRect(SDL_Renderer *renderer, SDL_Rect rect) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void movement(SDL_Rect &rect, int &rectMovement) {
	switch (rectMovement) {
	case 0: {
		rect.x += 4;
		if (rect.x == WIDTH - (WIDTH / 6 + rect.w)) rectMovement = 1;
	}break;
	case 1: {
		rect.y += 4;
		if (rect.y == HEIGHT - (HEIGHT / 6 + rect.h)) rectMovement = 2;
	}break;
	case 2: {
		rect.x -= 4;
		if (rect.x == WIDTH / 6) rectMovement = 3;
	}break;
	case 3: {
		rect.y -= 4;
		if (rect.y == HEIGHT / 6) rectMovement = 0;
	}break;
	}
}

int main(int argc, char* argv[])
{
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;
	SDL_Rect rect = { WIDTH / 6,HEIGHT / 6,WIDTH / 4,HEIGHT / 4 };

	int rectMovement = 0;

	window = SDL_CreateWindow("SDLTest", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, 0);


	while (true) {
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			break;
		}
		movement(rect, rectMovement);

		renderBackground(renderer);
		renderRect(renderer, rect);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();


	return 0;
}

