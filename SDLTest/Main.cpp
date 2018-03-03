#include "Utilities.h"
#include "Singletons.h"
#include "Ship.h"

Ship player;
bool quit = false;
int frame = 0;


void init();
void gameLoop();
void close();
void handleEvents();
void playerMovement(const Uint8* currentKeyStates);
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
	instanceSingletons();

	player = Ship();
}

void gameLoop() {
	SDL_Event event;
	
	Uint32 frameStart;
	int frameTime;

	while (!quit) {
		
		frameStart = SDL_GetTicks(); //ticks desde principio sdl

		handleEvents();
		update();
		render();

		frameTime = SDL_GetTicks() - frameStart; //tiempo que a tardado el frame

		//checkear si hace falta delay
		if (FRAMEDELAY > frameTime) {
			SDL_Delay(FRAMEDELAY - frameTime);
		}
	}
}
void close() {
	destroySingletons();
	SDL_Quit();
}

void handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			quit = true;
			return;
		}
		else {
			const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
			if (currentKeyStates[SDL_SCANCODE_ESCAPE])
			{
				quit = true;
				return;
			}

			playerMovement(currentKeyStates);

			if (currentKeyStates[SDL_SCANCODE_SPACE])
			{
				player.shoot();
			}
		}
	}	
}
void playerMovement(const Uint8* currentKeyStates) {
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
}

void update() {
	player.update();
}
void render() {
	sVideoManager->renderBackground();
	player.render();
	sVideoManager->render();
}


