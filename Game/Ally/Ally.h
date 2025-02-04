#pragma once

#include "Actor/Entity.h"
#include "Enemy/Enemy.h"
#include "Define.h"
class Enemy;
class Ally : public Entity
{
public:
	Ally();
	virtual ~Ally();
protected:
	int _attackTime = 500;
	int _attackRange = 5;
	int _damage = 5;
	int _price = 20;
	clock_t _lastAttackTime = 0;
public:
	void resetAttackCooltime() { _lastAttackTime = -_attackTime; }
	int getPrice() { return _price; }
	int getAttackRange() { return _attackRange; }
	void update() override;
	virtual void attack();
	virtual vector<Enemy*> defineTargets() ;
};