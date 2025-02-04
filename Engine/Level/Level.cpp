#include "PreCompiledHeader.h"
#include "Level.h"
#include "Actor/Actor.h"

Level::Level()
{
}

Level::~Level()
{
}

void Level::AddActor(Actor* newActor)
{
	//actors.PushBack(newActor);
	addRequestedActor = newActor;
}

void Level::ProcessAddedAndDestroyedActor()
{
	// 액터 순회 후 삭제 요청된 액터를 처리.
	for (int ix = 0; ix < actors.Size();)
	{
		if (actors[ix]->isExpired)
		{
			delete actors[ix];
			actors[ix] = nullptr;
			actors.Erase(ix);
			continue;
		}

		++ix;
	}

	// 추가 요청된 액터 처리.
	if (addRequestedActor)
	{
		actors.PushBack(addRequestedActor);
		addRequestedActor = nullptr;
	}
}


void Level::Update(float deltaTime)
{
}

void Level::Draw()
{
}