#include "InGameState.h"
#include<conio.h>

void InGameState::update()
{
}

void InGameState::Draw()
{
}

KEY InGameState::keyController()
{
	if (_kbhit())
	{
		int key = _getch();
		if (key == 0 || key == 224)
		{
			key = _getch();
			KEY eKey = (KEY)key;
			if (eKey == KEY::SPACE || eKey == KEY::ENTER)
			{
			}
			return eKey;
			if (key == 27)
			{
				return KEY::ESC; // ESC Å° ¹ÝÈ¯
			}
		}
		return (KEY)key;
	}
	return KEY::FAIL;
}
