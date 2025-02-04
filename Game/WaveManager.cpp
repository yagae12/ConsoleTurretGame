#include "WaveManager.h"
#include "Define.h"
#include "WaveInfo.h"
#include<fstream>
#include "Actor/EntityManager.h"
#include<sstream>
#include "Level/SceneManager.h"
#include <vector>

WaveManager* WaveManager::m_pInst = nullptr;

void WaveManager::init()
{
// 	std::fstream waveRead("../Assets/Wave/WaveInfo.txt");
// 	if (waveRead.is_open())
// 	{
// 		for (int i = 0; i < 50; i++)
// 		{
// 			WaveInfo info = WaveInfo();
// 			string waveStr;
// 			std::getline(waveRead, waveStr);
// 
// 			std::istringstream iss(waveStr);
// 
// 			string buffer;
// 			vector<string> result;
// 			ENEMY_TYPE type = ENEMY_TYPE::GOBLIN;
// 			while (iss >> buffer)
// 			{
// 				if (type == ENEMY_TYPE::END)
// 				{
// 					info.spawnDelay = std::stoi(buffer);
// 					
// 					continue;
// 				}
// 				info.spawnEnemyMap.insert(std::make_pair(type, std::stoi(buffer)));
// 				type = (ENEMY_TYPE)((int)type + 1);
// 			}
// 			_waveInfoVec.push_back(info);
// 		}
// 	}
// 	waveRead.close();
 // WaveInfo 벡터 초기화
// 	_waveInfoVec.clear();

	// 하드코딩된 웨이브 정보 추가
	_waveInfoVec.push_back(WaveInfo({ { ENEMY_TYPE::GOBLIN, 5 } }, 100));
	_waveInfoVec.push_back(WaveInfo({ { ENEMY_TYPE::GOBLIN, 8 }, { ENEMY_TYPE::GOLDGOBLIN, 2 } }, 800));
	_waveInfoVec.push_back(WaveInfo({ { ENEMY_TYPE::GOBLIN, 10 }, { ENEMY_TYPE::GOLDGOBLIN, 4 } }, 600));
	_waveInfoVec.push_back(WaveInfo({ { ENEMY_TYPE::GOBLIN, 10 }, { ENEMY_TYPE::GOLDGOBLIN, 5 }, { ENEMY_TYPE::OGRE, 1 } }, 600));
	_waveInfoVec.push_back(WaveInfo({ { ENEMY_TYPE::GOBLIN, 15 }, { ENEMY_TYPE::GOLDGOBLIN, 8 }, { ENEMY_TYPE::OGRE, 2 } }, 500));
	_waveInfoVec.push_back(WaveInfo({ { ENEMY_TYPE::GOBLIN, 20 }, { ENEMY_TYPE::GOLDGOBLIN, 10 }, { ENEMY_TYPE::OGRE, 3 }, { ENEMY_TYPE::GOLEM, 1 } }, 400));
	_waveInfoVec.push_back(WaveInfo({ { ENEMY_TYPE::GOBLIN, 30 }, { ENEMY_TYPE::GOLDGOBLIN, 15 }, { ENEMY_TYPE::OGRE, 5 }, { ENEMY_TYPE::GOLEM, 2 } }, 300));
	_waveInfoVec.push_back(WaveInfo({ { ENEMY_TYPE::GOBLIN, 40 }, { ENEMY_TYPE::GOLDGOBLIN, 20 }, { ENEMY_TYPE::OGRE, 10 }, { ENEMY_TYPE::GOLEM, 3 }, { ENEMY_TYPE::DRAGON, 1 } }, 200));
	_waveInfoVec.push_back(WaveInfo({ { ENEMY_TYPE::GOBLIN, 50 }, { ENEMY_TYPE::GOLDGOBLIN, 30 }, { ENEMY_TYPE::OGRE, 15 }, { ENEMY_TYPE::GOLEM, 5 }, { ENEMY_TYPE::DRAGON, 2 } }, 150));

	// 디버깅용 출력

	// 초기 값 설정
	_currentWave = 0;
	_currentSpawnEnemy = ENEMY_TYPE::GOBLIN;
	_leftSpawnEnemy = _waveInfoVec[_currentWave].spawnEnemyMap[_currentSpawnEnemy];
	_lastSpawnTime = clock();
}

void WaveManager::nextWave()
{
	_currentWave++;
	if (_currentWave >= _waveInfoVec.size()) // 벡터 크기 확인
	{
		if (_waveInfoVec.empty())
		{
			std::cerr << "WaveInfoVec is empty! Initialization failed." << std::endl;
			std::cout << "Initialized Waves: " << _waveInfoVec.size() << " waves loaded." << std::endl;
			std::cin.get();
		}

// 		std::cout << "Current Wave: " << _currentWave << std::endl;
// 		std::cin.get();
// 		Sleep(1000000);

		GET_SINGLETON(SceneManager)->loadScene("TitleScene");
		return;
	}
	// 기존 로직 유지
	for (auto& ally : GET_SINGLETON(EntityManager)->getAllies())
	{
		ally->resetAttackCooltime();
	}
	_currentSpawnEnemy = ENEMY_TYPE::GOBLIN;
	_leftSpawnEnemy = _waveInfoVec[_currentWave].spawnEnemyMap[_currentSpawnEnemy];
}

void WaveManager::spawnEnemy()
{
	if (_currentSpawnEnemy >= ENEMY_TYPE::END) return;

	_spawnTimer = clock();
	if (_lastSpawnTime + _waveInfoVec[_currentWave].spawnDelay < _spawnTimer)
	{
		_spawnRoad = (_spawnRoad == ROAD_TYPE::FIRST) ? ROAD_TYPE::SECOND : ROAD_TYPE::FIRST;
		_lastSpawnTime = _spawnTimer;
		_leftSpawnEnemy--;

		if (_leftSpawnEnemy > 0)
		{
			GET_SINGLETON(EntityManager)->spawnEntity(_currentSpawnEnemy, ENEMY_SPAWNPOS, _spawnRoad);
		}

		if (_leftSpawnEnemy <= 0)
		{
			_currentSpawnEnemy = static_cast<ENEMY_TYPE>(static_cast<int>(_currentSpawnEnemy) + 1);
			if (_currentSpawnEnemy >= ENEMY_TYPE::END) return;

			if (_waveInfoVec[_currentWave].spawnEnemyMap.find(_currentSpawnEnemy) !=
				_waveInfoVec[_currentWave].spawnEnemyMap.end())
			{
				_leftSpawnEnemy = _waveInfoVec[_currentWave].spawnEnemyMap[_currentSpawnEnemy];
			}
		}
	}
}
