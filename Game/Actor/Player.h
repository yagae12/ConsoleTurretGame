#pragma once

#pragma once
#include "Define.h"
#include "Ally/Ally.h"
#include "EntityManager.h"
class Player
{
	DECLARE_SINGLETON(Player)
private:
	Ally* _selectedAlly = nullptr;
public:
	void init();
public:
	void setAlly(Ally* ally) { _selectedAlly = ally; }
	Ally* getAlly() { return _selectedAlly; }
	void modifyHP(int value);
	void modifyGold(int value, bool withTotal = true);
	int getGold() { return _gold; }
	int getTotalGold() { return _totalGold; }
	int getHP() { return _hp; }
private:
	int _hp = 3;
	int _totalGold = 30;
	int _gold = 30;
};