#pragma once
#include "RenderWindow.h"
class TextureManager {
public:
	static SDL_Texture* LoadTexture(const char* fileName);
};