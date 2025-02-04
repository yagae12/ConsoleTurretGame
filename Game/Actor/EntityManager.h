#pragma once

#include "Define.h"
#include "Actor/Entity.h"
#include "Enemy/Enemy.h"
#include <map>
#include "Ally/Ally.h"
#include "Math/Vector2.h"
#include "RTTI.h"
class Enemy;
class EntityManager
{
	DECLARE_SINGLETON(EntityManager)
public:
	void init();
public:
	Ally* spawnEntity(ALLY_TYPE type, const Vector2& pos);
	Enemy* spawnEntity(ENEMY_TYPE type, const Vector2& pos, ROAD_TYPE road);
	void despawnEntity(Ally* ally);
	void despawnEntity(Enemy* enemy);
	void deleteEntity();
	vector<Entity*> getEntities() { return _entityVec; }
	vector<Enemy*> getEnemies() { return _enemyVec; }
	vector<Ally*> getAllies() { return _allyVec; }
private:
	map<ALLY_TYPE, Ally* (*)()> _allyMap;
	map<ENEMY_TYPE, Enemy* (*)()> _enemyMap;
	vector<Entity*> _lazyDeleteVec;
	vector<Entity*> _entityVec;
	vector<Enemy*> _enemyVec;
	vector<Ally*> _allyVec;
};
