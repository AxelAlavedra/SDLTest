#include "Utilities.h"
#include "Singletons.h"
#include "Ship.h"

Ship player;

void update() {
	player.update();
}
void render() {
	VideoManager->renderBackground();
	player.render();
	VideoManager->render();
}
void init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	instanceSingletons();

	player = Ship();
}
void quit() {
	destroySingletons();
	SDL_Quit();
}

int main(int argc, char* argv[])
{
	SDL_Event event;
	init();

	while (true) {
		SDL_PollEvent(&event);
		if (event.type == SDL_QUIT) {
			break;
		}

		update();
		render();
	}

	quit();

	return 0;
}

