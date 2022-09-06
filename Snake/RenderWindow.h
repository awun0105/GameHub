#pragma once
#ifndef RenderWindow_h
#define RenderWindow_h

#include <stdio.h>
#include <iostream>

#include "SDL.h"
#include "SDL_image.h"

using namespace std;

class RenderWindow
{
private:
	int cnt;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	RenderWindow();
	~RenderWindow();
	void Init(const char* title, int xpos,int ypos, int width, int height, bool fullscreen);
	//SDL_Texture* loadTexture(const char* p_filePath);
	void handleEvents();
	void Update();
	void Clear();
	void Render();
	//void Display();
	void CleanUp();

	bool running() { return isRunning; }


};
#endif