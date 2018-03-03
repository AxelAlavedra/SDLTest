#pragma once
#include "../SDL/include/SDL.h"
#include "../SDL/include/SDL_timer.h"
#pragma comment(lib,"../SDL/lib/x86/SDL2.lib")
#pragma comment(lib,"../SDL/lib/x86/SDL2main.lib")

#define WIDTH 640
#define HEIGHT 480
#define FRAMES_PER_SECOND 30
#define FRAMEDELAY 1000 / FRAMES_PER_SECOND //tiempo que tardara un frame

#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

#define IDLE 0
#define MOVING 1