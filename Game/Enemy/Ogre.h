#pragma once
#include "Enemy.h"
class Ogre : public Enemy
{
public:
	Ogre(ENTITY_TYPE type, std::string renderString, Color color, int hp, int moveTime, int rewardGold);
};

