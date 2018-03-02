#include "Utilities.h"
#include "Singletons.h"
#include "Ship.h"

Ship player;

void update() {
	player.update();
}
void render() {
	sVideoManager->renderBackground();
	player.render();
	sVideoManager->render();
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
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.scancode) {
			case SDL_SCANCODE_UP:
				player.setDirection(UP);
				player.setState(MOVING);
				break;
			case SDL_SCANCODE_DOWN:
				player.setDirection(DOWN);
				player.setState(MOVING);
				break;
			case SDL_SCANCODE_LEFT:
				player.setDirection(LEFT);
				player.setState(MOVING);
				break;
			case SDL_SCANCODE_RIGHT:
				player.setDirection(RIGHT);
				player.setState(MOVING);
				break;
			}
		}
		else player.setState(IDLE);

		update();
		render();
	}

	quit();

	return 0;
}

