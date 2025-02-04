#pragma once
#include "InGameState.h"
#include "Level/GameLevel.h"
class BattleState : public InGameState
{
public:
	BattleState(GameLevel* inGameScene);
public:
	void update() override;
	void Draw() override;
private:
	void entityUpdate();
	void deleteEnemyBody();
	bool isWaveEnd();
};

