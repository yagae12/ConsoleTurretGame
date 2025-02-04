#pragma once

#include <Actor/DrawableActor.h>

// 타워를 설치할수 있는 공간 액터.
class Place : public DrawableActor
{
	RTTI_DECLARATIONS(Place, DrawableActor)

public:
	Place(const Vector2& position);
};