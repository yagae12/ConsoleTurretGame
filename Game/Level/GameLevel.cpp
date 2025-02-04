#include "GameLevel.h"
#include "Engine/Engine.h"

<<<<<<< HEAD
#include "Define.h"
=======
#include "Actor/Wall.h"
#include "Actor/Place.h"
#include "Actor/Road.h"
#include "Actor/House.h"
>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)

#include "Engine/Timer.h"
<<<<<<< HEAD
#include <fstream>
#include "Actor/EntityManager.h"
#include "Actor/Type.h"
#include "MapManager.h"
#include "Actor/Player.h"
#include <Windows.h>
#include "Actor/Cell.h"
#include "WaveManager.h"
#include "Game/IdleState.h"
#include "Game/InGameState.h"
#include "Game/PlaceState.h"
#include "Game/SelectState.h"
#include "Game/RemoveState.h"
#include "Game/BattleState.h"
#include "Game/AskState.h"

GameLevel::GameLevel() 
{
}

void GameLevel::init()
=======

GameLevel::GameLevel()
>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)
{
	Engine::Get().SetCursorType(CursorType::NoCursor);

<<<<<<< HEAD
	std::fstream mapRead("../Assets/Maps/Map1.txt");
	if (mapRead.is_open())
	{
		for (int i = 0; i < MAP_HEIGHT - 1; i++)
		{
			for (int j = 0; j < MAP_WIDTH; j++)
			{
				char read = mapRead.get();

				if (read == '0')
				{
					GET_SINGLETON(MapManager)->setCell(Cell{ Color::GRAY, "  " , MAP_TYPE::Wall, ROAD_TYPE::NONE }, Vector2(j, i));
				}
				else if (read == '1')
				{
					GET_SINGLETON(MapManager)->setCell(Cell{ Color::LIGHT_GRAY, "  ", MAP_TYPE::Road, ROAD_TYPE::FIRST }, Vector2(j, i));
				}
				else if (read == '2')
				{
					GET_SINGLETON(MapManager)->setCell(Cell{ Color::WHITE, "  ", MAP_TYPE::Place, ROAD_TYPE::NONE }, Vector2(j, i));
				}
				else if (read == '3')
				{
					GET_SINGLETON(MapManager)->setCell(Cell{ Color::LIGHT_GRAY, "  ", MAP_TYPE::Road, ROAD_TYPE::SECOND }, Vector2(j, i));
				}
				else if (read == '4')
				{
					GET_SINGLETON(MapManager)->setCell(Cell{ Color::YELLOW, "  ", MAP_TYPE::House, ROAD_TYPE::NONE }, Vector2(j, i));
				}

				if (mapRead.fail())
				{
					cout << "File read error.";
					break;
				}
			}
		}
	}
	mapRead.close();
	_stateMap.insert(std::make_pair(INGAMESCENE_STATE::IDLE, new IdleState(this)));
	_stateMap.insert(std::make_pair(INGAMESCENE_STATE::SELECT, new SelectState(this)));
	_stateMap.insert(std::make_pair(INGAMESCENE_STATE::REMOVE, new RemoveState(this)));
	_stateMap.insert(std::make_pair(INGAMESCENE_STATE::PLACE, new PlaceState(this)));
	_stateMap.insert(std::make_pair(INGAMESCENE_STATE::BATTLE, new BattleState(this)));
	_stateMap.insert(std::make_pair(INGAMESCENE_STATE::ASK, new AskState(this)));

	changeState(INGAMESCENE_STATE::IDLE);

=======
	// ¸Ê ÆÄÀÏ ºÒ·¯¿Í ·¹º§ ·Îµå.
	// ÆÄÀÏ ÀÐ±â.
	FILE* file = nullptr;
	fopen_s(&file, "../Assets/Maps/Map.txt", "rb");

	// ÆÄÀÏ Ã³¸®.
	if (file == nullptr)
	{
		std::cout << "¸Ê ÆÄÀÏ ¿­±â ½ÇÆÐ.\n";
		__debugbreak();
		return;
	}

	// ÆÄÀÏ ÀÐ±â.
	// ³¡À§Ä¡·Î ÀÌµ¿.
	fseek(file, 0, SEEK_END);

	// ÀÌµ¿ÇÑ À§Ä¡ÀÇ FP °¡Á®¿À±â.
	size_t readSize = ftell(file);

	// FP ¿øÀ§Ä¡.
	//fseek(file, 0, SEEK_SET);
	rewind(file);

	// ÆÄÀÏ ÀÐ¾î¼­ ¹öÆÛ¿¡ ´ã±â.
	char* buffer = new char[readSize + 1];
	size_t bytesRead = fread(buffer, 1, readSize, file);

	if (readSize != bytesRead)
	{
		std::cout << "ÀÐ¾î¿Â Å©±â°¡ ´Ù¸§\n";
		__debugbreak();
		return;
	}

	buffer[readSize] = '\0';

	// ÆÄÀÏ ÀÐÀ» ¶§ »ç¿ëÇÒ ÀÎµ¦½º.
	int index = 0;

	// ÁÂÇ¥ °è»êÀ» À§ÇÑ º¯¼ö ¼±¾ð.
	int xPosition = 0;
	int yPosition = 0;

	// ÇØ¼® (ÆÄ½Ì-Parcing).
	while (index < (int)bytesRead)
	{
		// ÇÑ ¹®ÀÚ¾¿ ÀÐ±â.
		char mapChar = buffer[index++];

		// °³Çà ¹®ÀÚÀÎ °æ¿ì Ã³¸®.
		if (mapChar == '\n')
		{
			++yPosition;
			xPosition = 0;
			continue;
		}

		// ¸Ê ¹®ÀÚ°¡ 1ÀÌ¸é Wall ¾×ÅÍ »ý¼º.
		if (mapChar == '1')
		{
			Wall* wall = new Wall(Vector2(xPosition, yPosition));
			actors.PushBack(wall);
			map.PushBack(wall);
			//Engine::Get().Draw(Vector2(xPosition, yPosition), "¢Ã", Color::Red);
		}

		// ¸Ê ¹®ÀÚ°¡ .ÀÌ¸é ±×¶ó¿îµå ¾×ÅÍ »ý¼º.
		else if (mapChar == '.')
		{
			Place* ground = new Place(Vector2(xPosition, yPosition));
			actors.PushBack(ground);
			map.PushBack(ground);
		}

		// ¸Ê ¹®ÀÚ°¡ bÀÌ¸é ¹Ú½º ¾×ÅÍ »ý¼º.
		else if (mapChar == 'b')
		{
			Place* ground = new Place(Vector2(xPosition, yPosition));
			actors.PushBack(ground);
			map.PushBack(ground);

			Road* box = new Road(Vector2(xPosition, yPosition));
			actors.PushBack(box);
			boxes.PushBack(box);
		}

		// ¸Ê ¹®ÀÚ°¡ tÀÌ¸é Å¸°Ù ¾×ÅÍ »ý¼º.
		else if (mapChar == 't')
		{
			House* target = new House(Vector2(xPosition, yPosition));
			actors.PushBack(target);
			map.PushBack(target);
			targets.PushBack(target);
		}

	}

	// ¹öÆÛ »èÁ¦.
	delete[] buffer;

	// ÆÄÀÏ ´Ý±â.
	fclose(file);
>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)
}

void GameLevel::update()
{
<<<<<<< HEAD
	_currentState->update();
=======
	Super::Update(deltaTime);

	// °ÔÀÓÀÌ Å¬¸®¾îµÆÀ¸¸é, °ÔÀÓ Á¾·á Ã³¸®.
	if (isGameClear)
	{
		// ´ë·« ÇÑ ÇÁ·¹ÀÓ Á¤µµÀÇ ½Ã°£ ´ë±â.
		//static float elapsedTime = 0.0f;
		//elapsedTime += deltaTime;
		//if (elapsedTime < 0.1f)
		//{
		//	return;
		//}

		// Å¸ÀÌ¸Ó.
		static Timer timer(0.1f);
		timer.Update(deltaTime);
		if (!timer.IsTimeOut())
		{
			return;
		}

		//Ä¿¼­ ÀÌµ¿ 
		Engine::Get().Draw(Vector2(0, 0), "Game Clear!", Color::Green);

		// ¸Þ½ÃÁö Ãâ·Â.
		Log("Game Clear!");

		// ¾²·¹µå Á¤Áö.
		Sleep(2000);

		// °ÔÀÓ Á¾·á Ã³¸®.
		Engine::Get().QuitGame();
	}
>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)
}


// void GameLevel::Update(float deltaTime)
// {
// 	Super::Update(deltaTime);
// 
// 	// °ÔÀÓÀÌ Å¬¸®¾îµÆÀ¸¸é, °ÔÀÓ Á¾·á Ã³¸®.
// // 	if (isGameClear)
// // 	{
// // 		// ´ë·« ÇÑ ÇÁ·¹ÀÓ Á¤µµÀÇ ½Ã°£ ´ë±â.
// // 		//static float elapsedTime = 0.0f;
// // 		//elapsedTime += deltaTime;
// // 		//if (elapsedTime < 0.1f)
// // 		//{
// // 		//	return;
// // 		//}
// // 
// // 		// Å¸ÀÌ¸Ó.
// // 		static Timer timer(0.1f);
// // 		timer.Update(deltaTime);
// // 		if (!timer.IsTimeOut())
// // 		{
// // 			return;
// // 		}
// // 
// // 		//Ä¿¼­ ÀÌµ¿ 
// // 		Engine::Get().Draw(Vector2(0, 0), "Game Clear!", Color::GREEN);
// // 
// // 		// ¸Þ½ÃÁö Ãâ·Â.
// // 		Log("Game Clear!");
// // 
// // 		// ¾²·¹µå Á¤Áö.
// // 		Sleep(2000);
// // 
// // 		// °ÔÀÓ Á¾·á Ã³¸®.
// // 		Engine::Get().QuitGame();
// // 	}
// 	enemymove();
// 	// 	for (auto& ally : GET_SINGLETON(EntityManager)->getAlly())
// 	// 	{
// 	// 		ally->tryAttack();
	// 	}
// }

void GameLevel::Draw()
{
<<<<<<< HEAD
	mapRender();
	uiRender();
	_currentState->Draw();
=======
	// ¸Ê ±×¸®±â.
	for (auto* actor : map)
	{
		// ÇÃ·¹ÀÌ¾î À§Ä¡ È®ÀÎ.
		if (actor->Position() == player->Position())
		{
			continue;
		}

		// ¹Ú½º À§Ä¡ È®ÀÎ.
		bool shouldDraw = true;
		for (auto* box : boxes)
		{
			if (actor->Position() == box->Position())
			{
				shouldDraw = false;
				break;
			}
		}

		// ¸Ê ¾×ÅÍ ±×¸®±â.
		if (shouldDraw)
		{
			actor->Draw();
		}
	}

	// Å¸°Ù ±×¸®±â.
	for (auto* target : targets)
	{
		// ÇÃ·¹ÀÌ¾î À§Ä¡ È®ÀÎ.
		if (target->Position() == player->Position())
		{
			continue;
		}

		// ¹Ú½º À§Ä¡ È®ÀÎ.
		bool shouldDraw = true;
		for (auto* box : boxes)
		{
			if (target->Position() == box->Position())
			{
				shouldDraw = false;
				break;
			}
		}

		// Å¸°Ù ¾×ÅÍ ±×¸®±â.
		if (shouldDraw)
		{
			target->Draw();
		}
	}

	// ¹Ú½º ±×¸®±â.
	for (auto* box : boxes)
	{
		box->Draw();
	}

	// ÇÃ·¹ÀÌ¾î ±×¸®±â.
	player->Draw();
>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)
}


void GameLevel::changeState(INGAMESCENE_STATE state)
{
	system("cls");
	_currentState = _stateMap[state];

<<<<<<< HEAD
}

void GameLevel::mapRender()
{
	Engine::Get().gotoxy(30, 6);
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			Vector2 pos = Vector2(j, i);
			Cell* cell = GET_SINGLETON(MapManager)->getCell(pos);
			Engine::Get().setColor((int)cell->charColor, (int)cell->bgColor);
			entityRender(pos);
=======
	// ¹Ú½º °Ë»ö.
	Road* searchedBox = nullptr;
	for (auto* box : boxes)
	{
		if (box->Position() == position)
		{
			searchedBox = box;
			break;
>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)
		}
	}
<<<<<<< HEAD
	Engine::Get().setColor((int)Color::WHITE, (int)Color::BLACK);
}

void GameLevel::entityRender(const Vector2& pos)
{
	cout << GET_SINGLETON(MapManager)->getCell(pos)->renderString;
=======

	// ¹Ú½º°¡ ÀÖÀ» ¶§ Ã³¸®.
	if (searchedBox)
	{
		// ÀÌµ¿ ¹æÇâ.
		int directionX = position.x - player->Position().x;
		int directionY = position.y - player->Position().y;

		// ¹Ú½º°¡ ÀÌµ¿ÇÒ »õ À§Ä¡.
		Vector2 newPosition 
			= searchedBox->Position() + Vector2(directionX, directionY);

		// Ãß°¡ °Ë»ö (¹Ú½º).
		for (auto* box : boxes)
		{
			// ¿¹¿Ü Ã³¸®.
			if (box == searchedBox)
			{
				continue;
			}

			// ÀÌµ¿ÇÒ À§Ä¡¿¡ ´Ù¸¥ ¹Ú½º°¡ ÀÖ´Ù¸é ÀÌµ¿ ºÒ°¡.
			if (box->Position() == newPosition)
			{
				return false;
			}
		}

		// Ãß°¡ °Ë»ö (¸Ê).
		for (auto* actor : map)
		{
			// ÀÌµ¿ÇÏ·Á´Â À§Ä¡¿¡ ÀÖ´Â ¾×ÅÍ °Ë»ö.
			if (actor->Position() == newPosition)
			{
				// Çüº¯È¯À» ÅëÇØ ¹°Ã¼ÀÇ Å¸ÀÔ È®ÀÎ.

				// ÀÌµ¿ÇÏ·Á´Â À§Ä¡¿¡ º®ÀÌ ÀÖÀ¸¸é ÀÌµ¿ ºÒ°¡.
				if (actor->As<Wall>())
				{
					return false;
				}

				// ¶¥ÀÌ³ª Å¸°ÙÀÌ¸é ÀÌµ¿ °¡´É.
				if (actor->As<Place>() || actor->As<House>())
				{
					// ¹Ú½º ÀÌµ¿ Ã³¸®.
					searchedBox->SetPosition(newPosition);

					// °ÔÀÓ Å¬¸®¾î ¿©ºÎ È®ÀÎ.
					isGameClear = CheckGameClear();

					return true;
				}
			}
		}
	}

	// ÀÌµ¿ÇÏ·Á´Â À§Ä¡¿¡ º®ÀÌ ÀÖ´ÂÁö È®ÀÎ.
	DrawableActor* searchedActor = nullptr;

	// ¸ÕÀú ÀÌµ¿ÇÏ·Á´Â À§Ä¡ÀÇ ¾×ÅÍ Ã£±â.
	for (auto* actor : map)
	{
		if (actor->Position() == position)
		{
			searchedActor = actor;
			break;
		}
	}

	// °Ë»öÇÑ ¾×ÅÍ°¡ º®ÀÎÁö È®ÀÎ.
	if (searchedActor->As<Wall>())
	{
		return false;
	}

	// °Ë»öÇÑ ¾×ÅÍ°¡ ÀÌµ¿ °¡´ÉÇÑ ¾×ÅÍ(¶¥/Å¸°Ù)ÀÎÁö È®ÀÎ.
	if (searchedActor->As<Place>()
		|| searchedActor->As<House>())
	{
		return true;
	}

	return false;
>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)
}

void GameLevel::uiRender()
{
<<<<<<< HEAD
	Engine::Get().gotoxy(1, 1);
	cout << "ÇöÀç Ã¼·Â : ";
	for (int i = 0; i < GET_SINGLETON(Player)->getHP(); i++)
	{
		cout << "¢¾";
	}
	cout << "   ";

	Engine::Get().gotoxy(1, 2);
	cout << "°ñµå : " << GET_SINGLETON(Player)->getGold();
}
=======
	// Á¡¼ö È®ÀÎÀ» À§ÇÑ º¯¼ö.
	int currentScore = 0;
	int targetScore = targets.Size();

	// Å¸°Ù À§Ä¡¿¡ ¹èÄ¡µÈ ¹Ú½º °³¼ö ¼¼±â.
	for (auto* box : boxes)
	{
		for (auto* target : targets)
		{
			// Á¡¼ö È®ÀÎ.
			if (box->Position() == target->Position())
			{
				++currentScore;
				break;
			}
		}
	}

	// È¹µæÇÑ Á¡¼ö°¡ ¸ñÇ¥ Á¡¼ö¿Í °°ÀºÁö ºñ±³.
	return currentScore == targetScore;
}
>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)
