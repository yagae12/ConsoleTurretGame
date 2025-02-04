#include "Sword.h"
#include "Actor/Cell.h"
#include "Level/MapManager.h"

Sword::Sword(ENTITY_TYPE type, std::string renderString, Color color, int attackTime, int attackRange, int damage, int price)
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

Sword::~Sword()
{
}

vector<Enemy*> Sword::defineTargets()
{
	vector<Enemy*> targetVec;
	Enemy* target = nullptr;
	int x = _currentPos.x - _attackRange / 2;
	int y = _currentPos.y - _attackRange / 2;
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
				if (vec.size() > 0)
				{
					if (target == nullptr)
					{
						target = vec.front();
						continue;
					}
					else
					{
						if (target->getMoveCount() < vec.front()->getMoveCount())
						{
							target = vec.front();
						}
					}
				}
			}
		}
	}
	if (target != nullptr)
		targetVec = GET_SINGLETON(MapManager)->getCell(target->getPos())->getEntities<Enemy>(ENTITY_TYPE::ENEMY);
	return targetVec;

}
