#include "BattleState.h"
#include "WaveManager.h"
#include "Actor/EntityManager.h"
#include "Level/MapManager.h"
#include "Actor/Player.h"
#include "Engine/Engine.h"


BattleState::BattleState(GameLevel* inGameScene)
{
	_inGameScene = inGameScene;

}

void BattleState::update()
{
	GET_SINGLETON(WaveManager)->spawnEnemy();

	entityUpdate();

	if (isWaveEnd())
	{
		deleteEnemyBody();
		_inGameScene->changeState(INGAMESCENE_STATE::IDLE);
	}
	if (keyController() == KEY::ESC)
	{
		if (GET_SINGLETON(WaveManager)->isSpawnEnd())
		{
			for (auto& enemy : GET_SINGLETON(EntityManager)->getEnemies())
			{
				GET_SINGLETON(EntityManager)->despawnEntity(enemy);
				GET_SINGLETON(Player)->modifyHP(-1);
			}
			GET_SINGLETON(WaveManager)->reductWave();
		}
	}
}

void BattleState::Draw()
{
	Engine::Get().gotoxy(49, 0);
	cout << " 현재 웨이브 :  " << GET_SINGLETON(WaveManager)->getCurrentWave();
	Engine::Get().gotoxy(50, 1);
	cout << "남은 적 수 : " << GET_SINGLETON(EntityManager)->getEnemies().size() << "   ";

	if (GET_SINGLETON(WaveManager)->isSpawnEnd())
	{
		Engine::Get().gotoxy(48, 2);
		cout << "ESC키를 눌러 항복";
	}

}


void BattleState::entityUpdate()
{
	for (auto& entity : GET_SINGLETON(EntityManager)->getEntities())
	{
		if (entity == nullptr)
			continue;
		entity->update();
	}
	GET_SINGLETON(EntityManager)->deleteEntity();
}

void BattleState::deleteEnemyBody()
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH - 1; x++)
		{
			Cell* cell = GET_SINGLETON(MapManager)->getCell(Vector2(x, y));
			if (cell->type == MAP_TYPE::Road)
			{
				cell->setRenderString("  ");
			}
		}
	}
}

bool BattleState::isWaveEnd()
{
	bool noEnemies = GET_SINGLETON(EntityManager)->getEnemies().empty();
	bool spawnFinished = GET_SINGLETON(WaveManager)->isSpawnEnd();

	// 디버깅 로그 추가
	std::cout << "Wave End Check: No Enemies = " << noEnemies
		<< ", Spawn Finished = " << spawnFinished << std::endl;

	return noEnemies && spawnFinished;
}
