#pragma once
#include "Actor/Entity.h"
#include "Define.h"
class Enemy : public Entity
{
public:
	Enemy();
	virtual ~Enemy();
public:
	bool isDead = false;
protected:
	int _hp;
	int _rewardGold;
	int _moveTime;
	int _defaultMoveTime;
	int _hitEffectTime = 200;
	int _slowTime;
	int _moveCount = 0;
	bool _isHit = false;
	bool _isSlowed = false;
	Vector2 _facingDir = Vector2(1, 0);
	ROAD_TYPE _roadType;
	clock_t _lastMoveTime = 0;
	clock_t _lastHitTime = 0;
	clock_t _lastSlowTime = 0;
public:
	void update() override;
public:
	void setRoad(ROAD_TYPE type);
	void setMoveTime(int value) { _moveTime = value; }
	int getMoveCount() { return _moveCount; }
	int getHP() { return _hp; }

	void tryMove();
	void move();
	void getDamage(int value);
	void getSlow(int value, int slowTime);
	void modifyHP(int value);
	bool checkDead();
	void tryRotate();
	bool isOnHouse();
	bool isOnRoad(Vector2 dir);
	void rotate(Vector2 dir);
	void dead();
};

