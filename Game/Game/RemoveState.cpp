#include "RemoveState.h"
#include "Actor/EntityManager.h"
#include "Level/MapManager.h"
#include "Actor/Player.h"
#include "Engine/Engine.h"
RemoveState::RemoveState(GameLevel* inGameScene)
{
	_inGameScene = inGameScene;

}

void RemoveState::update()
{
	_currentMousePos = GET_SINGLETON(MapManager)->consolePosToCellPos(Engine::Get().getMousePos());

	if (keyController() == KEY::ESC)
	{
		_inGameScene->changeState(INGAMESCENE_STATE::IDLE);
	}
	if (Engine::Get().getMouseInput())
	{
		Cell* cell = GET_SINGLETON(MapManager)->getCell(_currentMousePos);
		bool isValid = isInMap(_currentMousePos) && !isCellEmpty() && cell->type == MAP_TYPE::Place;
		if (isValid)
		{
			Ally* ally = cell->getEntities<Ally>(ENTITY_TYPE::ALLY).front();
			if (ally != nullptr)
			{
				GET_SINGLETON(EntityManager)->despawnEntity(ally);
				_inGameScene->changeState(INGAMESCENE_STATE::IDLE);
			}
		}
	}

}

void RemoveState::Draw()
{
	Engine::Get().gotoxy(40, 0);
	cout << "���ϴ� ���� ���콺�� Ŭ���Ͽ� �Ʊ��� �����ϼ���.";
	Engine::Get().gotoxy(43, 1);
	cout << "���� ������ ��ġ���� �÷� ǥ�õ˴ϴ�.";
	Engine::Get().gotoxy(50, 2);
	cout << "ESC�� ���� ���";

	Cell* cell = GET_SINGLETON(MapManager)->getCell(_currentMousePos);
	bool isValid = isInMap(_currentMousePos) && !isCellEmpty() && cell->type == MAP_TYPE::Place;
	if (isValid)
	{
		Engine::Get().setColor((int)Color::RED, (int)cell->bgColor);
		Engine::Get().gotoxy(GET_SINGLETON(MapManager)->cellPosToConsolePos(_currentMousePos));
		cout << "��";
		Engine::Get().setColor((int)Color::WHITE, (int)Color::BLACK);
	}

}


bool RemoveState::isInMap(const Vector2& pos)
{
	bool isXIn = _currentMousePos.x >= 0 && _currentMousePos.x < MAP_WIDTH;
	bool isYIn = _currentMousePos.y >= 0 && _currentMousePos.y < MAP_HEIGHT;
	return isYIn && isXIn;
}

bool RemoveState::isCellEmpty()
{
	return GET_SINGLETON(MapManager)->getCell(_currentMousePos)->getEntities().size() == 0;
}
