#include "Enemy.h"
#include "Goblin.h"
#include "WaveManager.h"

Goblin::Goblin(ENTITY_TYPE type, std::string renderString, Color color, int hp, int moveTime, int rewardGold)
{
	_type = type;
	_renderString = renderString;
	_color = color;
	_hp = std::round((float)hp * (float)(1 + GET_SINGLETON(WaveManager)->getCurrentWave() / 7.0f));
	_moveTime = moveTime;
	_defaultMoveTime = moveTime;
	_rewardGold = rewardGold;
	_originColor = _color;

}
