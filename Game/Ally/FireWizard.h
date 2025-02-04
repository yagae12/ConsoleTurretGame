#pragma once
#include "Ally.h"
class FireWizard : public Ally
{
public:
	FireWizard(ENTITY_TYPE type, std::string renderString, Color color, int attackTime, int attackRange, int damage, int price);
	~FireWizard();
public:
	vector<Enemy*> defineTargets() override;
};

