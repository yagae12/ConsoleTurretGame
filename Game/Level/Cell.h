#pragma once

#include "PreCompiledHeader/PreCompiledHeader.h"
#include "Engine/Engine.h"
#include "Type.h"
#include "Define.h"
#include "Core.h"

class Cell
{
public:
	Cell();
	Cell(Color col, string str, MAP_TYPE type) : bgColor{ col }, renderString{ str }, type{ type } {};
public:
	MAP_TYPE type;
	Color bgColor = Color::BG_Green;
	Color charColor = Color::White;
	string renderString = "  ";
};