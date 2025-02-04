#pragma once
<<<<<<< HEAD
#include "Actor/Cell.h"
#include "Define.h"
#include <vector>
=======
#include "Define.h"
#include "Level/Cell.h"
#include "Math/Vector2.h"
>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)

class MapManager
{
	DECLARE_SINGLETON(MapManager)
public:
<<<<<<< HEAD
	void setCell(const Cell& cell, const Vector2& pos);
	Cell* getCell(const Vector2& pos);
	void registerEntityInCell(Entity* entity, const Vector2& pos);
	void deregisterEntityInCell(Entity* entity, const Vector2& pos);
	Vector2 consolePosToCellPos(const Vector2& pos);
	Vector2 cellPosToConsolePos(const Vector2& pos);
private:
	Cell _arrMap[MAP_HEIGHT][MAP_WIDTH];
=======
	void SetCell(const Cell* cell, const Vector2& position);
	Cell* GetCell(const Vector2& position); 

>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)
};