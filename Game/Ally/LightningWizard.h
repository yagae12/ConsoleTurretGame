#pragma once
#include "Ally.h"
class LightningWizard : public Ally
{
public:
	LightningWizard(ENTITY_TYPE type, std::string renderString, Color color, int attackTime, int attackRange, int damage, int price);
	~LightningWizard();
public:
	vector<Enemy*> defineTargets() override;
};

 