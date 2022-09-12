#pragma once

#include "Component.h"
#include "SDL.h"
//draw itself on screen
class SpriteComponent :public Component
{
private:
	PositionComponent* position;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
public:
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}
	void Init() override
	{
		position = &entity->getComponent<PositionComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 32;
		destRect.w = destRect.h = 64;
	}
	void Update()override
	{
		destRect.x = position->Getx();
		destRect.y = position->Gety();

	}
	void Draw()override
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}

};