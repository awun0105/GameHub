#pragma once

#include "Component.h"
#include "SDL.h"
//draw itself on screen
class SpriteComponent :public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
public:
	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		setTex(path);
	}
	void setTex(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}
	void Init() override
	{
		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = srcRect.h = 64;
		destRect.w = destRect.h = 64;
	}
	void Update()override
	{
		destRect.x = (int)transform->position.x;
		destRect.y = (int)transform->position.y;

	}
	void Draw()override
	{
		TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
	}

};