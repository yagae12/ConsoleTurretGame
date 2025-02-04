#pragma once
#include "Level/GameLevel.h"

class GameLevel;
class InGameState
{
public:
	virtual ~InGameState() {}
	virtual void update() ;
	virtual void Draw() ;
protected:
	virtual KEY keyController();
protected:
	GameLevel* _inGameScene;
};