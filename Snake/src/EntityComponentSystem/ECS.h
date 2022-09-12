#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
using namespace std;

class Component;
class Entity;

using ComponentID = size_t;

inline ComponentID getComponentTypeID()
{
	static ComponentID lastID = 0;
	return lastID++;
}
template <typename T> inline ComponentID getComponentTypeID() noexcept
{
	static ComponentID typeID = getComponentTypeID();
	return typeID;
}
constexpr size_t maxComponents = 32;
using ComponentBitSet = bitset<maxComponents>;
using ComponentArray = array<Component*, maxComponents>;

class Component
{
public:
	Entity* entity;
	virtual void Init() {}
	virtual void Update(){}
	virtual void Draw(){}

	virtual ~Component() {}
	
};
class Entity
{
private:
	bool Active = true;
	vector<unique_ptr<Component>>Components;

	ComponentArray ComponentArray;
	ComponentBitSet ComponentBitSet;
public:
	void Update()
	{
		for (auto& c : Components)c->Update();
		
	}
	void Draw() 
	{
		for (auto& c : Components)c->Draw();
	}
	bool isActive() const { return Active; }
	void Destroy() { Active = false; }

	template <typename T>bool hasComponent()const
	{
		return ComponentBitSet[getComponentTypeID<T>];
	}
	template <typename T, typename...TArgs>
	T& addComponent(TArgs&&... mArgs)
	{
		T* c(new T(forward<TArgs>(mArgs)...));
		c->entity = this;
		unique_ptr<Component>uPtr{ c };
		Components.emplace_back(move(uPtr));

		ComponentArray[getComponentTypeID<T>()] = c;
		ComponentBitSet[getComponentTypeID<T>()] = true;

		c->Init();
		return *c;
	}
	template<typename T>T& getComponent()const
	{
		auto ptr(ComponentArray[getComponentTypeID<T>()]);
		return *static_cast<T*>(ptr);
	}

};

class Manager
{
private:
	vector<unique_ptr<Entity>> entities;
public:
	void Update()
	{
		for (auto& e : entities)e->Update();
	}
	void Draw()
	{
		for (auto& e : entities)e->Draw();
	}
	void Refresh()
	{
		entities.erase(remove_if(begin(entities), end(entities), [](const unique_ptr<Entity>& mEntity)
			{
				return !mEntity->isActive();
			}), 
			end(entities));
	}
	Entity& addEntity()
	{
		Entity* e = new Entity();
		unique_ptr<Entity>uPtr{ e };
		entities.emplace_back(move(uPtr));
		return *e;
	}
};