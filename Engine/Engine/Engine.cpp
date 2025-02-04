#include "PreCompiledHeader.h"

#include "Engine.h"
#include <Windows.h>
#include <iostream>

#include "Level/Level.h"
#include "Actor/Actor.h"

#include <time.h>

#include "Render/ScreenBuffer.h"

// �ܼ� â �޽��� �ݹ� �Լ�.
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
>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)
// ����ƽ ���� �ʱ�ȭ.
Engine* Engine::instance = nullptr;

Engine::Engine()
	: quit(false), mainLevel(nullptr), screenSize(31, 20)
{
	// ���� �õ� ����.
	srand((unsigned int)time(nullptr));

	// �̱��� ��ü ����.
	instance = this;

	// �⺻ Ÿ�� ������ �ӵ� ����.
	SetTargetFrameRate(60.0f);

	// ȭ�� ���� �ʱ�ȭ.
	// 1. ���� ũ�� �Ҵ�.
	imageBuffer = new CHAR_INFO[(screenSize.x + 1) * screenSize.y + 1];

	// ���� �ʱ�ȭ.
	ClearImageBuffer();

	// �� ���� ���� ���� (���۸� ������ ����ϱ� ����-���� ���۸�).
	COORD size = { (short)screenSize.x, (short)screenSize.y };
	renderTargets[0] = new ScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE), size);
	renderTargets[1] = new ScreenBuffer(size);

	


	// ���� ����.
	Present();

	// �ܼ� â �̺�Ʈ �ݹ� �Լ� ���.
	SetConsoleCtrlHandler(MessageProcessor, true);
	//�ֻܼ�����/ ��Ʈ ���� ���� ũ��� ���� �Լ�
	SetupConsole();

<<<<<<< HEAD

=======
>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)
}

Engine::~Engine()
{
	// ���� ���� �޸� ����.
	if (mainLevel != nullptr)
	{
		delete mainLevel;
	}

	// Ŭ���� ���� ����.
	delete[] imageBuffer;

	// ȭ�� ���� ����.
	delete renderTargets[0];
	delete renderTargets[1];
}

void Engine::Run()
{
	// ���� Ÿ�� ������ ����.
	// timeGetTime �Լ��� �и�������(1/1000��) ����.
	//unsigned long currentTime = timeGetTime();
	//unsigned long previousTime = 0;

	// CPU �ð� ���.
	// �ý��� �ð� -> ���ػ� ī����. (10000000).
	// ���κ��忡 �ð谡 ����.
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	//std::cout << "Frequency: " << frequency.QuadPart << "\n";

	// ���� �ð� �� ���� �ð��� ���� ����.
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);

	int64_t currentTime = time.QuadPart;
	int64_t previousTime = currentTime;

	// ������ ����.
	//float targetFrameRate = 90.0f;

	// �� ������ �ð� ���.
	//float targetOneFrameTime = 1.0f / targetFrameRate;

	// Game-Loop.
	while (true)
	{
		// ���� ����.
		if (quit)
		{
			break;
		}

		// ���� ������ �ð� ����.
		//time = timeGetTime();
		QueryPerformanceCounter(&time);
		currentTime = time.QuadPart;

		// ������ �ð� ���.
		float deltaTime = static_cast<float>(currentTime - previousTime) /
			static_cast<float>(frequency.QuadPart);


		// ������ Ȯ��.
		if (deltaTime >= targetOneFrameTime)
		{
			// �Է� ó�� (���� Ű�� ���� ���� Ȯ��).
			ProcessInput();

			// ������Ʈ ������ ���¿����� ������ ������Ʈ ó��.
			if (shouldUpdate)
			{
				Update(deltaTime);
				Draw();
			}

			// Ű ���� ����.
			SavePreviouseKeyStates();

			// ���� ������ �ð� ����.
			previousTime = currentTime;

			// ���� ���� (���� ��û�� ���͵� ����).
			if (mainLevel)
			{
				//mainLevel->DestroyActor();
				mainLevel->ProcessAddedAndDestroyedActor();
			}

			// ������ Ȱ��ȭ.
			shouldUpdate = true;
		}
	}
}

void Engine::LoadLevel(Level* newLevel)
{
	// ���� ������ �ִٸ� ���� �� ��ü.

	// ���� ���� ����.
	mainLevel = newLevel;
}

void Engine::AddActor(Actor* newActor)
{
	// ���� ó��.
	if (mainLevel == nullptr)
	{
		return;
	}

	// ������ ���� �߰�.
	shouldUpdate = false;
	mainLevel->AddActor(newActor);
}

void Engine::DestroyActor(Actor* targetActor)
{
	// ���� ó��.
	if (mainLevel == nullptr)
	{
		return;
	}

	// ������ ���� �߰�.
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
		// ������ �ʰ��ϸ� �׸��� ����
		return;
	}
	for (int ix = 0; ix < (int)strlen(image); ++ix) {
		int index = (position.y * (screenSize.x)) + position.x + ix;
		imageBuffer[index].Char.AsciiChar = image[ix];
<<<<<<< HEAD
		imageBuffer[index].Attributes = (unsigned int)color;
=======
		imageBuffer[index].Attributes = (unsigned long)color;
>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)
	}
}

// void Engine::Draw(const Vector2& position, const char* image, Color foreground, Color background)
// {
// 	// ���ڿ� ����
// 	size_t len = strlen(image);
// 
// 	for (size_t ix = 0; ix < len; ++ix)
// 	{
// 		int index = (position.y * screenSize.x) + position.x + ix;
// 		// ����
// 		imageBuffer[index].Char.AsciiChar = image[ix];
// 		// ����� + ������ ���ļ� �Ӽ����� ����
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
	// ���� �÷��� ����.
	quit = true;
}

Engine& Engine::Get()
{
	// �̱��� ��ü ��ȯ.
	return *instance;
}

void Engine::SetupConsole()
{
	// 1) �ܼ��� ��(cols), ��(lines) ũ�� ���
	   //    ��: ���� 160, ���� 50 (���� �� ū ��� ������ �ø�����)
<<<<<<< HEAD
	system("mode con cols=160 lines=50");
=======
	system("mode con cols=40 lines=40");
>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)

	// 2) �ܼ� ��Ʈ ũ�� ���̱�(�ȼ� ����)
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 8;  // ���� �� (�ȼ�)
	cfi.dwFontSize.Y = 8;  // ���� ���� (�ȼ�)
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	// ��Ʈ �̸�, ��: "Consolas", "�ѱ� �����ý��丮" ��
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	// 3) �ܼ� â �ִ�ȭ (Ȥ�� ���ϴ� ũ��� �̵�)
	//    - �׳� ȭ�� ���� ä����� SW_MAXIMIZE
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
	// ����� �� ��ȯ���� ������ �ս� ��� �ذ�
	COORD cursor = { pos.x,pos.y };
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

void Engine::setColor(int txtColor, int bgColor)
{
	// �ܼ� ���� ����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | txtColor);
}

void Engine::SetMap(Cell** mapData, int width, int height)
{
	map = mapData;
	mapWidth = width;
	mapHeight = height;
}


=======
>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)
void Engine::ProcessInput()
{
	for (int ix = 0; ix < 255; ++ix)
	{
		keyState[ix].isKeyDown = (GetAsyncKeyState(ix) & 0x8000) ? true : false;
	}
}

void Engine::Update(float deltaTime)
{
	// ���� ������Ʈ.
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
	Clear();  // ȭ�� �ʱ�ȭ
	if (mainLevel != nullptr)
	{
		mainLevel->Draw();  // ���� ������ ��� ��ü�� �׸��ϴ�.
	}
	Present();  // ���� ��ȯ
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
		return Vector2(-1, -1); // ���� ���¸� ��Ÿ���� �� ��ȯ
	}

	COORD fontSize = GetConsoleFontSize(hConsoleOutput, fontInfo.nFont);
	if (fontSize.X <= 0 || fontSize.Y <= 0) {
// 		std::cerr << "Error: GetConsoleFontSize failed or returned invalid values." << std::endl;
		return Vector2(-1, -1); // ���� ���¸� ��Ÿ���� �� ��ȯ
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
	curInfo.dwSize = size; // Ŀ�� ���� (1~100)
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
	// ���� �����.
	for (int y = 0; y < screenSize.y; ++y)
	{
		// ���� �����.
		for (int x = 0; x < screenSize.x + 1; ++x)
		{
			auto& buffer = imageBuffer[(y * (screenSize.x + 1)) + x];
			buffer.Char.AsciiChar = ' ';
			buffer.Attributes = 0;
		}

		// �� �� ���� ���� ���� �߰�.
		auto& buffer = imageBuffer[(y * (screenSize.x + 1)) + screenSize.x];
		buffer.Char.AsciiChar = '\n';
		buffer.Attributes = 0;
	}

	// �������� �� ���� �߰�.
	auto& buffer = imageBuffer[(screenSize.x + 1) * screenSize.y];
	buffer.Char.AsciiChar = '\0';
	buffer.Attributes = 0;
}