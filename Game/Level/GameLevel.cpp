#include "GameLevel.h"
#include "Engine/Engine.h"
#include "Define.h"
#include "Engine/Timer.h"
#include <fstream>
#include "Actor/EntityManager.h"
#include "Actor/Type.h"
#include "MapManager.h"
#include "Actor/Player.h"
#include <Windows.h>
#include "Actor/Cell.h"
#include "WaveManager.h"
#include "Game/IdleState.h"
#include "Game/InGameState.h"
#include "Game/PlaceState.h"
#include "Game/SelectState.h"
#include "Game/RemoveState.h"
#include "Game/BattleState.h"
#include "Game/AskState.h"

GameLevel::GameLevel()
{
}

void GameLevel::init()
{
        Engine::Get().SetCursorType(CursorType::NoCursor);

        std::fstream mapRead("../Assets/Maps/Map1.txt");
        if (mapRead.is_open())
        {
                for (int i = 0; i < MAP_HEIGHT - 1; i++)
                {
                        for (int j = 0; j < MAP_WIDTH; j++)
                        {
                                char read = mapRead.get();

                                if (read == '0')
                                {
                                        GET_SINGLETON(MapManager)->setCell(Cell{ Color::GRAY, "  ", MAP_TYPE::Wall, ROAD_TYPE::NONE }, Vector2(j, i));
                                }
                                else if (read == '1')
                                {
                                        GET_SINGLETON(MapManager)->setCell(Cell{ Color::LIGHT_GRAY, "  ", MAP_TYPE::Road, ROAD_TYPE::FIRST }, Vector2(j, i));
                                }
                                else if (read == '2')
                                {
                                        GET_SINGLETON(MapManager)->setCell(Cell{ Color::WHITE, "  ", MAP_TYPE::Place, ROAD_TYPE::NONE }, Vector2(j, i));
                                }
                                else if (read == '3')
                                {
                                        GET_SINGLETON(MapManager)->setCell(Cell{ Color::LIGHT_GRAY, "  ", MAP_TYPE::Road, ROAD_TYPE::SECOND }, Vector2(j, i));
                                }
                                else if (read == '4')
                                {
                                        GET_SINGLETON(MapManager)->setCell(Cell{ Color::YELLOW, "  ", MAP_TYPE::House, ROAD_TYPE::NONE }, Vector2(j, i));
                                }

                                if (mapRead.fail())
                                {
                                        cout << "File read error.";
                                        break;
                                }
                        }
                }
        }
        mapRead.close();
        _stateMap.insert(std::make_pair(INGAMESCENE_STATE::IDLE, new IdleState(this)));
        _stateMap.insert(std::make_pair(INGAMESCENE_STATE::SELECT, new SelectState(this)));
        _stateMap.insert(std::make_pair(INGAMESCENE_STATE::REMOVE, new RemoveState(this)));
        _stateMap.insert(std::make_pair(INGAMESCENE_STATE::PLACE, new PlaceState(this)));
        _stateMap.insert(std::make_pair(INGAMESCENE_STATE::BATTLE, new BattleState(this)));
        _stateMap.insert(std::make_pair(INGAMESCENE_STATE::ASK, new AskState(this)));

        changeState(INGAMESCENE_STATE::IDLE);
}

void GameLevel::update()
{
        _currentState->update();
}

void GameLevel::Draw()
{
        mapRender();
        uiRender();
        _currentState->Draw();
}

void GameLevel::changeState(INGAMESCENE_STATE state)
{
        system("cls");
        _currentState = _stateMap[state];
}

void GameLevel::mapRender()
{
        Engine::Get().gotoxy(30, 6);
        for (int i = 0; i < MAP_HEIGHT; i++)
        {
                for (int j = 0; j < MAP_WIDTH; j++)
                {
                        Vector2 pos = Vector2(j, i);
                        Cell* cell = GET_SINGLETON(MapManager)->getCell(pos);
                        Engine::Get().setColor((int)cell->charColor, (int)cell->bgColor);
                        entityRender(pos);
                }
        }
        Engine::Get().setColor((int)Color::WHITE, (int)Color::BLACK);
}

void GameLevel::entityRender(const Vector2& pos)
{
        cout << GET_SINGLETON(MapManager)->getCell(pos)->renderString;
}

void GameLevel::uiRender()
{
        Engine::Get().gotoxy(1, 1);
        cout << "HP : ";
        for (int i = 0; i < GET_SINGLETON(Player)->getHP(); i++)
        {
                cout << "*";
        }
        cout << "   ";

        Engine::Get().gotoxy(1, 2);
        cout << "Gold : " << GET_SINGLETON(Player)->getGold();
}
