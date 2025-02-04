#pragma once
#include "Define.h"
#include "Actor/Type.h"
#include <map>

struct WaveInfo
{
	WaveInfo() : spawnDelay(0) {}

	// �ʱ�ȭ ����Ʈ�� �����ϴ� ������ �߰�
	WaveInfo(std::initializer_list<std::pair<const ENEMY_TYPE, int>> enemyMap, int delay)
		: spawnEnemyMap(enemyMap), spawnDelay(delay) {
	}

	std::map<ENEMY_TYPE, int> spawnEnemyMap; // �� Ÿ�԰� ����
	int spawnDelay;                          // ���� ����(ms)
};
