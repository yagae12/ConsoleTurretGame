#include "TitleScene.h"
#include "Define.h"
#include <iostream>
#include <Windows.h>
#include "Engine/Engine.h"
#include <fcntl.h>
#include <io.h>
#include "SceneManager.h"
#include "Game/Key.h"
#include<conio.h>
#include <mciapi.h>
#include "Level/GameLevel.h"

using namespace std;
UINT Effectid;

TitleScene::TitleScene() {}
TitleScene::~TitleScene() {}

void TitleScene::init()
{
	srand(time(NULL));
	system("title !!!!DefaultDefence!!!!");
	Engine::Get().setCursorVisible(false, 1);
	Engine::Get().lockResize();
}

void TitleScene::update()
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L" ██████╗ ███████╗███████╗███████╗███╗   ██╗███████╗███████╗" << endl;
	wcout << L" ██╔══██╗██╔════╝██╔════╝██╔════╝████╗  ██║██╔════╝██╔════╝" << endl;
	wcout << L" ██║  ██║█████╗  █████╗  █████╗  ██╔██╗ ██║███████╗█████╗  " << endl;
	wcout << L" ██║  ██║██╔══╝  ██╔══╝  ██╔══╝  ██║╚██╗██║╚════██║██╔══╝  " << endl;
	wcout << L" ██████╔╝███████╗██║     ███████╗██║ ╚████║███████║███████╗" << endl;
	wcout << L" ╚═════╝ ╚══════╝╚═╝     ╚══════╝╚═╝  ╚═══╝╚══════╝╚══════╝" << endl;
	wcout << L"                                                           " << endl;
	wcout << L" ██████╗  █████╗ ███╗   ███╗███████╗                       " << endl;
	wcout << L"██╔════╝ ██╔══██╗████╗ ████║██╔════╝                       " << endl;
	wcout << L"██║  ███╗███████║██╔████╔██║█████╗                         " << endl;
	wcout << L"██║   ██║██╔══██║██║╚██╔╝██║██╔══╝                         " << endl;
	wcout << L"╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗                       " << endl;
	wcout << L" ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝                       " << endl;

	int curmode = _setmode(_fileno(stdout), prevmode);
}

void TitleScene::Draw()
{
	COORD Resolution = Engine::Get().getConsoleResolution();
	int x = Resolution.X / 2.5;
	int y = Resolution.Y / 2.5;
	int originy = y;

	Engine::Get().gotoxy(x - 2, y);
	cout << "> 게임 시작";
	Engine::Get().gotoxy(x, y + 1);
	cout << "게임 종료";


	while (true)
	{
		KEY eKey = KeyController();
		switch (eKey)
		{
		case KEY::UP:
			if (y > originy)
			{
				if (y == originy + 10)
				{
					Engine::Get().gotoxy(x - 2, y);
					cout << " ";
					Engine::Get().gotoxy(x - 2, y -= 8);
					cout << ">";
				}
				else
				{
					Engine::Get().gotoxy(x - 2, y);
					cout << " ";
					Engine::Get().gotoxy(x - 2, --y);
					cout << ">";
					Sleep(100);
				}
			}
			break;
		case KEY::DOWN:
			if (y < originy + 2)
			{
				Engine::Get().gotoxy(x - 2, y);
				cout << " ";
				Engine::Get().gotoxy(x - 2, ++y);
				cout << ">";
				Sleep(100);
			}
			else if (y == originy + 2)
			{
				Engine::Get().gotoxy(x - 2, y);
				cout << " ";
				Engine::Get().gotoxy(x - 2, y += 8);
				cout << ">";
			}
			break;
		case KEY::ENTER:
		case KEY::SPACE:
			if (originy == y) { // "게임 시작" 선택
				GET_SINGLETON(SceneManager)->loadScene("GameLevel");
			}
			else if (originy + 1 == y) { // "게임 종료" 선택
				exit(0);
			}
			system("cls");
			return;
		}
	}
}


KEY TitleScene::KeyController()
{
	if (_kbhit())
	{
		int key = _getch();
		if (key == 0 || key == 224)
		{
			key = _getch();
// 			KEY eKey = (KEY)key;
// 			if (eKey == KEY::SPACE || eKey == KEY::ENTER)
// 			{
// 				PlayEffect();
// 			}
// 			return eKey;
		}
		return (KEY)key;
	}
	return KEY::FAIL;
}
