#include "Game.h"
#include "Ship.h"

SDL_Renderer* Game::renderer = nullptr;

Ship player;
void playerMovement(const Uint8* currentKeyStates);

Game::Game() {}
Game::~Game() {}

void Game::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("SDLTest", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	renderer = SDL_CreateRenderer(window, -1, 0);
	isRunning = true;

	player = Ship();
}

void Game::handleEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event) != 0) {
		if (event.type == SDL_QUIT) {
			isRunning = false;
			return;
		}
		else {
			const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
			if (currentKeyStates[SDL_SCANCODE_ESCAPE])
			{
				isRunning = false;
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

void Game::update()
{
	player.update();
}

void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);

	player.render();
	SDL_RenderPresent(renderer);
}

void Game::close()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
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

