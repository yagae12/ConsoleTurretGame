#include <iostream>
#include "Engine/Engine.h"
#include "Game/Game.h"
#include "Level/GameLevel.h"

int main()
{
<<<<<<< HEAD
	Game game ;
=======
	// ¸Þ¸ð¸® ´©¼ö È®ÀÎ.
	CheckMemoryLeak();
>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)

	game.init();
	while (true)
	{
		game.update();
		game.Draw();
	}
}