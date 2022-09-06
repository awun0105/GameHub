#include "SDL.h"
//#include "SDL_image.h"
#include <iostream>
#include <stdio.h>
#include <vector>

#include "RenderWindow.h"
//#include "Entity.h"

using namespace std;

RenderWindow* Window = nullptr;
int main(int argc, char* argv[])
{
	//Ctrl + shift + /
	/*SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400,SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);*/
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	Window = new RenderWindow();
	Window->Init("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (Window->running())
	{
		frameStart = SDL_GetTicks();

		Window->handleEvents();
		Window->Update();
		Window->Render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	Window->CleanUp();
	return 0;
}