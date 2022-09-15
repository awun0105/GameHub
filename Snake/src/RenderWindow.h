#pragma once
#ifndef RenderWindow_h
#define RenderWindow_h

#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>
#include <iostream>

using namespace std;

class RenderWindow
{
private:
	int cnt = 0;
	SDL_Window* window;
	
public:
	RenderWindow();
	~RenderWindow();
	void Init(const char* title, int xpos,int ypos, int width, int height, bool fullscreen);
	//SDL_Texture* loadTexture(const char* p_filePath);
	void handleEvents();
	void Update();
	bool running() { return isRunning; }
	void Clear();
	void Render();
	void CleanUp();

	static bool isRunning;
	static SDL_Renderer* renderer;
	static SDL_Event event;

};
#endif