#include "House.h"

House::House(const Vector2& position)
	: DrawableActor("T")
{
	// 위치 설정.
	this->position = position;

	// 색상 설정.
	color = Color::Blue;
}