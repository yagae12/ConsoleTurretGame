#pragma once  
#include <fstream>
#include <Windows.h>
#include "Actor/Type.h"
#include "InGameState.h"
#include "Level/GameLevel.h"
#include "Key.h"

class SelectState : public InGameState
{
public:
	SelectState(GameLevel* inGameScene);
public:
	void update() override;
	void Draw() override;
private:
	void spawnAlly();
private:
	int _currentPage = 1;
	int _currentSelectIndex = 1;
};
