#include "MenuLevel.h"
#include "Game/Game.h"

MenuLevel::MenuLevel()
{
// 	menuItems.PushBack(new MenuItem("Resume Game", []() { Game::Get().ToggleMenu(); }));
	menuItems.PushBack(new MenuItem("Quit Game", []() { Game::Get().QuitGame(); }));
	length = menuItems.Size();
}

MenuLevel::~MenuLevel()
{
	for (auto* item : menuItems)
	{
		delete item;
	}
}

void MenuLevel::Update(float deltaTime)
{
// 	if (Game::Get().GetKeyDown(VK_ESCAPE))
// 	{
// 		Game::Get().ToggleMenu();
// 	}

	if (Game::Get().GetKeyDown(VK_UP))
	{
		currentIndex = (currentIndex - 1 + length) % length;
	}
	if (Game::Get().GetKeyDown(VK_DOWN))
	{
		currentIndex = (currentIndex + 1) % length;
	}

	if (Game::Get().GetKeyDown(VK_RETURN))
	{
		menuItems[currentIndex]->onSelected();
	}

}

void MenuLevel::Draw()
{
	Super::Draw();

	// 메뉴 그리기.

// 	SetColor(unselectedColor);
	Engine::Get().Draw(Vector2(0, 0), " Game", Color::White);

	// 메뉴 항목 그리기.
	for (int ix = 0; ix < length; ++ix)
	{
		if (ix == currentIndex)
		{
			Engine::Get().Draw(Vector2(0, ix + 1), menuItems[ix]->menuText, Color::Green);
		}
		else
		{
			Engine::Get().Draw(Vector2(0, ix + 1), menuItems[ix]->menuText, Color::White);
		}
	}
}	
