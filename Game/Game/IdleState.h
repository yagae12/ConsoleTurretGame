#pragma once
#include "InGameState.h"
#include "Level/GameLevel.h"
class IdleState : public InGameState
{
public:
	IdleState(GameLevel* inGameScene);
public:
	void update() override;
	void Draw() override;
};

