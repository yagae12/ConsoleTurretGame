#pragma once
#include "Ally.h"
class Greatsword : public Ally
{
public:
	Greatsword(ENTITY_TYPE type, std::string renderString, Color color, int attackTime, int attackRange, int damage, int price);
	~Greatsword();
public:
	vector<Enemy*> defineTargets() override;
};

