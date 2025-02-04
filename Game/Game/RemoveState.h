#pragma once
#include "InGameState.h"
#include "Level/GameLevel.h"
class RemoveState : public InGameState
{
public:
	RemoveState(GameLevel* inGameScene);
public:
	void update() override;
	void Draw() override;
private:
	bool isInMap(const Vector2& pos);
	bool isCellEmpty();
private:
	Vector2 _currentMousePos;
};

