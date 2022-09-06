#include "RenderWindow.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* Player;

RenderWindow::RenderWindow()
{}
RenderWindow::~RenderWindow()
{}

void RenderWindow::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flag = 0;
	if (fullscreen)
	{
		flag = SDL_WINDOW_FULLSCREEN;
	}
	
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		cout << "Subsystems Initialised!..." << endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flag);
		if (window)
		{
			cout << "Window created!" << endl;
		}
		else
		{
			cout << "Window failed to init. Error: " << SDL_GetError() << endl;
		}
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			//SDL_RenderClear(renderer);
			//SDL_RenderPresent(renderer);
			cout << "renderer created!" << endl;
		}
		else
		{
			cout << "renderer failed to init. Error: " << SDL_GetError() << endl;
		}
		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
	
	//playerTex = TextureManager::LoadTexture("res/gfx/brownsnake.png", renderer);
	Player = new GameObject("res/gfx/brownsnake.png", renderer, 0 ,0);
}
void RenderWindow::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
		{
			isRunning = false;
			break;
		}
		default:
			break;
	}
}
void RenderWindow::Update()
{
	Player->Update();

}

void RenderWindow::Render()
{
	SDL_RenderClear(renderer);
	Player->Render();
	SDL_RenderPresent(renderer);
}
void RenderWindow::Clear()
{
	SDL_RenderClear(renderer);
}
void RenderWindow::CleanUp()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game Exited!" << endl;
}