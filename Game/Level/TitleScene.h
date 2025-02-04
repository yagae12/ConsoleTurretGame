#pragma once
#include "Level/Scene.h"
#include "Game/Key.h"

enum class MENU
{
	START,  QUIT
};

class TitleScene : public Scene
{
public:
	TitleScene();
	~TitleScene();
public:
	void init() override;
	void update() override;
	void Draw() override;
	void PlayEffect();
	KEY KeyController();
};