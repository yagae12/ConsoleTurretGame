<<<<<<< HEAD

#include "MapManager.h"
#include <fstream>
#include <iostream>


MapManager* MapManager::m_pInst = nullptr;
void MapManager::setCell(const Cell& cell, const Vector2& pos)
{
	_arrMap[pos.y][pos.x] = cell;
}

Cell* MapManager::getCell(const Vector2& pos)
{
	return &_arrMap[pos.y][pos.x];
}

void MapManager::registerEntityInCell(Entity* entity, const Vector2& pos)
{
	_arrMap[pos.y][pos.x].registerEntity(entity);
}

void MapManager::deregisterEntityInCell(Entity* entity, const Vector2& pos)
{
	_arrMap[pos.y][pos.x].deregisterEntity(entity);
}

Vector2 MapManager::consolePosToCellPos(const Vector2& pos)
{
	Vector2 cellPos((pos.x - 30) / 2, pos.y - 6);
	return cellPos;
}

Vector2 MapManager::cellPosToConsolePos(const Vector2& pos)
{
	Vector2 consolePos(pos.x * 2 + 30, pos.y + 6);
	return consolePos;
=======
#include "MapManager.h"

void MapManager::SetCell(const Cell* cell, const Vector2& position)
{
}

Cell* MapManager::GetCell(const Vector2& position)
{
    return nullptr;
>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)
}
