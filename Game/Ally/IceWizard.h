#pragma once
#include "Ally.h"
class IceWizard : public Ally
{
public:
	IceWizard(ENTITY_TYPE type, std::string renderString, Color color, int attackTime, int attackRange, int damage, int price);
	~IceWizard();
public:
	vector<Enemy*> defineTargets() override;
};

