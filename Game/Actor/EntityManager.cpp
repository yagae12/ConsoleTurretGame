#include "EntityManager.h"
#include "Engine/Engine.h"
#include "Level/MapManager.h"

#pragma region Enemy Includes
#include "Enemy/Enemy.h"
#include "Enemy/Goblin.h"
#include "Enemy/GoldGoblin.h"
#include "Enemy/Ogre.h"
#include "Enemy/Golem.h"
#include "Enemy/Dragon.h"
#pragma endregion

#pragma region Ally Includes
#include "Ally/Ally.h"
#include "Ally/Archer.h"
#include "Ally/Crossbow.h"
#include "Ally/Ballista.h"
#include "Ally/Gunslinger.h"
#include "Ally/FireWizard.h"
#include "Ally/IceWizard.h"
#include "Ally/LightningWizard.h"
#include "Ally/Sword.h"
#include "Ally/Spear.h"
#include "Ally/Slayer.h"
#include "Ally/Greatsword.h"
#pragma endregion

#include "Define.h"

EntityManager* EntityManager::m_pInst = nullptr;

void EntityManager::init()
{
	_allyMap.insert(std::make_pair(ALLY_TYPE::ARCHER, []() -> Ally* { return new Archer(ENTITY_TYPE::ALLY, "▶", Color::BLUE, 1000, 9, 5, 20); }));
	_allyMap.insert(std::make_pair(ALLY_TYPE::CROSSBOW, []() -> Ally* { return new Crossbow(ENTITY_TYPE::ALLY, "◁", Color::LIGHT_BLUE, 100, 9, 1, 50); }));
	_allyMap.insert(std::make_pair(ALLY_TYPE::BALLISTA, []() -> Ally* { return new Ballista(ENTITY_TYPE::ALLY, "♠", Color::MINT, 10000, 17, 200, 1000); }));
	_allyMap.insert(std::make_pair(ALLY_TYPE::GUNSLINGER, []() -> Ally* { return new Gunslinger(ENTITY_TYPE::ALLY, "♠", Color::VOILET, 1000, 11, 10, 100); }));
	_allyMap.insert(std::make_pair(ALLY_TYPE::FIRE_WIZARD, []() -> Ally* { return new FireWizard(ENTITY_TYPE::ALLY, "★", Color::RED, 3000, 11, 10, 400); }));
	_allyMap.insert(std::make_pair(ALLY_TYPE::ICE_WIZARD, []() -> Ally* { return new IceWizard(ENTITY_TYPE::ALLY, "★", Color::BLUE, 5000, 11, 5, 500); }));
	_allyMap.insert(std::make_pair(ALLY_TYPE::LIGHTNING_WIZARD, []() -> Ally* { return new LightningWizard(ENTITY_TYPE::ALLY, "★", Color::YELLOW, 1000, 0, 20, 500); }));
	_allyMap.insert(std::make_pair(ALLY_TYPE::SWORD, []() -> Ally* { return new Sword(ENTITY_TYPE::ALLY, "■", Color::GRAY, 500, 3, 5, 50); }));
	_allyMap.insert(std::make_pair(ALLY_TYPE::SPEAR, []() -> Ally* { return new Spear(ENTITY_TYPE::ALLY, "♠", Color::GRAY, 1500, 5, 7, 80); }));
	_allyMap.insert(std::make_pair(ALLY_TYPE::SLAYER, []() -> Ally* { return new Slayer(ENTITY_TYPE::ALLY, "♣", Color::RED, 3000, 3, 200, 1000); }));
	_allyMap.insert(std::make_pair(ALLY_TYPE::GREATSWORD, []() -> Ally* { return new Greatsword(ENTITY_TYPE::ALLY, "●", Color::MINT, 3000, 0, 300, 1500); }));
	_enemyMap.insert(std::make_pair(ENEMY_TYPE::GOBLIN, []() -> Enemy* { return new Goblin(ENTITY_TYPE::ENEMY, "▲", Color::GREEN, 10, 1000, 10); }));
	_enemyMap.insert(std::make_pair(ENEMY_TYPE::GOLDGOBLIN, []() -> Enemy* { return new GoldGoblin(ENTITY_TYPE::ENEMY, "▲", Color::YELLOW, 50, 5000, 100); }));
	_enemyMap.insert(std::make_pair(ENEMY_TYPE::OGRE, []() -> Enemy* { return new Ogre(ENTITY_TYPE::ENEMY, "■", Color::GREEN, 100, 500, 100); }));
	_enemyMap.insert(std::make_pair(ENEMY_TYPE::GOLEM, []() -> Enemy* { return new Golem(ENTITY_TYPE::ENEMY, "◈", Color::BLACK, 500, 100, 500); }));
	_enemyMap.insert(std::make_pair(ENEMY_TYPE::DRAGON, []() -> Enemy* { return new Dragon(ENTITY_TYPE::ENEMY, "‡", Color::RED, 1000, 1000, 1500); }));
}

Ally* EntityManager::spawnEntity(ALLY_TYPE type, const Vector2& pos)
{
	auto it = _allyMap.find(type);
	if (it != _allyMap.end())
	{
		Ally* ally = it->second(); // 함수 포인터 호출
		ally->setPos(pos);
		_allyVec.push_back(ally);
		return ally;
	}
	return nullptr;
}

Enemy* EntityManager::spawnEntity(ENEMY_TYPE type, const Vector2& pos, ROAD_TYPE road)
{
	auto it = _enemyMap.find(type);
	if (it != _enemyMap.end())
	{
		// 1. 적 객체 생성
		Enemy* enemy = it->second();

		// 2. 스폰 위치 및 도로 설정
		Vector2 spawnPos = pos;
		spawnPos = road == ROAD_TYPE::FIRST ? spawnPos : spawnPos + Vector2(0, 1);

		enemy->setPos(spawnPos);
		enemy->setRoad(road);

		// 3. 적을 맵에 등록
		GET_SINGLETON(MapManager)->registerEntityInCell(enemy, spawnPos);

		// 4. 벡터에 적 추가
		_enemyVec.push_back(enemy);
		_entityVec.push_back(enemy);

		return enemy;
	}
	return nullptr;
}

void EntityManager::despawnEntity(Ally* ally)
{
	auto it = find(_allyVec.begin(), _allyVec.end(), ally);
	if (it != _allyVec.end())
	{
		GET_SINGLETON(MapManager)->deregisterEntityInCell(ally, ally->getPos());
		_allyVec.erase(it);
		_entityVec.erase(find(_entityVec.begin(), _entityVec.end(), (Entity*)ally));
		_lazyDeleteVec.push_back(ally);
	}

}

void EntityManager::despawnEntity(Enemy* enemy)
{
	GET_SINGLETON(MapManager)->deregisterEntityInCell(enemy, enemy->getPos());
	_enemyVec.erase(find(_enemyVec.begin(), _enemyVec.end(), enemy));
	_entityVec.erase(find(_entityVec.begin(), _entityVec.end(), (Entity*)enemy));
	_lazyDeleteVec.push_back(enemy);
}

void EntityManager::deleteEntity()
{
	for (auto& entity : _lazyDeleteVec)
	{
		auto it = find(_lazyDeleteVec.begin(), _lazyDeleteVec.end(), entity);
		if (it != _lazyDeleteVec.end())
		{
			_lazyDeleteVec.erase(it);
			entity = nullptr;
			delete entity;
		}
	}
}
