#pragma once

#include "Component.h"
#include "../Vector2D.h"

class TransformComponent : public Component
{
public:
	Vector2D position;
	Vector2D velocity;
	int speed = 3;

	int height = 64;
	int width = 64;
	int scale = 1;


	TransformComponent()
	{
		position.x = 0.0f;
		position.y = 0.0f;
	}
	TransformComponent(float x, float y)
	{
		position.x = x;
		position.y = y;
	}
	TransformComponent(int scle)
	{
		position.x = 0.0f;
		position.y = 0.0f;
		scale = scle;
	}
	TransformComponent(float x, float y, int h, int w, int scle)
	{
		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = scle;
	}
	void Init()override
	{
		velocity.x = 0;
		velocity.y = 0;
	}
	void Update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
	
};