#pragma once
#include "RenderWindow.h"

class Map
{
private:
	SDL_Rect src, dest;
	//SDL_Texture

public:
	Map();
	~Map();

	void LoadMap();
	void DrawMap();


};