#pragma once

#include <Engine/Engine.h>

class Game : public Engine
{
public:
	Game();
	~Game();

// 	void ToggleMenu();
// 
// 	static Game& Get() { return *instance; }
	void init();
	void update();
	void Draw();



private:
// 	bool showMenu = false;
// 
// 	Level* menuLevel = nullptr;
// 	Level* backLevel = nullptr;
// 
private:
// 	static Game* instance;
};