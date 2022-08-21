#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	RenderWindow(const char* p_title, int p_w, int p_h);
	SDL_Texture* loadTexture(const char* p_filePath);
	void Clear();
	void Render(SDL_Texture* p_tex);
	void Display();
	void CleanUp();




};