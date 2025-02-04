#pragma once

enum class Color
{
	BLACK, BLUE, GREEN, SKYBLUE, RED,
	VOILET, YELLOW, LIGHT_GRAY, GRAY, LIGHT_BLUE,
	LIGHT_GREEN, MINT, LIGHT_RED, LIGHT_VIOLET,
	LIGHT_YELLOW, WHITE, END
};

enum class ENTITY_TYPE
{
	ALLY,
	ENEMY,
	TRAP,
	NONE
};

enum class ROAD_TYPE
{
	FIRST,
	SECOND,
	NONE
};



enum class MAP_TYPE
{
	Wall,
	Road,
	Place,
	House
};
enum class ALLY_TYPE
{
	ARCHER = 1,
	CROSSBOW = 2,
	BALLISTA,
	GUNSLINGER,
	FIRE_WIZARD,
	ICE_WIZARD,
	LIGHTNING_WIZARD,
	NECROMANCER,
	SWORD,
	SPEAR,
	SLAYER,
	GREATSWORD
};

enum class ENEMY_TYPE
{
	GOBLIN = 1,
	GOLDGOBLIN,
	OGRE,
	GOLEM,
	DRAGON,
	END
};
enum class TRAP_TYPE
{
	DEFAULT
};

enum class INGAMESCENE_STATE
{
	IDLE,
	SELECT,
	PLACE,
	BATTLE,
	REMOVE,
	ASK,
	NONE
};



// 커서의 종류를 설정할 때 사용할 열거형.
enum class CursorType
{
	NoCursor,
	SolidCursor,
	NormalCursor
};
