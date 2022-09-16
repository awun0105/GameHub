#pragma once
#include "../RenderWindow.h"
#include "ECS.h"
#include "Component.h"

class keyboardController : public Component
{
public:
	TransformComponent* transform;
	//SpriteComponent* sprite;
	void Init() override
	{
		transform = &entity->getComponent<TransformComponent>();
		//sprite = &entity->getComponent<SpriteComponent>();
	}
	void Update() override
	{
		switch (RenderWindow::event.type)
		{
		case SDL_KEYDOWN:
			switch (RenderWindow::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.y = -1;
				cout << "Key W down" << endl;
				break;
			case SDLK_a:
				transform->velocity.x = -1;
				cout << "Key A down" << endl;
				break;
			case SDLK_d:
				transform->velocity.x = 1;
				cout << "Key D down" << endl;
				break;
			case SDLK_s:
				transform->velocity.y = 1;
				cout << "Key S down" << endl;
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			switch (RenderWindow::event.key.keysym.sym)
			{
			case SDLK_w:
				transform->velocity.y = 0;
				cout << "Key W up" << endl;
				break;
			case SDLK_a:
				transform->velocity.x = 0;
				cout << "Key A up" << endl;
				break;
			case SDLK_d:
				transform->velocity.x = 0;
				cout << "Key D up" << endl;
				break;
			case SDLK_s:
				transform->velocity.y = 0;
				cout << "Key S up" << endl;
				break;
			case SDLK_ESCAPE:
				RenderWindow::isRunning = false;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
};