#pragma once
#include "Ally.h"
class Ballista : public Ally
{
public:
	Ballista(ENTITY_TYPE type, std::string renderString, Color color, int attackTime, int attackRange, int damage, int price);
	~Ballista();
public:
	vector<Enemy*> defineTargets() override;
};