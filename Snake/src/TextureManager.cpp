#include "TextureManager.h"
SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(RenderWindow::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);
	return tex;
}