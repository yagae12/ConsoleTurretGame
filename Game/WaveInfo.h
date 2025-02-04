#pragma once
#include "Define.h"
#include "Actor/Type.h"
#include <map>

struct WaveInfo
{
	WaveInfo() : spawnDelay(0) {}

	// 초기화 리스트를 지원하는 생성자 추가
	WaveInfo(std::initializer_list<std::pair<const ENEMY_TYPE, int>> enemyMap, int delay)
		: spawnEnemyMap(enemyMap), spawnDelay(delay) {
	}

	std::map<ENEMY_TYPE, int> spawnEnemyMap; // 적 타입과 수량
	int spawnDelay;                          // 스폰 간격(ms)
};
