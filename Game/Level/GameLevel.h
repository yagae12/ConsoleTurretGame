#pragma once

#include "Level/Scene.h"
#include <Math/Vector2.h>
#include "Game/Key.h"
#include "Actor/Type.h"
#include  <map>
#include "Game/InGameState.h"

<<<<<<< HEAD
class InGameState;
class Player;
class GameLevel : public Scene
=======
// ���ڹ� ���� ����.
class DrawableActor;
class Player;
class Road;
class House;
class GameLevel : public Level
>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)
{
public:
	GameLevel();

	// ������Ʈ �Լ�.

	virtual void init() override;
	virtual void update() override;

	// ������ �׸��� �Լ�.
	virtual void Draw() override;

	// �÷��̾ �̵��� ������ �� Ȯ���ϴ� �Լ�.
<<<<<<< HEAD
public:
	
	void changeState(INGAMESCENE_STATE state);
	void mapRender();
	void uiRender();
	void entityRender(const Vector2& pos);
=======
	bool CanPlayerMove(const Vector2& position);

>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)


private:
<<<<<<< HEAD


private:

	InGameState* _currentState;
	std::map<INGAMESCENE_STATE, InGameState*> _stateMap;
=======
	// ��/�� ���� �迭.
	List<DrawableActor*> map;

	// �ڽ� ����.
	List<Road*> boxes;

	// Ÿ�� ����.
	List<House*> targets;

	// �÷��̾� ����.
	Player* player = nullptr;
>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)

	// ���� Ŭ���� ����.
	bool isGameClear = false;
};