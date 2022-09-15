#pragma once
#include "../RenderWindow.h"
#include "ECS.h"
#include "Component.h"

class keyboardController : public Component
{
public:
	TransformComponent* transform;
	void Init() override
	{
		transform = &entity->getComponent<TransformComponent>();
	}
	void Update() override
	{
		if (RenderWindow::event.type == SDL_KEYDOWN)
		{
			switch (RenderWindow::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.y = -1;
				break;
			case SDLK_a:
				transform->velocity.x = -1;
				break;
			case SDLK_d:
				transform->velocity.x = 1;
				break;
			case SDLK_s:
				transform->velocity.y = 1;
				break;
			default:
				break;
			}
		}
		if (RenderWindow::event.type = SDL_KEYUP)
		{
			switch (RenderWindow::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.y = 0;
				break;
			case SDLK_a:
				transform->velocity.x = 0;
				break;
			case SDLK_d:
				transform->velocity.x = 0;
				break;
			case SDLK_s:
				transform->velocity.y = 0;
				break;
			case SDLK_ESCAPE:
				RenderWindow::isRunning = false;
			default:
				break;
			}
		}
	}
};