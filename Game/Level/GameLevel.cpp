#include "GameLevel.h"
#include "Engine/Engine.h"

<<<<<<< HEAD
#include "Define.h"
=======
#include "Actor/Wall.h"
#include "Actor/Place.h"
#include "Actor/Road.h"
#include "Actor/House.h"
>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)

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
>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)
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
	// �� ���� �ҷ��� ���� �ε�.
	// ���� �б�.
	FILE* file = nullptr;
	fopen_s(&file, "../Assets/Maps/Map.txt", "rb");

	// ���� ó��.
	if (file == nullptr)
	{
		std::cout << "�� ���� ���� ����.\n";
		__debugbreak();
		return;
	}

	// ���� �б�.
	// ����ġ�� �̵�.
	fseek(file, 0, SEEK_END);

	// �̵��� ��ġ�� FP ��������.
	size_t readSize = ftell(file);

	// FP ����ġ.
	//fseek(file, 0, SEEK_SET);
	rewind(file);

	// ���� �о ���ۿ� ���.
	char* buffer = new char[readSize + 1];
	size_t bytesRead = fread(buffer, 1, readSize, file);

	if (readSize != bytesRead)
	{
		std::cout << "�о�� ũ�Ⱑ �ٸ�\n";
		__debugbreak();
		return;
	}

	buffer[readSize] = '\0';

	// ���� ���� �� ����� �ε���.
	int index = 0;

	// ��ǥ ����� ���� ���� ����.
	int xPosition = 0;
	int yPosition = 0;

	// �ؼ� (�Ľ�-Parcing).
	while (index < (int)bytesRead)
	{
		// �� ���ھ� �б�.
		char mapChar = buffer[index++];

		// ���� ������ ��� ó��.
		if (mapChar == '\n')
		{
			++yPosition;
			xPosition = 0;
			continue;
		}

		// �� ���ڰ� 1�̸� Wall ���� ����.
		if (mapChar == '1')
		{
			Wall* wall = new Wall(Vector2(xPosition, yPosition));
			actors.PushBack(wall);
			map.PushBack(wall);
			//Engine::Get().Draw(Vector2(xPosition, yPosition), "��", Color::Red);
		}

		// �� ���ڰ� .�̸� �׶��� ���� ����.
		else if (mapChar == '.')
		{
			Place* ground = new Place(Vector2(xPosition, yPosition));
			actors.PushBack(ground);
			map.PushBack(ground);
		}

		// �� ���ڰ� b�̸� �ڽ� ���� ����.
		else if (mapChar == 'b')
		{
			Place* ground = new Place(Vector2(xPosition, yPosition));
			actors.PushBack(ground);
			map.PushBack(ground);

			Road* box = new Road(Vector2(xPosition, yPosition));
			actors.PushBack(box);
			boxes.PushBack(box);
		}

		// �� ���ڰ� t�̸� Ÿ�� ���� ����.
		else if (mapChar == 't')
		{
			House* target = new House(Vector2(xPosition, yPosition));
			actors.PushBack(target);
			map.PushBack(target);
			targets.PushBack(target);
		}

	}

	// ���� ����.
	delete[] buffer;

	// ���� �ݱ�.
	fclose(file);
>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)
}

void GameLevel::update()
{
<<<<<<< HEAD
	_currentState->update();
=======
	Super::Update(deltaTime);

	// ������ Ŭ���������, ���� ���� ó��.
	if (isGameClear)
	{
		// �뷫 �� ������ ������ �ð� ���.
		//static float elapsedTime = 0.0f;
		//elapsedTime += deltaTime;
		//if (elapsedTime < 0.1f)
		//{
		//	return;
		//}

		// Ÿ�̸�.
		static Timer timer(0.1f);
		timer.Update(deltaTime);
		if (!timer.IsTimeOut())
		{
			return;
		}

		//Ŀ�� �̵� 
		Engine::Get().Draw(Vector2(0, 0), "Game Clear!", Color::Green);

		// �޽��� ���.
		Log("Game Clear!");

		// ������ ����.
		Sleep(2000);

		// ���� ���� ó��.
		Engine::Get().QuitGame();
	}
>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)
}


// void GameLevel::Update(float deltaTime)
// {
// 	Super::Update(deltaTime);
// 
// 	// ������ Ŭ���������, ���� ���� ó��.
// // 	if (isGameClear)
// // 	{
// // 		// �뷫 �� ������ ������ �ð� ���.
// // 		//static float elapsedTime = 0.0f;
// // 		//elapsedTime += deltaTime;
// // 		//if (elapsedTime < 0.1f)
// // 		//{
// // 		//	return;
// // 		//}
// // 
// // 		// Ÿ�̸�.
// // 		static Timer timer(0.1f);
// // 		timer.Update(deltaTime);
// // 		if (!timer.IsTimeOut())
// // 		{
// // 			return;
// // 		}
// // 
// // 		//Ŀ�� �̵� 
// // 		Engine::Get().Draw(Vector2(0, 0), "Game Clear!", Color::GREEN);
// // 
// // 		// �޽��� ���.
// // 		Log("Game Clear!");
// // 
// // 		// ������ ����.
// // 		Sleep(2000);
// // 
// // 		// ���� ���� ó��.
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
	// �� �׸���.
	for (auto* actor : map)
	{
		// �÷��̾� ��ġ Ȯ��.
		if (actor->Position() == player->Position())
		{
			continue;
		}

		// �ڽ� ��ġ Ȯ��.
		bool shouldDraw = true;
		for (auto* box : boxes)
		{
			if (actor->Position() == box->Position())
			{
				shouldDraw = false;
				break;
			}
		}

		// �� ���� �׸���.
		if (shouldDraw)
		{
			actor->Draw();
		}
	}

	// Ÿ�� �׸���.
	for (auto* target : targets)
	{
		// �÷��̾� ��ġ Ȯ��.
		if (target->Position() == player->Position())
		{
			continue;
		}

		// �ڽ� ��ġ Ȯ��.
		bool shouldDraw = true;
		for (auto* box : boxes)
		{
			if (target->Position() == box->Position())
			{
				shouldDraw = false;
				break;
			}
		}

		// Ÿ�� ���� �׸���.
		if (shouldDraw)
		{
			target->Draw();
		}
	}

	// �ڽ� �׸���.
	for (auto* box : boxes)
	{
		box->Draw();
	}

	// �÷��̾� �׸���.
	player->Draw();
>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)
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
	// �ڽ� �˻�.
	Road* searchedBox = nullptr;
	for (auto* box : boxes)
	{
		if (box->Position() == position)
		{
			searchedBox = box;
			break;
>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)
		}
	}
<<<<<<< HEAD
	Engine::Get().setColor((int)Color::WHITE, (int)Color::BLACK);
}

void GameLevel::entityRender(const Vector2& pos)
{
	cout << GET_SINGLETON(MapManager)->getCell(pos)->renderString;
=======

	// �ڽ��� ���� �� ó��.
	if (searchedBox)
	{
		// �̵� ����.
		int directionX = position.x - player->Position().x;
		int directionY = position.y - player->Position().y;

		// �ڽ��� �̵��� �� ��ġ.
		Vector2 newPosition 
			= searchedBox->Position() + Vector2(directionX, directionY);

		// �߰� �˻� (�ڽ�).
		for (auto* box : boxes)
		{
			// ���� ó��.
			if (box == searchedBox)
			{
				continue;
			}

			// �̵��� ��ġ�� �ٸ� �ڽ��� �ִٸ� �̵� �Ұ�.
			if (box->Position() == newPosition)
			{
				return false;
			}
		}

		// �߰� �˻� (��).
		for (auto* actor : map)
		{
			// �̵��Ϸ��� ��ġ�� �ִ� ���� �˻�.
			if (actor->Position() == newPosition)
			{
				// ����ȯ�� ���� ��ü�� Ÿ�� Ȯ��.

				// �̵��Ϸ��� ��ġ�� ���� ������ �̵� �Ұ�.
				if (actor->As<Wall>())
				{
					return false;
				}

				// ���̳� Ÿ���̸� �̵� ����.
				if (actor->As<Place>() || actor->As<House>())
				{
					// �ڽ� �̵� ó��.
					searchedBox->SetPosition(newPosition);

					// ���� Ŭ���� ���� Ȯ��.
					isGameClear = CheckGameClear();

					return true;
				}
			}
		}
	}

	// �̵��Ϸ��� ��ġ�� ���� �ִ��� Ȯ��.
	DrawableActor* searchedActor = nullptr;

	// ���� �̵��Ϸ��� ��ġ�� ���� ã��.
	for (auto* actor : map)
	{
		if (actor->Position() == position)
		{
			searchedActor = actor;
			break;
		}
	}

	// �˻��� ���Ͱ� ������ Ȯ��.
	if (searchedActor->As<Wall>())
	{
		return false;
	}

	// �˻��� ���Ͱ� �̵� ������ ����(��/Ÿ��)���� Ȯ��.
	if (searchedActor->As<Place>()
		|| searchedActor->As<House>())
	{
		return true;
	}

	return false;
>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)
}

void GameLevel::uiRender()
{
<<<<<<< HEAD
	Engine::Get().gotoxy(1, 1);
	cout << "���� ü�� : ";
	for (int i = 0; i < GET_SINGLETON(Player)->getHP(); i++)
	{
		cout << "��";
	}
	cout << "   ";

	Engine::Get().gotoxy(1, 2);
	cout << "��� : " << GET_SINGLETON(Player)->getGold();
}
=======
	// ���� Ȯ���� ���� ����.
	int currentScore = 0;
	int targetScore = targets.Size();

	// Ÿ�� ��ġ�� ��ġ�� �ڽ� ���� ����.
	for (auto* box : boxes)
	{
		for (auto* target : targets)
		{
			// ���� Ȯ��.
			if (box->Position() == target->Position())
			{
				++currentScore;
				break;
			}
		}
	}

	// ȹ���� ������ ��ǥ ������ ������ ��.
	return currentScore == targetScore;
}
>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)
