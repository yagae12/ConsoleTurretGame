#pragma once
#include "Ally.h"
#include"Enemy/Enemy.h"
class Enemy;
class Sword : public Ally
{
public:
	Sword(ENTITY_TYPE type, std::string renderString, Color color, int attackTime, int attackRange, int damage, int price);
	~Sword();
public:
	vector<Enemy*> defineTargets() override;
};

