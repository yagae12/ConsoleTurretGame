#pragma once
#include "Ally.h"
class Crossbow : public Ally
{
public:
	Crossbow(ENTITY_TYPE type, std::string renderString, Color color, int attackTime, int attackRange, int damage, int price);
	~Crossbow();
public:
	vector<Enemy*> defineTargets() override;
};

