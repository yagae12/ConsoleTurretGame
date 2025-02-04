#include "Entity.h"
#include "Level/MapManager.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::update()
{
	_timer = clock();
}

void Entity::setPos(const Vector2& pos)
{
	GET_SINGLETON(MapManager)->deregisterEntityInCell(this, _currentPos);
	_currentPos = pos;
	GET_SINGLETON(MapManager)->registerEntityInCell(this, _currentPos);
}