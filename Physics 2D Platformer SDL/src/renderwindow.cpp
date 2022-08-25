#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

using namespace std;
//create Window and render func
RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h):window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title,SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
	if(window == NULL)
	{
		cout<<"Window failed to init. Error: "<<SDL_GetError()<<endl;
	}
	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
	//change Console color
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);
	if(texture == NULL)
		cout<<"Failed to load texture. Error: "<<SDL_GetError()<<endl;
	return texture;
}
void RenderWindow::Clear()
{
	SDL_RenderClear(renderer);
}
void RenderWindow::Render(Entity& p_entity)
{
	SDL_Rect src;
	src.x = p_entity.getCurrentframe().x;
	src.y = p_entity.getCurrentframe().y;
	src.w = p_entity.getCurrentframe().w;
	src.h = p_entity.getCurrentframe().h;

	SDL_Rect dst;
	dst.x = p_entity.getX()*4;
	dst.y = p_entity.getY()*4;
	dst.w = p_entity.getCurrentframe().w*4;
	dst.h = p_entity.getCurrentframe().h*4;
	
	SDL_RenderCopy(renderer, p_entity.getTex(), &src, &dst);
}
void RenderWindow::Display()
{
	SDL_RenderPresent(renderer);
}

void RenderWindow::CleanUp()
{
	SDL_DestroyWindow(window);
}