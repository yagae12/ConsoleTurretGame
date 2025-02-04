#pragma once

#include <Actor/DrawableActor.h>

class House : public DrawableActor
{
	RTTI_DECLARATIONS(House, DrawableActor)

public:
	House(const Vector2& position);
};