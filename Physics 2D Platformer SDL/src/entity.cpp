#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Entity.hpp"

using namespace std;

Entity::Entity(float p_x, float p_y,SDL_Texture* p_tex):x(p_x), y(p_y), tex(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 70;
	currentFrame.h = 70;

}
float Entity::getX()
{
	return x;
}
float Entity::getY()
{
	return y;
}
SDL_Texture* Entity::getTex()
{
	return tex;
}
SDL_Rect Entity::getCurrentframe()
{
	return currentFrame;
}