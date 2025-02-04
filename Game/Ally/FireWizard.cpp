#include "FireWizard.h"
#include "Actor/Cell.h"
#include "Level/MapManager.h"
#include "Actor/Direction.h"

FireWizard::FireWizard(ENTITY_TYPE type, std::string renderString, Color color, int attackTime, int attackRange, int damage, int price)
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

FireWizard::~FireWizard()
{
}

vector<Enemy*> FireWizard::defineTargets()
{
	vector<Enemy*> targetVec;
	int x = _currentPos.x - _attackRange / 2;
	int y = _currentPos.y - _attackRange / 2;
	int maxCount = 0;
	Vector2 attackCellPos = Vector2();
	for (int i = y; i < y + _attackRange; i++)
	{
		for (int j = x; j < x + _attackRange; j++)
		{
			Vector2 pos = Vector2(j, i);
			if (pos.x < 0 || pos.y < 0) continue;
			Cell* cell = GET_SINGLETON(MapManager)->getCell(pos);
			if (cell->type == MAP_TYPE::Road)
			{
				vector<Enemy*> vec = cell->getEntities<Enemy>(ENTITY_TYPE::ENEMY);
				if (vec.size() == 0) continue;
				if (maxCount <= vec.front()->getMoveCount())
				{
					attackCellPos = pos;
				}
			}
		}
	}
	vector<Enemy*> enemyVec;
	for (int i = 0; i < 9; i++)
	{
		Vector2 pos = attackCellPos + Direction::nineDirection[i];
		if (GET_SINGLETON(MapManager)->getCell(pos)->type != MAP_TYPE::Road) continue;
		enemyVec = GET_SINGLETON(MapManager)->getCell(pos)->getEntities<Enemy>(ENTITY_TYPE::ENEMY);
		for (int j = 0; j < enemyVec.size(); j++)
		{
			targetVec.push_back(enemyVec[j]);
		}
	}
	return targetVec;
}
