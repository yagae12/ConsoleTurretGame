#pragma once

#include <Actor/DrawableActor.h>

class Road : public DrawableActor
{
	RTTI_DECLARATIONS(Road, DrawableActor)

public:
	Road(const Vector2& position);
};