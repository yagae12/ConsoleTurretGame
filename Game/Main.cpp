#include <iostream>
#include "Engine/Engine.h"
#include "Game/Game.h"
#include "Level/GameLevel.h"

int main()
{
<<<<<<< HEAD
	Game game ;
=======
	// �޸� ���� Ȯ��.
	CheckMemoryLeak();
>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)

	game.init();
	while (true)
	{
		game.update();
		game.Draw();
	}
}