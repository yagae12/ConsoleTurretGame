#pragma once
#include "Ally.h"
class Gunslinger : public Ally
{
public:
	Gunslinger(ENTITY_TYPE type, std::string renderString, Color color, int attackTime, int attackRange, int damage, int price);
	~Gunslinger();
public:
	vector<Enemy*> defineTargets() override;
};

