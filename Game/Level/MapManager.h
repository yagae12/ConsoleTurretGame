#pragma once
#include "Actor/Cell.h"
#include "Define.h"
#include <vector>

class MapManager
{
        DECLARE_SINGLETON(MapManager)
public:
        void setCell(const Cell& cell, const Vector2& pos);
        Cell* getCell(const Vector2& pos);
        void registerEntityInCell(Entity* entity, const Vector2& pos);
        void deregisterEntityInCell(Entity* entity, const Vector2& pos);
        Vector2 consolePosToCellPos(const Vector2& pos);
        Vector2 cellPosToConsolePos(const Vector2& pos);
private:
        Cell _arrMap[MAP_HEIGHT][MAP_WIDTH];
};
