#pragma once

#include "Core.h"
#include "Math/Vector2.h"
<<<<<<< HEAD
#include "Actor/Type.h"

=======
>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)

// ÀÔ·Â Ã³¸®¸¦ À§ÇÑ ±¸Á¶Ã¼.
struct KeyState
{
	// ÇöÀç ÇÁ·¹ÀÓ¿¡ Å°°¡ ´­·È´ÂÁö È®ÀÎ.
	bool isKeyDown = false;

	// ÀÌÀü ÇÁ·¹ÀÓ¿¡ Å°°¡ ´­·È¾ú´ÂÁö È®ÀÎ.
	bool wasKeyDown = false;
};

// ¿£Áø Å¬·¡½º.
class Level;
class Actor;
class ScreenBuffer;
class ENGINE_API Engine
{
public:
	Engine();
	virtual ~Engine();

	// ¿£Áø ½ÇÇà ÇÔ¼ö.
	void Run();

	// ·¹º§ Ãß°¡ ÇÔ¼ö.
	void LoadLevel(Level* newLevel);

	// ¾×ÅÍ Ãß°¡/»èÁ¦ ÇÔ¼ö.
	void AddActor(Actor* newActor);
	void DestroyActor(Actor* targetActor);

	// È­¸é ÁÂÇ¥ °ü·Ã ÇÔ¼ö.
	void SetCursorType(CursorType cursorType);
	//void SetCursorPosition(const Vector2& position);
	//void SetCursorPosition(int x, int y);

	void Draw(const Vector2& position, const char* image, Color color = Color::White);
// 	void Draw(const Vector2& position, const char* image, Color foreground, Color background);

	// È­¸é Å©±â ¹İÈ¯ ÇÔ¼ö.
	inline Vector2 ScreenSize() const { return screenSize; }

	// Å¸°Ù ÇÁ·¹ÀÓ ¼Óµµ ¼³Á¤ ÇÔ¼ö.
	void SetTargetFrameRate(float targetFrameRate);

	// ÀÔ·Â °ü·Ã ÇÔ¼ö.
	bool GetKey(int key);
	bool GetKeyDown(int key);
	bool GetKeyUp(int key);

	// ¿£Áø Á¾·á ÇÔ¼ö.
	void QuitGame();

	// ½Ì±ÛÅæ °´Ã¼ Á¢±Ù ÇÔ¼ö.
	static Engine& Get();

	//ÇÈ¼¿/ ÆùÆ® Å©±â ¼³Á¤
	void SetupConsole();

<<<<<<< HEAD
	void lockDragAndClick();
	void lockConsoleScroll();


	BOOL gotoxy(int x, int y);
	BOOL gotoxy(const Vector2& pos);
	void setColor(int txtColor = 15, int bgColor = 0);

	float getDeltaTime() const { return deltaTime; } // deltaTime ¹İÈ¯ ÇÔ¼ö

	//¸Ê µ¥ÀÌÅÍ¸¦ ÃÊ±âÈ­ÇÏ°Å³ª ¾÷µ¥ÀÌÆ®ÇÒ ¼ö ÀÖµµ·Ï ¸Ş¼­µå
	void SetMap(Cell** mapData, int width, int height);
	Vector2 getMousePos();

	void setCursorVisible(bool vis, DWORD size);

	void lockResize();

	COORD getConsoleResolution();

	bool getMouseInput();

=======

>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)
protected:
	void ProcessInput();				// ÀÔ·Â Ã³¸®.
	void Update(float deltaTime);		// Tick();

	void Clear();						// È­¸é Áö¿ì±â.
	void Draw();						// Render();
	void Present();

	// ÀÌÀü ÇÁ·¹ÀÓÀÇ Å° »óÅÂ¸¦ ÀúÀåÇÏ´Â ÇÔ¼ö.
	void SavePreviouseKeyStates();


	inline ScreenBuffer* GetRenderer() const { return renderTargets[currentRenderTargetIndex]; }
	void ClearImageBuffer();

protected:

	// Å¸°Ù ÇÁ·¹ÀÓ º¯¼ö(ÃÊ´ç ÇÁ·¹ÀÓ).
	float targetFrameRate = 60.0f;

	// ÇÑ ÇÁ·¹ÀÓ ½Ã°£ °ª(´ÜÀ§: ÃÊ).
	float targetOneFrameTime = 0.0f;

	// Á¾·áÇÒ ¶§ ¼³Á¤ÇÒ º¯¼ö.
	bool quit;

	// Å° »óÅÂ¸¦ ÀúÀåÇÏ´Â ¹è¿­.
	KeyState keyState[255];

	// ½Ì±ÛÅæ ±¸ÇöÀ» À§ÇÑ Àü¿ª º¯¼ö ¼±¾ğ.
	static Engine* instance;

	// ¸ŞÀÎ ·¹º§ º¯¼ö.
	Level* mainLevel;

	// ÇÁ·¹ÀÓÀ» ¾÷µ¥ÀÌÆ®ÇØ¾ß ÇÏ´ÂÁö ¿©ºÎ¸¦ ³ªÅ¸³»´Â º¯¼ö.
	bool shouldUpdate = true;

	// È­¸é Å©±â.
	Vector2 screenSize;

	// È­¸é Áö¿ï ¶§ »ç¿ëÇÒ ¹öÆÛ(Buffer/Blob).
	CHAR_INFO* imageBuffer = nullptr;

	// È­¸é ¹öÆÛ.
	ScreenBuffer* renderTargets[2];
	int currentRenderTargetIndex = 0;
<<<<<<< HEAD

	private:
		float deltaTime = 0.0f; // deltaTime ÀúÀå º¯¼ö
		Cell** map;           // 2D ¹è¿­ ÇüÅÂÀÇ ¸Ê µ¥ÀÌÅÍ
		int mapWidth, mapHeight; // ¸Ê Å©±â
};

=======
};
>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)
