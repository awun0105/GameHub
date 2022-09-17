#pragma once

#include "Component.h"
#include "SDL.h"
#include "../TextureManager.h"
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
	~SpriteComponent()
	{
		SDL_DestroyTexture(texture);
	}
	void setTex(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}
	void Init() override
	{
		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;
		
	}
	void Update()override
	{
		destRect.x = static_cast<int>(transform->position.x);
		destRect.y = static_cast<int>(transform->position.y);
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;
	}
	void Draw()override
	{
		TextureManager::Draw(texture, srcRect, destRect, spriteFlip);
	}

};