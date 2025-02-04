#include "PlaceState.h"
#include "Math/Vector2.h"
#include<Windows.h>
#include "Level/MapManager.h"
#include "Define.h"
#include "Actor/Player.h"
#include "Actor/EntityManager.h"
#include "Engine/Engine.h"



PlaceState::PlaceState(GameLevel* gamelevel)
{
	_inGameScene = gamelevel;

}

void PlaceState::update()
{
	_currentMousePos = GET_SINGLETON(MapManager)->consolePosToCellPos(Engine::Get().getMousePos());

	if (Engine::Get().getMouseInput())
	{
		Cell* cell = GET_SINGLETON(MapManager)->getCell(_currentMousePos);
		bool isValid = isInMap(_currentMousePos) && isCellEmpty() && cell->type == MAP_TYPE::Place;
		if (isValid)
		{
			GET_SINGLETON(Player)->getAlly()->setPos(_currentMousePos);
			_inGameScene->changeState(INGAMESCENE_STATE::IDLE);
		}
	}

	if (keyController() == KEY::ESC)
	{
		Ally* ally = GET_SINGLETON(Player)->getAlly();
		GET_SINGLETON(Player)->modifyGold(ally->getPrice(), false);
		GET_SINGLETON(EntityManager)->despawnEntity(ally);
		_inGameScene->changeState(INGAMESCENE_STATE::SELECT);
	}
}

void PlaceState::Draw()
{
	Engine::Get().gotoxy(40, 0);
	cout << "원하는 곳에 마우스를 클릭하여 아군을 배치하세요.";
	Engine::Get().gotoxy(43, 1);
	cout << "설치 가능한 위치에서 ★로 표시됩니다.";
	Engine::Get().gotoxy(50, 2);
	cout << "ESC키를 눌러 취소";

	// 디버깅: 현재 마우스 좌표 출력
// 	std::cout << "Mouse Console Pos: " << Engine::Get().getMousePos() << std::endl;
// 	std::cout << "Mouse Cell Pos: " << _currentMousePos << std::endl;

	Cell* cell = GET_SINGLETON(MapManager)->getCell(_currentMousePos);
	bool isValid = isInMap(_currentMousePos) && isCellEmpty() && cell->type == MAP_TYPE::Place;

	if (isValid)
	{
		Engine::Get().setColor((int)Color::BLACK, (int)cell->bgColor);
		Engine::Get().gotoxy(GET_SINGLETON(MapManager)->cellPosToConsolePos(_currentMousePos));
		cout << "★";
		Engine::Get().setColor((int)Color::WHITE, (int)Color::BLACK);
	}
}

bool PlaceState::isInMap(const Vector2& pos)
{
	bool isXIn = _currentMousePos.x >= 0 && _currentMousePos.x < MAP_WIDTH;
	bool isYIn = _currentMousePos.y >= 0 && _currentMousePos.y < MAP_HEIGHT;
	return isYIn && isXIn;
}

bool PlaceState::isCellEmpty()
{
	return GET_SINGLETON(MapManager)->getCell(_currentMousePos)->getEntities().size() == 0;
}