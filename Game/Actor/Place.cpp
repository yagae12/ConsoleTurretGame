#include "Place.h"

Place::Place(const Vector2& position)
	: DrawableActor(".")
{
	// ��ġ ����.
	this->position = position;

	// ���� ����.
	color = Color::Red;
}