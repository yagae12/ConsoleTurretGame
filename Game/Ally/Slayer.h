#pragma once
#include "Ally.h"
class Slayer : public Ally
{
public:
	Slayer(ENTITY_TYPE type, std::string renderString, Color color, int attackTime, int attackRange, int damage, int price);
	~Slayer();
public:
	vector<Enemy*> defineTargets() override;
};

