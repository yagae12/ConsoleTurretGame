#pragma once
#include "Enemy/Enemy.h"
class Goblin : public Enemy
{
public:
	Goblin(ENTITY_TYPE type, std::string renderString, Color color, int hp, int moveTime, int rewardGold);
};