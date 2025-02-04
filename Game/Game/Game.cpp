#include "Game.h"
#include "Engine/Engine.h"
#include "Define.h"
#include "Level/SceneManager.h"
#include "Level/TitleScene.h"
#include "Level/GameLevel.h"
#include "Actor/EntityManager.h"
#include "Level/MenuLevel.h"
#include "WaveManager.h"


Game::Game()
{
}

Game::~Game()
{
// 	if (showMenu)
// 	{
// 		delete backLevel;
// 		backLevel = nullptr;
// 		mainLevel = nullptr;
// 	}
// 	else
// 	{
// 		delete mainLevel;
// 		mainLevel = nullptr;
// 	}
// 
// 	delete menuLevel;
// 	menuLevel = nullptr;
}

// void Game::ToggleMenu()
// {
// 	system("cls");
// 	//Clear();
// 	showMenu = !showMenu;
// 	if (showMenu)
// 	{
// 		backLevel = mainLevel;
// 		mainLevel = menuLevel;
// 	}
// 	else
// 	{
// 		mainLevel = backLevel;
// 	}
// }

void Game::init()
{
	Engine::Get().lockDragAndClick();
	Engine::Get().lockConsoleScroll();

	GET_SINGLETON(EntityManager)->init();

	GET_SINGLETON(WaveManager)->init();

	GET_SINGLETON(SceneManager)->init();
	GET_SINGLETON(SceneManager)->registerScene("TitleScene", new TitleScene);
	GET_SINGLETON(SceneManager)->registerScene("GameLevel", new GameLevel);
// 	GET_SINGLETON(SceneManager)->registerScene("TransitionScene", new TransitionScene);
// 	GET_SINGLETON(SceneManager)->registerScene("InfoScene", new InfoScene);
// 	GET_SINGLETON(SceneManager)->registerScene("EndScene", new EndScene);

	GET_SINGLETON(SceneManager)->loadScene("TitleScene");

}

void Game::update()
{
	GET_SINGLETON(SceneManager)->update();

}

void Game::Draw()
{
	GET_SINGLETON(SceneManager)->draw();

}
