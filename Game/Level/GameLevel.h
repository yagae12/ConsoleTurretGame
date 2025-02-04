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
// ¼ÒÄÚ¹Ý °ÔÀÓ ·¹º§.
class DrawableActor;
class Player;
class Road;
class House;
class GameLevel : public Level
>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)
{
public:
	GameLevel();

	// ¾÷µ¥ÀÌÆ® ÇÔ¼ö.

	virtual void init() override;
	virtual void update() override;

	// ·¹º§ÀÇ ±×¸®±â ÇÔ¼ö.
	virtual void Draw() override;

	// ÇÃ·¹ÀÌ¾î°¡ ÀÌµ¿ÀÌ °¡´ÉÇÑ Áö È®ÀÎÇÏ´Â ÇÔ¼ö.
<<<<<<< HEAD
public:
	
	void changeState(INGAMESCENE_STATE state);
	void mapRender();
	void uiRender();
	void entityRender(const Vector2& pos);
=======
	bool CanPlayerMove(const Vector2& position);

>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)


private:
<<<<<<< HEAD


private:

	InGameState* _currentState;
	std::map<INGAMESCENE_STATE, InGameState*> _stateMap;
=======
	// º®/¶¥ ¾×ÅÍ ¹è¿­.
	List<DrawableActor*> map;

	// ¹Ú½º ¾×ÅÍ.
	List<Road*> boxes;

	// Å¸°Ù ¾×ÅÍ.
	List<House*> targets;

	// ÇÃ·¹ÀÌ¾î ¾×ÅÍ.
	Player* player = nullptr;
>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)

	// °ÔÀÓ Å¬¸®¾î º¯¼ö.
	bool isGameClear = false;
};