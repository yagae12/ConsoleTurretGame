#include "Player.h"
#include "Level/SceneManager.h"
Player* Player::m_pInst = nullptr;

void Player::init()
{
        _hp = 3;
        _totalGold = 30;
        _gold = 30;
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
