#pragma once

#include <Actor/DrawableActor.h>

// Ÿ���� ��ġ�Ҽ� �ִ� ���� ����.
class Place : public DrawableActor
{
	RTTI_DECLARATIONS(Place, DrawableActor)

public:
	Place(const Vector2& position);
};