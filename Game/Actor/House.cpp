#include "House.h"

House::House(const Vector2& position)
	: DrawableActor("T")
{
	// ��ġ ����.
	this->position = position;

	// ���� ����.
	color = Color::Blue;
}