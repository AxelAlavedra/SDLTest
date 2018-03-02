#include "Utilities.h"
#include "Singletons.h"
#include "Ship.h"

Ship player;
bool quit;


void init();
void gameLoop();
void close();
void handleEvent(SDL_Event event);
void update();
void render();



int main(int argc, char* argv[])
{
	init();
	gameLoop();
	close();

	return 0;
}


void init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	quit = false;
	instanceSingletons();

	player = Ship();
}
void gameLoop() {
	SDL_Event event;
	while (!quit) {
		while (SDL_PollEvent(&event) != 0) {
			handleEvent(event);
		}
		update();
		render();
	}
}
void close() {
	destroySingletons();
	SDL_Quit();
}

void handleEvent(SDL_Event event) {
	if (event.type == SDL_QUIT) {
		quit = true;
		return;
	}

	const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
	if (currentKeyStates[SDL_SCANCODE_ESCAPE])
	{
		quit = true;
		return;
	}

	//Player Movement
	player.setState(IDLE);

	if (currentKeyStates[SDL_SCANCODE_UP])
	{
		player.setDirection(UP, true);
		player.setState(MOVING);
	} 
	else player.setDirection(UP, false);

	if (currentKeyStates[SDL_SCANCODE_DOWN])
	{
		player.setDirection(DOWN, true);
		player.setState(MOVING);
	} 
	else player.setDirection(DOWN, false);

	if (currentKeyStates[SDL_SCANCODE_LEFT])
	{
		player.setDirection(LEFT, true);
		player.setState(MOVING);
	}
	else player.setDirection(LEFT, false);

	if (currentKeyStates[SDL_SCANCODE_RIGHT])
	{
		player.setDirection(RIGHT, true);
		player.setState(MOVING);
	}
	else player.setDirection(RIGHT, false);

	//Shooting
	if (currentKeyStates[SDL_SCANCODE_SPACE])
	{
		player.shoot();
	}
}
void update() {
	player.update();
}
void render() {
	sVideoManager->renderBackground();
	player.render();
	sVideoManager->render();
}
