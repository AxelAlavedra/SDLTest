#include "Utilities.h"
#include "Game.h"


int frame = 0;
Game* game = nullptr;

int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS; //tiempo que tarda un frame

	game = new Game();
	game->init();

	Uint32 frameStart;
	int frameTime;
	
	while (game->running()) {

		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->close();

	return 0;
}
