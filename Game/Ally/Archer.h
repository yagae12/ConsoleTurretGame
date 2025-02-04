#pragma once

#include "Ally/Ally.h"
#include "Enemy/Enemy.h"
class Enemy;
class Archer : public Ally
{
public:
	Archer(ENTITY_TYPE type, std::string renderString, Color color, int attackTime, int attackRange, int damage, int price);
	~Archer();
public:
	vector<Enemy*> defineTargets() override;
};