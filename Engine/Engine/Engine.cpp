#include "PreCompiledHeader.h"

#include "Engine.h"
#include <Windows.h>
#include <iostream>

#include "Level/Level.h"
#include "Actor/Actor.h"

#include <time.h>

#include "Render/ScreenBuffer.h"

// ÄÜ¼Ö Ã¢ ¸Þ½ÃÁö ÄÝ¹é ÇÔ¼ö.
BOOL WINAPI MessageProcessor(DWORD message)
{
	switch (message)
	{
	case CTRL_CLOSE_EVENT:
		Engine::Get().QuitGame();
		return true;

	default:
		return false;
	}
}

<<<<<<< HEAD

=======
>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)
// ½ºÅÂÆ½ º¯¼ö ÃÊ±âÈ­.
Engine* Engine::instance = nullptr;

Engine::Engine()
	: quit(false), mainLevel(nullptr), screenSize(31, 20)
{
	// ·£´ý ½Ãµå ¼³Á¤.
	srand((unsigned int)time(nullptr));

	// ½Ì±ÛÅæ °´Ã¼ ¼³Á¤.
	instance = this;

	// ±âº» Å¸°Ù ÇÁ·¹ÀÓ ¼Óµµ ¼³Á¤.
	SetTargetFrameRate(60.0f);

	// È­¸é ¹öÆÛ ÃÊ±âÈ­.
	// 1. ¹öÆÛ Å©±â ÇÒ´ç.
	imageBuffer = new CHAR_INFO[(screenSize.x + 1) * screenSize.y + 1];

	// ¹öÆÛ ÃÊ±âÈ­.
	ClearImageBuffer();

	// µÎ °³ÀÇ ¹öÆÛ »ý¼º (¹öÆÛ¸¦ ¹ø°¥¾Æ »ç¿ëÇÏ±â À§ÇØ-´õºí ¹öÆÛ¸µ).
	COORD size = { (short)screenSize.x, (short)screenSize.y };
	renderTargets[0] = new ScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE), size);
	renderTargets[1] = new ScreenBuffer(size);

	


	// ½º¿Ò ¹öÆÛ.
	Present();

	// ÄÜ¼Ö Ã¢ ÀÌº¥Æ® ÄÝ¹é ÇÔ¼ö µî·Ï.
	SetConsoleCtrlHandler(MessageProcessor, true);
	//ÄÜ¼Ö»çÀÌÁî/ ÆùÆ® Á¹·ù ±½±â Å©±âµî °áÁ¤ ÇÔ¼ö
	SetupConsole();

<<<<<<< HEAD

=======
>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)
}

Engine::~Engine()
{
	// ¸ÞÀÎ ·¹º§ ¸Þ¸ð¸® ÇØÁ¦.
	if (mainLevel != nullptr)
	{
		delete mainLevel;
	}

	// Å¬¸®¾î ¹öÆÛ »èÁ¦.
	delete[] imageBuffer;

	// È­¸é ¹öÆÛ »èÁ¦.
	delete renderTargets[0];
	delete renderTargets[1];
}

void Engine::Run()
{
	// ½ÃÀÛ Å¸ÀÓ ½ºÅÆÇÁ ÀúÀå.
	// timeGetTime ÇÔ¼ö´Â ¹Ð¸®¼¼ÄÁµå(1/1000ÃÊ) ´ÜÀ§.
	//unsigned long currentTime = timeGetTime();
	//unsigned long previousTime = 0;

	// CPU ½Ã°è »ç¿ë.
	// ½Ã½ºÅÛ ½Ã°è -> °íÇØ»óµµ Ä«¿îÅÍ. (10000000).
	// ¸ÞÀÎº¸µå¿¡ ½Ã°è°¡ ÀÖÀ½.
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	//std::cout << "Frequency: " << frequency.QuadPart << "\n";

	// ½ÃÀÛ ½Ã°£ ¹× ÀÌÀü ½Ã°£À» À§ÇÑ º¯¼ö.
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);

	int64_t currentTime = time.QuadPart;
	int64_t previousTime = currentTime;

	// ÇÁ·¹ÀÓ Á¦ÇÑ.
	//float targetFrameRate = 90.0f;

	// ÇÑ ÇÁ·¹ÀÓ ½Ã°£ °è»ê.
	//float targetOneFrameTime = 1.0f / targetFrameRate;

	// Game-Loop.
	while (true)
	{
		// Á¾·á Á¶°Ç.
		if (quit)
		{
			break;
		}

		// ÇöÀç ÇÁ·¹ÀÓ ½Ã°£ ÀúÀå.
		//time = timeGetTime();
		QueryPerformanceCounter(&time);
		currentTime = time.QuadPart;

		// ÇÁ·¹ÀÓ ½Ã°£ °è»ê.
		float deltaTime = static_cast<float>(currentTime - previousTime) /
			static_cast<float>(frequency.QuadPart);


		// ÇÁ·¹ÀÓ È®ÀÎ.
		if (deltaTime >= targetOneFrameTime)
		{
			// ÀÔ·Â Ã³¸® (ÇöÀç Å°ÀÇ ´­¸² »óÅÂ È®ÀÎ).
			ProcessInput();

			// ¾÷µ¥ÀÌÆ® °¡´ÉÇÑ »óÅÂ¿¡¼­¸¸ ÇÁ·¹ÀÓ ¾÷µ¥ÀÌÆ® Ã³¸®.
			if (shouldUpdate)
			{
				Update(deltaTime);
				Draw();
			}

			// Å° »óÅÂ ÀúÀå.
			SavePreviouseKeyStates();

			// ÀÌÀü ÇÁ·¹ÀÓ ½Ã°£ ÀúÀå.
			previousTime = currentTime;

			// ¾×ÅÍ Á¤¸® (»èÁ¦ ¿äÃ»µÈ ¾×ÅÍµé Á¤¸®).
			if (mainLevel)
			{
				//mainLevel->DestroyActor();
				mainLevel->ProcessAddedAndDestroyedActor();
			}

			// ÇÁ·¹ÀÓ È°¼ºÈ­.
			shouldUpdate = true;
		}
	}
}

void Engine::LoadLevel(Level* newLevel)
{
	// ±âÁ¸ ·¹º§ÀÌ ÀÖ´Ù¸é »èÁ¦ ÈÄ ±³Ã¼.

	// ¸ÞÀÎ ·¹º§ ¼³Á¤.
	mainLevel = newLevel;
}

void Engine::AddActor(Actor* newActor)
{
	// ¿¹¿Ü Ã³¸®.
	if (mainLevel == nullptr)
	{
		return;
	}

	// ·¹º§¿¡ ¾×ÅÍ Ãß°¡.
	shouldUpdate = false;
	mainLevel->AddActor(newActor);
}

void Engine::DestroyActor(Actor* targetActor)
{
	// ¿¹¿Ü Ã³¸®.
	if (mainLevel == nullptr)
	{
		return;
	}

	// ·¹º§¿¡ ¾×ÅÍ Ãß°¡.
	shouldUpdate = false;
	targetActor->Destroy();
}

void Engine::SetCursorType(CursorType cursorType)
{
	GetRenderer()->SetCursorType(cursorType);
}



//void Engine::SetCursorPosition(const Vector2& position)
//{
//	SetCursorPosition(position.x, position.y);
//}
//
//void Engine::SetCursorPosition(int x, int y)
//{
//	GetRenderer()->SetCursorPosition(x, y);
//}

void Engine::Draw(const Vector2& position, const char* image, Color color)
{
	int index = (position.y * (screenSize.x)) + position.x;
	if (index < 0 || index >= (screenSize.x + 1) * screenSize.y) {
		// ¹üÀ§¸¦ ÃÊ°úÇÏ¸é ±×¸®Áö ¾ÊÀ½
		return;
	}
	for (int ix = 0; ix < (int)strlen(image); ++ix) {
		int index = (position.y * (screenSize.x)) + position.x + ix;
		imageBuffer[index].Char.AsciiChar = image[ix];
<<<<<<< HEAD
		imageBuffer[index].Attributes = (unsigned int)color;
=======
		imageBuffer[index].Attributes = (unsigned long)color;
>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)
	}
}

// void Engine::Draw(const Vector2& position, const char* image, Color foreground, Color background)
// {
// 	// ¹®ÀÚ¿­ ±æÀÌ
// 	size_t len = strlen(image);
// 
// 	for (size_t ix = 0; ix < len; ++ix)
// 	{
// 		int index = (position.y * screenSize.x) + position.x + ix;
// 		// ¹®ÀÚ
// 		imageBuffer[index].Char.AsciiChar = image[ix];
// 		// Àü°æ»ö + ¹è°æ»öÀ» ÇÕÃÄ¼­ ¼Ó¼ºÀ¸·Î ¼³Á¤
// 		unsigned short attr = (unsigned short)foreground | (unsigned short)background;
// 		imageBuffer[index].Attributes = attr;
// 	}
// }

void Engine::SetTargetFrameRate(float targetFrameRate)
{
	this->targetFrameRate = targetFrameRate;
	targetOneFrameTime = 1.0f / targetFrameRate;
}

bool Engine::GetKey(int key)
{
	return keyState[key].isKeyDown;
}

bool Engine::GetKeyDown(int key)
{
	return keyState[key].isKeyDown && !keyState[key].wasKeyDown;
}

bool Engine::GetKeyUp(int key)
{
	return !keyState[key].isKeyDown && keyState[key].wasKeyDown;
}

void Engine::QuitGame()
{
	// Á¾·á ÇÃ·¡±× ¼³Á¤.
	quit = true;
}

Engine& Engine::Get()
{
	// ½Ì±ÛÅæ °´Ã¼ ¹ÝÈ¯.
	return *instance;
}

void Engine::SetupConsole()
{
	// 1) ÄÜ¼ÖÀÇ ¿­(cols), Çà(lines) Å©°Ô Àâ±â
	   //    ¿¹: °¡·Î 160, ¼¼·Î 50 (¸ÊÀÌ ´õ Å« °æ¿ì ÀûÀýÈ÷ ´Ã¸®¼¼¿ä)
<<<<<<< HEAD
	system("mode con cols=160 lines=50");
=======
	system("mode con cols=40 lines=40");
>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)

	// 2) ÄÜ¼Ö ÆùÆ® Å©±â ÁÙÀÌ±â(ÇÈ¼¿ ´ÜÀ§)
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 8;  // ±ÛÀÚ Æø (ÇÈ¼¿)
	cfi.dwFontSize.Y = 8;  // ±ÛÀÚ ³ôÀÌ (ÇÈ¼¿)
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	// ÆùÆ® ÀÌ¸§, ¿¹: "Consolas", "ÇÑ±Û ¸ÞÀÌÇÃ½ºÅä¸®" µî
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	// 3) ÄÜ¼Ö Ã¢ ÃÖ´ëÈ­ (È¤Àº ¿øÇÏ´Â Å©±â·Î ÀÌµ¿)
	//    - ±×³É È­¸é °¡µæ Ã¤¿ì·Á¸é SW_MAXIMIZE
// 	HWND hWnd = GetConsoleWindow();
// 	ShowWindow(hWnd, SW_MAXIMIZE);
}

<<<<<<< HEAD
void Engine::lockDragAndClick()
{
	DWORD consoleModePrev;
	HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(handle, &consoleModePrev);
	SetConsoleMode(handle, consoleModePrev & ~ENABLE_QUICK_EDIT_MODE);

}

void Engine::lockConsoleScroll()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hConsole == INVALID_HANDLE_VALUE) return;

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;

	SMALL_RECT windowSize = csbi.srWindow;
	COORD bufferSize = { windowSize.Right - windowSize.Left + 1, windowSize.Bottom - windowSize.Top + 1 };

	SetConsoleScreenBufferSize(hConsole, bufferSize);

}

BOOL Engine::gotoxy(int x, int y)
{
	COORD cursor = { x,y };
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

BOOL Engine::gotoxy(const Vector2& pos)
{
	// ¸í½ÃÀû Çü º¯È¯À¸·Î µ¥ÀÌÅÍ ¼Õ½Ç °æ°í ÇØ°á
	COORD cursor = { pos.x,pos.y };
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

void Engine::setColor(int txtColor, int bgColor)
{
	// ÄÜ¼Ö »ö»ó ¼³Á¤
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | txtColor);
}

void Engine::SetMap(Cell** mapData, int width, int height)
{
	map = mapData;
	mapWidth = width;
	mapHeight = height;
}


=======
>>>>>>> parent of b773401 (1-22/ ally attack í•˜ëŠ”ì¤‘ í™”ë©´ ì•ˆë‚˜ì˜´)
void Engine::ProcessInput()
{
	for (int ix = 0; ix < 255; ++ix)
	{
		keyState[ix].isKeyDown = (GetAsyncKeyState(ix) & 0x8000) ? true : false;
	}
}

void Engine::Update(float deltaTime)
{
	// ·¹º§ ¾÷µ¥ÀÌÆ®.
	if (mainLevel != nullptr)
	{
		mainLevel->Update(deltaTime);
	}
}

void Engine::Clear()
{
	ClearImageBuffer();
	GetRenderer()->Clear();
}

void Engine::Draw()
{
	Clear();  // È­¸é ÃÊ±âÈ­
	if (mainLevel != nullptr)
	{
		mainLevel->Draw();  // ÇöÀç ·¹º§ÀÇ ¸ðµç °´Ã¼¸¦ ±×¸³´Ï´Ù.
	}
	Present();  // ¹öÆÛ ±³È¯
}

void Engine::Present()
{
	// Swap Buffer.
	SetConsoleActiveScreenBuffer(GetRenderer()->buffer);
	currentRenderTargetIndex = 1 - currentRenderTargetIndex;
}

void Engine::SavePreviouseKeyStates()
{
	for (int ix = 0; ix < 255; ++ix)
	{
		keyState[ix].wasKeyDown = keyState[ix].isKeyDown;
	}
}
Vector2 Engine::getMousePos()
{
	Vector2 mousePos = Vector2();
	HWND consoleWindow = GetConsoleWindow();
	HDC hdc = GetDC(consoleWindow);

	RECT clientRect;
	GetClientRect(consoleWindow, &clientRect);
	POINT clientTopLeft = { clientRect.left, clientRect.top };
	ClientToScreen(consoleWindow, &clientTopLeft);

	CONSOLE_FONT_INFO fontInfo;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	if (!GetCurrentConsoleFont(hConsoleOutput, FALSE, &fontInfo)) {
// 		std::cerr << "Error: Failed to get current console font info." << std::endl;
		return Vector2(-1, -1); // ¿¹¿Ü »óÅÂ¸¦ ³ªÅ¸³»´Â °ª ¹ÝÈ¯
	}

	COORD fontSize = GetConsoleFontSize(hConsoleOutput, fontInfo.nFont);
	if (fontSize.X <= 0 || fontSize.Y <= 0) {
// 		std::cerr << "Error: GetConsoleFontSize failed or returned invalid values." << std::endl;
		return Vector2(-1, -1); // ¿¹¿Ü »óÅÂ¸¦ ³ªÅ¸³»´Â °ª ¹ÝÈ¯
	}

	POINT p;
	if (GetCursorPos(&p)) {
		ScreenToClient(consoleWindow, &p);

		int cellX = (p.x - clientRect.left) / fontSize.X;
		int cellY = (p.y - clientRect.top) / fontSize.Y;

		mousePos = Vector2(cellX, cellY);
	}

	return mousePos;
}
void Engine::setCursorVisible(bool vis, DWORD size)
{
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.bVisible = vis; // true : On, false : Off
	curInfo.dwSize = size; // Ä¿¼­ ±½±â (1~100)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}
void Engine::lockResize()
{
	HWND console = GetConsoleWindow();

	if (console != nullptr)
	{
		LONG style = GetWindowLong(console, GWL_STYLE);
		style &= ~WS_MAXIMIZEBOX & ~WS_SIZEBOX;
		SetWindowLong(console, GWL_STYLE, style);
	}
}
COORD Engine::getConsoleResolution()
{
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);

	short width = info.srWindow.Right - info.srWindow.Left + 1;
	short height = info.srWindow.Bottom - info.srWindow.Top + 1;


	return COORD{ width, height };
}


bool  Engine::getMouseInput()
{
	DWORD consoleModePrev;
	HANDLE hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
	GetConsoleMode(hConsoleInput, &consoleModePrev);
	DWORD consoleMode = consoleModePrev & ~ENABLE_QUICK_EDIT_MODE;
	consoleMode |= ENABLE_MOUSE_INPUT;
	SetConsoleMode(hConsoleInput, consoleMode);

	INPUT_RECORD inputRecord;
	DWORD events;

	if (PeekConsoleInput(hConsoleInput, &inputRecord, 1, &events) && events > 0)
	{
		ReadConsoleInput(hConsoleInput, &inputRecord, 1, &events);

		if (inputRecord.EventType == MOUSE_EVENT) {
			MOUSE_EVENT_RECORD mouseEvent = inputRecord.Event.MouseEvent;

			if (mouseEvent.dwEventFlags == 0)
			{
				return mouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED;
			}
		}
	}
	return false;
}

void Engine::ClearImageBuffer()
{
	// ¹öÆÛ µ¤¾î¾²±â.
	for (int y = 0; y < screenSize.y; ++y)
	{
		// ¹öÆÛ µ¤¾î¾²±â.
		for (int x = 0; x < screenSize.x + 1; ++x)
		{
			auto& buffer = imageBuffer[(y * (screenSize.x + 1)) + x];
			buffer.Char.AsciiChar = ' ';
			buffer.Attributes = 0;
		}

		// °¢ ÁÙ ³¡¿¡ °³Çà ¹®ÀÚ Ãß°¡.
		auto& buffer = imageBuffer[(y * (screenSize.x + 1)) + screenSize.x];
		buffer.Char.AsciiChar = '\n';
		buffer.Attributes = 0;
	}

	// ¸¶Áö¸·¿¡ ³Î ¹®ÀÚ Ãß°¡.
	auto& buffer = imageBuffer[(screenSize.x + 1) * screenSize.y];
	buffer.Char.AsciiChar = '\0';
	buffer.Attributes = 0;
}