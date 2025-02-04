#include "Cell.h"
#include<algorithm>

Cell::Cell()
{
	bgColor = Color::BLACK;
	renderString = "  ";
}

void Cell::registerEntity(Entity* entity)
{
	entityVec.push_back(entity);
	renderString = entity->getRenderString();
	charColor = entity->getColor();
}

void Cell::deregisterEntity(Entity* entity)
{
	auto it = find(entityVec.begin(), entityVec.end(), entity);
	if (it != entityVec.end())
	{
		entityVec.erase(it);
		renderString = "  ";
		charColor = Color::WHITE;
		if (entityVec.size() != 0)
		{
			renderString = entityVec.back()->getRenderString();
			charColor = entityVec.back()->getColor();
		}
	}
}

void Cell::setRenderString(const string& str)
{
	renderString = str;
}

void Cell::setBGColor(Color color)
{
	bgColor = color;
}