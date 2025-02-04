#include "IdleState.h"
#include "Level/GameLevel.h"
#include<conio.h>
#include "WaveManager.h"
#include "Level/SceneManager.h"
#include "Engine/Engine.h"

IdleState::IdleState(GameLevel* inGameScene)
{
	_inGameScene = inGameScene;

}

void IdleState::update()
{
	KEY Key = keyController();
	switch (Key)
	{
	case KEY::ONE:
	{
		_inGameScene->changeState(INGAMESCENE_STATE::SELECT);
		break;
	}
	case KEY::TWO:
	{
		_inGameScene->changeState(INGAMESCENE_STATE::REMOVE);
		break;
	}
	case KEY::THREE:
	{
		_inGameScene->changeState(INGAMESCENE_STATE::BATTLE);
		GET_SINGLETON(WaveManager)->nextWave();
		break;
	}
	case KEY::FOUR:
	{
		_inGameScene->changeState(INGAMESCENE_STATE::ASK);
		break;
	}
	}
}

void IdleState::Draw()
{
	Engine::Get().gotoxy(49, 0);
	cout << " 다음 웨이브 :  " << GET_SINGLETON(WaveManager)->getCurrentWave() + 1;
	Engine::Get().gotoxy(22, 27);
	cout << "(1) 아군 고용\t\t(2) 아군 방출\t\t(3) 전투 시작!\t\t(4) 게임 종료";

}

