#include "SelectState.h"
#include "Actor/Player.h"
#include<conio.h>
#include "Engine/Engine.h"
#include <iostream>
#include "Define.h"

SelectState::SelectState(GameLevel* inGameScene)
{
	_inGameScene = inGameScene;

}
void SelectState::update()
{
	KEY Key = keyController();
	switch (Key)
	{
	case KEY::ONE:
	{
		_currentSelectIndex = 1;
		break;
	}
	case KEY::TWO:
	{
		_currentSelectIndex = 2;
		break;
	}
	case KEY::THREE:
	{
		_currentSelectIndex = 3;
		break;
	}
	case KEY::FOUR:
	{
		_currentSelectIndex = 4;
		break;
	}
	case KEY::RIGHT:
	{
		if (_currentPage < 3)
			_currentPage++;
		break;
	}
	case KEY::LEFT:
	{
		if (_currentPage > 1)
			_currentPage--;
		break;
	}
	case KEY::UP:
	{
		if (_currentSelectIndex > 1)
			_currentSelectIndex--;
		break;
	}
	case KEY::DOWN:
	{
		if (_currentSelectIndex < 4)
			_currentSelectIndex++;
		break;
	}
	case KEY::ENTER:
	{
		spawnAlly();
		break;
	}
	case KEY::SPACE:
	{
		spawnAlly();
		break;
	}
	case KEY::ESC:
	{
		_inGameScene->changeState(INGAMESCENE_STATE::IDLE);
		break;
	}
	}
}

void SelectState::Draw()
{
	if (_currentPage == 1)
	{
		Engine::Get().gotoxy(92, 6);
		cout << "���������������" << endl;
		Engine::Get().gotoxy(92, 7);
		cout << "��  �ü�    | ��Ÿ�: 3ĭ ��" << endl;
		Engine::Get().gotoxy(92, 8);
		cout << "�ᰡ��: 20  | ���ݷ�: 5   ��" << endl;
		Engine::Get().gotoxy(92, 9);
		cout << "���������������" << endl << endl;

		Engine::Get().gotoxy(92, 11);
		cout << "���������������" << endl;
		Engine::Get().gotoxy(92, 12);
		cout << "��  ���ú�  | ��Ÿ�: 5ĭ ��" << endl;
		Engine::Get().gotoxy(92, 13);
		cout << "�ᰡ��: 50  | ���ݷ�: 1   ��" << endl;
		Engine::Get().gotoxy(92, 14);
		cout << "���������������" << endl << endl;

		Engine::Get().gotoxy(92, 16);
		cout << "���������������" << endl;
		Engine::Get().gotoxy(92, 17);
		cout << "��  �߸���Ÿ| ��Ÿ�: 10ĭ��" << endl;
		Engine::Get().gotoxy(92, 18);
		cout << "�ᰡ��: 1000| ���ݷ�: 200 ��" << endl;
		Engine::Get().gotoxy(92, 19);
		cout << "���������������" << endl << endl;

		Engine::Get().gotoxy(92, 21);
		cout << "���������������" << endl;
		Engine::Get().gotoxy(92, 22);
		cout << "��  ������  | ��Ÿ�: 5ĭ ��" << endl;
		Engine::Get().gotoxy(92, 23);
		cout << "�ᰡ�� : 100| ���ݷ�: 10  ��" << endl;
		Engine::Get().gotoxy(92, 24);
		cout << "���������������" << endl << endl;
	}
	else if (_currentPage == 2)
	{
		Engine::Get().gotoxy(92, 6);
		cout << "���������������" << endl;
		Engine::Get().gotoxy(92, 7);
		cout << "��  ȭ��������|��Ÿ�: 5ĭ��" << endl;
		Engine::Get().gotoxy(92, 8);
		cout << "�ᰡ��: 400   |���ݷ�: 10 ��" << endl;
		Engine::Get().gotoxy(92, 9);
		cout << "���������������" << endl << endl;

		Engine::Get().gotoxy(92, 11);
		cout << "���������������" << endl;
		Engine::Get().gotoxy(92, 12);
		cout << "��  ����������|��Ÿ�: 5ĭ��" << endl;
		Engine::Get().gotoxy(92, 13);
		cout << "�ᰡ��: 500   |���ݷ�: 5  ��" << endl;
		Engine::Get().gotoxy(92, 14);
		cout << "���������������" << endl << endl;

		Engine::Get().gotoxy(92, 16);
		cout << "���������������" << endl;
		Engine::Get().gotoxy(92, 17);
		cout << "��  ����������|��Ÿ�: �� ��" << endl;
		Engine::Get().gotoxy(92, 18);
		cout << "�ᰡ��: 500   |���ݷ�: 20 ��" << endl;
		Engine::Get().gotoxy(92, 19);
		cout << "���������������" << endl << endl;

		Engine::Get().gotoxy(92, 21);
		cout << "���������������" << endl;
		Engine::Get().gotoxy(92, 22);
		cout << "��  ��ũ�θǼ�|��Ÿ�: ?ĭ��" << endl;
		Engine::Get().gotoxy(92, 23);
		cout << "�ᰡ�� : 500  |���ݷ�: ?? ��" << endl;
		Engine::Get().gotoxy(92, 24);
		cout << "���������������" << endl << endl;
	}
	else if (_currentPage == 3)
	{
		Engine::Get().gotoxy(92, 6);
		cout << "���������������" << endl;
		Engine::Get().gotoxy(92, 7);
		cout << "��  �˺�    | ��Ÿ�: 1ĭ ��" << endl;
		Engine::Get().gotoxy(92, 8);
		cout << "�ᰡ��: 50  | ���ݷ�: 5   ��" << endl;
		Engine::Get().gotoxy(92, 9);
		cout << "���������������" << endl << endl;

		Engine::Get().gotoxy(92, 11);
		cout << "���������������" << endl;
		Engine::Get().gotoxy(92, 12);
		cout << "��  â��    | ��Ÿ�: 2ĭ ��" << endl;
		Engine::Get().gotoxy(92, 13);
		cout << "�ᰡ��: 80  | ���ݷ�: 7   ��" << endl;
		Engine::Get().gotoxy(92, 14);
		cout << "���������������" << endl << endl;

		Engine::Get().gotoxy(92, 16);
		cout << "���������������" << endl;
		Engine::Get().gotoxy(92, 17);
		cout << "��  �����̾�| ��Ÿ�: 1ĭ ��" << endl;
		Engine::Get().gotoxy(92, 18);
		cout << "�ᰡ��: 1000| ���ݷ�: 200 ��" << endl;
		Engine::Get().gotoxy(92, 19);
		cout << "���������������" << endl << endl;

		Engine::Get().gotoxy(92, 21);
		cout << "���������������" << endl;
		Engine::Get().gotoxy(92, 22);
		cout << "��  ��˺�  | ��Ÿ�: 2ĭ ��" << endl;
		Engine::Get().gotoxy(92, 23);
		cout << "�ᰡ��: 1500| ���ݷ�: 300 ��" << endl;
		Engine::Get().gotoxy(92, 24);
		cout << "���������������" << endl << endl;
	}

	Engine::Get().gotoxy(103, 26);
	cout << _currentPage << " / 3" << endl;

	int selectMarkY = 7 + 5 * (_currentSelectIndex - 1);
	Engine::Get().gotoxy(93, selectMarkY);
	cout << "��";

	Engine::Get().gotoxy(51, 26);
	cout << "ESCŰ�� ���� ���";
	Engine::Get().gotoxy(48, 27);
	cout << "Enter �Ǵ� SpaceŰ�� ���";

}

void SelectState::spawnAlly()
{
	ALLY_TYPE type = (ALLY_TYPE)(((_currentPage - 1) * 4) + _currentSelectIndex);

	// ��� �Ұ����� �Ʊ� ó��
	if (type == ALLY_TYPE::NECROMANCER)
	{
		Engine::Get().setColor((int)Color::RED);
		Engine::Get().gotoxy(44, 28);
		cout << "�ش� �Ʊ��� ����� �Ұ����մϴ�.";
		Engine::Get().setColor();
		return;
	}

	// Ally ����
	Ally* ally = GET_SINGLETON(EntityManager)->spawnEntity(type, Vector2(28, 19));
	if (!ally) // Ally ���� ���� Ȯ��
	{
		Engine::Get().setColor((int)Color::RED);
		Engine::Get().gotoxy(44, 28);
		cout << "�� �� ���� ������ �Ʊ� ������ �����߽��ϴ�.";
		Engine::Get().setColor();
		return;
	}

	// ��� ���� ���� Ȯ��
	if (GET_SINGLETON(Player)->getGold() < ally->getPrice())
	{
		Engine::Get().setColor((int)Color::RED);
		Engine::Get().gotoxy(44, 28);
		cout << "        ���� �����մϴ�.       ";
		Engine::Get().setColor();
		GET_SINGLETON(EntityManager)->despawnEntity(ally); // Ally �޸� ����
	}
	else
	{
		// ���������� ���
		GET_SINGLETON(Player)->modifyGold(-ally->getPrice());
		GET_SINGLETON(Player)->setAlly(ally);
		_inGameScene->changeState(INGAMESCENE_STATE::PLACE);
	}
}
