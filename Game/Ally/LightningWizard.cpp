#include "LightningWizard.h"
#include "Actor/Cell.h"
#include "Level/MapManager.h"
#include "Actor/EntityManager.h"
#include "Actor/Entity.h"
#include "Enemy/Enemy.h"

LightningWizard::LightningWizard(ENTITY_TYPE type, std::string renderString, Color color, int attackTime, int attackRange, int damage, int price)
{
	_type = type;
	_renderString = renderString;
	_color = color;
	_attackTime = attackTime;
	_attackRange = attackRange;
	_damage = damage;
	_price = price;
	_lastAttackTime = -attackTime;

}

LightningWizard::~LightningWizard()
{
}

vector<Enemy*> LightningWizard::defineTargets()
{
	vector<Enemy*> targetVec;
	vector<Enemy*> enemyVec = GET_SINGLETON(EntityManager)->getEnemies();
	if (enemyVec.size() == 0)
	{
		return targetVec;
	}
	int randIdx = rand() % enemyVec.size();
	targetVec = GET_SINGLETON(MapManager)->getCell(enemyVec[randIdx]->getPos())->getEntities<Enemy>(ENTITY_TYPE::ENEMY);
	return targetVec;
}
