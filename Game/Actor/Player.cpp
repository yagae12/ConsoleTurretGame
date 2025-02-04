#include "Player.h"
#include "Level/SceneManager.h"
Player* Player::m_pInst = nullptr;

void Player::init()
{
<<<<<<< HEAD
	_hp = 3;
	_totalGold = 30;
	_gold = 30;
=======
	// À§Ä¡ ¼³Á¤.
	this->position = position;

	// »ö»ó ¼³Á¤.
	color = Color::White;
>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)
}

void Player::modifyHP(int value)
{
	_hp += value;
	if (_hp <= 0)
	{
		GET_SINGLETON(SceneManager)->loadScene("EndScene");
	}
}

void Player::modifyGold(int value, bool withTotal)
{
	if (value > 0 && withTotal)
		_totalGold += value;
	_gold += value;
}
