#pragma once

#include "Level/Scene.h"
#include <Math/Vector2.h>
#include "Game/Key.h"
#include "Actor/Type.h"
#include <map>
#include "Game/InGameState.h"

class InGameState;
class Player;
class GameLevel : public Scene
{
public:
        GameLevel();

        virtual void init() override;
        virtual void update() override;
        virtual void Draw() override;

public:
        void changeState(INGAMESCENE_STATE state);
        void mapRender();
        void uiRender();
        void entityRender(const Vector2& pos);

private:
        InGameState* _currentState;
        std::map<INGAMESCENE_STATE, InGameState*> _stateMap;

        bool isGameClear = false;
};
