#pragma once
#include "Entity.h"
#include "Engine/Engine.h"
#include "Define.h"
#include "Actor/Type.h"
class Cell
{
public:
	Cell();
	Cell(Color col, string str, MAP_TYPE type, ROAD_TYPE roadType) : bgColor{ col }, renderString{ str }, type{ type }, roadType{ roadType } {};
public:
	MAP_TYPE type;
	ROAD_TYPE roadType;
	Color bgColor = Color::BLACK;
	Color charColor = Color::WHITE;
	string renderString = "  ";
	vector<Entity*> entityVec;
public:
	void registerEntity(Entity* entity);
	void deregisterEntity(Entity* entity);
	void setRenderString(const string& str);
	void setBGColor(Color color);
	template<typename T>
	vector<T*> getEntities(ENTITY_TYPE type);
	vector<Entity*> getEntities() { return entityVec; }
};

template<typename T>
std::vector<T*> Cell::getEntities(ENTITY_TYPE type) {
	std::vector<T*> entities;
	for (Entity* i : entityVec) {
		if (type == i->getType()) {
			T* specificEntity = dynamic_cast<T*>(i);
			entities.push_back(specificEntity);

		}
	}
	return entities;
}