#pragma once

#include "Component.h"

class PositionComponent : public Component
{
private:
	int xpos, ypos;
public:
	PositionComponent(int x, int y)
	{
		xpos = 0;
		ypos = 0;
	}
	int Getx() { return xpos; }
	int Gety() { return ypos; }
	void Setx(int x) { xpos = x; }
	void Sety(int y) { ypos = y; }
	void Init() override
	{
		xpos = 0;
		ypos = 0;
	}
	void Update() override
	{
		xpos++;
		ypos++;
	}
	void setPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
};