#include "Enemy.h"
#include "Level/MapManager.h"
#include "Define.h"
#include<time.h>
#include "Actor/EntityManager.h"
#include "Actor/Direction.h"
#include "Actor/Player.h"
#include "Engine/Engine.h"
#include "WaveManager.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::setRoad(ROAD_TYPE type)
{
	_roadType = type;
}

void Enemy::update()
{
	Entity::update();
	tryMove();
	if (_isHit)
	{
		if (_timer - _lastHitTime > _hitEffectTime)
		{
			_color = _originColor;
			GET_SINGLETON(MapManager)->getCell(_currentPos)->charColor = _color;
			_isHit = false;
		}
	}

	if (_isSlowed)
	{
		if (_timer - _lastSlowTime > _slowTime)
		{
			Engine::Get().gotoxy(0, 0);
			setMoveTime(_defaultMoveTime);
			_isSlowed = false;
		}
	}
}

void Enemy::tryMove()
{
	if (_timer - _lastMoveTime > _moveTime)
	{
		move();
		tryRotate();
		_lastMoveTime = _timer;
	}
}

void Enemy::move()
{
	if (isDead) return;
	GET_SINGLETON(MapManager)->deregisterEntityInCell(this, _currentPos);
	_currentPos += _facingDir;
	_moveCount++;
	GET_SINGLETON(MapManager)->registerEntityInCell(this, _currentPos);
	if (isOnHouse())
	{
		if (GET_SINGLETON(WaveManager)->isSpawnEnd())
		{
			if (GET_SINGLETON(EntityManager)->getEnemies().size() == 1)
			{
				GET_SINGLETON(WaveManager)->reductWave();
			}
		}
		GET_SINGLETON(Player)->modifyHP(-1);
		GET_SINGLETON(EntityManager)->despawnEntity(this);
	}
}

void Enemy::getDamage(int value)
{
	_isHit = true;
	_lastHitTime = _timer;
	_color = Color::RED;
	GET_SINGLETON(MapManager)->getCell(_currentPos)->charColor = _color;
	modifyHP(-value);
}

void Enemy::tryRotate()
{
	if (!isOnRoad(_facingDir))
	{
		for (int i = 0; i < 4; i++)
		{
			Vector2 dir = Direction::fourDirection[i];
			if (_facingDir == dir || _facingDir * -1 == dir)
				continue;
			if (isOnRoad(dir))
			{
				rotate(dir);
				break;
			}
		}
	}
}

bool Enemy::isOnRoad(Vector2 dir)
{
	return GET_SINGLETON(MapManager)->getCell(_currentPos + dir)->roadType == _roadType;
}

void Enemy::rotate(Vector2 dir)
{
	_facingDir = dir;
}

void Enemy::modifyHP(int value)
{
	_hp += value;
	if (checkDead())
	{
		dead();
	}
}

bool Enemy::checkDead()
{
	return _hp <= 0;
}

void Enemy::dead()
{
	if (isDead) return;
	isDead = true;
	GET_SINGLETON(EntityManager)->despawnEntity(this);
	GET_SINGLETON(Player)->modifyGold(_rewardGold);
}

bool Enemy::isOnHouse()
{
	return GET_SINGLETON(MapManager)->getCell(_currentPos)->type == MAP_TYPE::House;
}

void Enemy::getSlow(int value, int slowTime)
{
	_lastSlowTime = _timer;
	_slowTime = slowTime;
	_isSlowed = true;
	setMoveTime(_moveTime + value);
}

