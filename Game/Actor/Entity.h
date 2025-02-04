#pragma once
#include "Math/Vector2.h"
#include "Define.h"
#include "Actor/Type.h"
#include <string>

class Entity
{
public:
	Entity();
	virtual ~Entity();
protected:
	clock_t _timer;
	Color _originColor;
	Color _color;
	ENTITY_TYPE _type;
	Vector2 _currentPos;
	string _renderString;
public:
	virtual void update();
	Color getColor() { return _color; }
	ENTITY_TYPE getType() { return _type; }
	Vector2 getPos() { return _currentPos; }
	string getRenderString() { return _renderString; }
	virtual void setPos(const Vector2& pos);
};