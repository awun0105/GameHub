#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <stdio.h>
#include "RenderWindow.hpp"
using namespace std;
int main(int argc, char* args[])
{
	if(SDL_Init(SDL_INIT_VIDEO)>0)
		cout<<"SDL_Init HAS FAILED. SDL_ERROR:"<<SDL_GetError()<<endl;

	if(!(IMG_Init(IMG_INIT_PNG)))
		cout<<"IMG_Init has failed. Error: "<<SDL_GetError()<<endl;
	RenderWindow window("GAME v1.0",1280,720);

	SDL_Texture* WallTexture = window.loadTexture("res/gfx/Wall.png");
	//Game Loop
	bool gameRunning = true;
	SDL_Event WindowEvent;

	while(gameRunning)
	{
		while(SDL_PollEvent(&WindowEvent))
		{
			if(WindowEvent.type == SDL_QUIT)
				gameRunning = false;
		}
		window.Clear();
		window.Render(WallTexture);
		window.Display();

	}
	window.CleanUp();
	SDL_Quit();
	return 0;
}