#pragma once
#include "InGameState.h"
#include "Math/Vector2.h"
#include "Level/GameLevel.h"
class PlaceState : public InGameState
{
public:
	PlaceState(GameLevel* gamelevel);
public:
	void update() override;
	void Draw() override;
private :
	bool isInMap(const Vector2& pos);
	bool isCellEmpty();
private:
	Vector2 _currentMousePos;
};

