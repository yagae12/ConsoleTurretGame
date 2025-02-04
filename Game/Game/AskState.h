#pragma once
#include "InGameState.h"
#include "Level/GameLevel.h"
class AskState : public InGameState
{
public:
	AskState(GameLevel* inGameScene);
public:
	void update() override;
	void Draw() override;
};

