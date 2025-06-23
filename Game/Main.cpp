#include <iostream>
#include "Engine/Engine.h"
#include "Game/Game.h"
#include "Level/GameLevel.h"

int main()
{
        CheckMemoryLeak();
        Game game;

        game.init();
        while (true)
        {
                game.update();
                game.Draw();
        }
}

