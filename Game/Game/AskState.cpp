#include "AskState.h"
#include "Define.h"
#include "Level/SceneManager.h"
#include "Engine/Engine.h"
AskState::AskState(GameLevel* inGameScene)
{
	_inGameScene = inGameScene;

}

void AskState::update()
{
	KEY key = keyController();

	switch (key)
	{
	case KEY::SPACE:
	case KEY::ENTER:
		GET_SINGLETON(SceneManager)->setTransition("TitleScene");
		GET_SINGLETON(SceneManager)->loadScene("TransitionScene");
		break;
	case KEY::ESC:
		_inGameScene->changeState(INGAMESCENE_STATE::IDLE);
		break;
	}
}

void AskState::Draw()
{
	Engine::Get().gotoxy(37, 0);
	cout << "���� �����ðڽ��ϱ�? (ENTER or SPACE�� ���� ������)";
	Engine::Get().gotoxy(45, 1);
	cout << "���â�� Ȯ���Ͻ� �� �����ϴ�.";
	Engine::Get().gotoxy(50, 2);
	cout << "ESCŰ�� ���� ���";

}

