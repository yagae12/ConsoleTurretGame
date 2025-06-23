#include "PreCompiledHeader.h"

#include "Engine.h"
#include <Windows.h>
#include <iostream>

#include "Level/Level.h"
#include "Actor/Actor.h"

#include <time.h>

#include "Render/ScreenBuffer.h"


	default:
		return false;
	}
}

<<<<<<< HEAD

=======
>>>>>>> parent of b773401 (1-22/ ally attack 頃橂姅欷� 頇旊┐ 鞎堧倶鞓�)
// 胶怕平 函荐 檬扁拳.
Engine* Engine::instance = nullptr;

Engine::Engine()
	: quit(false), mainLevel(nullptr), screenSize(31, 20)
{
	// 罚待 矫靛 汲沥.
	srand((unsigned int)time(nullptr));

	// 教臂沛 按眉 汲沥.
	instance = this;

	// 扁夯 鸥百 橇饭烙 加档 汲沥.
	SetTargetFrameRate(60.0f);

	// 拳搁 滚欺 檬扁拳.
	// 1. 滚欺 农扁 且寸.
	imageBuffer = new CHAR_INFO[(screenSize.x + 1) * screenSize.y + 1];

	// 滚欺 檬扁拳.
	ClearImageBuffer();

	// 滴 俺狼 滚欺 积己 (滚欺甫 锅哎酒 荤侩窍扁 困秦-歹喉 滚欺傅).
	COORD size = { (short)screenSize.x, (short)screenSize.y };
	renderTargets[0] = new ScreenBuffer(GetStdHandle(STD_OUTPUT_HANDLE), size);
	renderTargets[1] = new ScreenBuffer(size);

	


	// 胶恳 滚欺.
	Present();

	// 能贾 芒 捞亥飘 妮归 窃荐 殿废.
	SetConsoleCtrlHandler(MessageProcessor, true);
	//能贾荤捞令/ 迄飘 凉幅 苯扁 农扁殿 搬沥 窃荐
	SetupConsole();

<<<<<<< HEAD

=======
>>>>>>> parent of b773401 (1-22/ ally attack 頃橂姅欷� 頇旊┐ 鞎堧倶鞓�)
}

Engine::~Engine()
{
	// 皋牢 饭骇 皋葛府 秦力.
	if (mainLevel != nullptr)
	{
		delete mainLevel;
	}

	// 努府绢 滚欺 昏力.
	delete[] imageBuffer;

	// 拳搁 滚欺 昏力.
	delete renderTargets[0];
	delete renderTargets[1];
}

void Engine::Run()
{
	// 矫累 鸥烙 胶牌橇 历厘.
	// timeGetTime 窃荐绰 剐府技牧靛(1/1000檬) 窜困.
	//unsigned long currentTime = timeGetTime();
	//unsigned long previousTime = 0;

	// CPU 矫拌 荤侩.
	// 矫胶袍 矫拌 -> 绊秦惑档 墨款磐. (10000000).
	// 皋牢焊靛俊 矫拌啊 乐澜.
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	//std::cout << "Frequency: " << frequency.QuadPart << "\n";

	// 矫累 矫埃 棺 捞傈 矫埃阑 困茄 函荐.
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);

	int64_t currentTime = time.QuadPart;
	int64_t previousTime = currentTime;

	// 橇饭烙 力茄.
	//float targetFrameRate = 90.0f;

	// 茄 橇饭烙 矫埃 拌魂.
	//float targetOneFrameTime = 1.0f / targetFrameRate;

	// Game-Loop.
	while (true)
	{
		// 辆丰 炼扒.
		if (quit)
		{
			break;
		}

		// 泅犁 橇饭烙 矫埃 历厘.
		//time = timeGetTime();
		QueryPerformanceCounter(&time);
		currentTime = time.QuadPart;

		// 橇饭烙 矫埃 拌魂.
		float deltaTime = static_cast<float>(currentTime - previousTime) /
			static_cast<float>(frequency.QuadPart);


		// 橇饭烙 犬牢.
		if (deltaTime >= targetOneFrameTime)
		{
			// 涝仿 贸府 (泅犁 虐狼 喘覆 惑怕 犬牢).
			ProcessInput();

			// 诀单捞飘 啊瓷茄 惑怕俊辑父 橇饭烙 诀单捞飘 贸府.
			if (shouldUpdate)
			{
				Update(deltaTime);
				Draw();
			}

			// 虐 惑怕 历厘.
			SavePreviouseKeyStates();

			// 捞傈 橇饭烙 矫埃 历厘.
			previousTime = currentTime;

			// 咀磐 沥府 (昏力 夸没等 咀磐甸 沥府).
			if (mainLevel)
			{
				//mainLevel->DestroyActor();
				mainLevel->ProcessAddedAndDestroyedActor();
			}

			// 橇饭烙 劝己拳.
			shouldUpdate = true;
		}
	}
}

void Engine::LoadLevel(Level* newLevel)
{
	// 扁粮 饭骇捞 乐促搁 昏力 饶 背眉.

	// 皋牢 饭骇 汲沥.
	mainLevel = newLevel;
}

void Engine::AddActor(Actor* newActor)
{
	// 抗寇 贸府.
	if (mainLevel == nullptr)
	{
		return;
	}

	// 饭骇俊 咀磐 眠啊.
	shouldUpdate = false;
	mainLevel->AddActor(newActor);
}

void Engine::DestroyActor(Actor* targetActor)
{
	// 抗寇 贸府.
	if (mainLevel == nullptr)
	{
		return;
	}

	// 饭骇俊 咀磐 眠啊.
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
		int index = (position.y * (screenSize.x)) + position.x + ix;
		imageBuffer[index].Char.AsciiChar = image[ix];
<<<<<<< HEAD
		imageBuffer[index].Attributes = (unsigned int)color;
=======
		imageBuffer[index].Attributes = (unsigned long)color;
>>>>>>> parent of b773401 (1-22/ ally attack 頃橂姅欷� 頇旊┐ 鞎堧倶鞓�)
	}
}

// void Engine::Draw(const Vector2& position, const char* image, Color foreground, Color background)
// {
// 	// 巩磊凯 辨捞
// 	size_t len = strlen(image);
// 
// 	for (size_t ix = 0; ix < len; ++ix)
// 	{
// 		int index = (position.y * screenSize.x) + position.x + ix;
// 		// 巩磊
// 		imageBuffer[index].Char.AsciiChar = image[ix];
// 		// 傈版祸 + 硅版祸阑 钦媚辑 加己栏肺 汲沥
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

{
	// 教臂沛 按眉 馆券.
	return *instance;
}

void Engine::SetupConsole()
{
	// 1) 能贾狼 凯(cols), 青(lines) 农霸 棱扁
	   //    抗: 啊肺 160, 技肺 50 (甘捞 歹 奴 版快 利例洒 疵府技夸)
<<<<<<< HEAD
	system("mode con cols=160 lines=50");
=======
	system("mode con cols=40 lines=40");
>>>>>>> parent of b773401 (1-22/ ally attack 頃橂姅欷� 頇旊┐ 鞎堧倶鞓�)

	// 2) 能贾 迄飘 农扁 临捞扁(侨伎 窜困)
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 8;  // 臂磊 气 (侨伎)
	cfi.dwFontSize.Y = 8;  // 臂磊 臭捞 (侨伎)
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	// 迄飘 捞抚, 抗: "Consolas", "茄臂 皋捞敲胶配府" 殿
	wcscpy_s(cfi.FaceName, L"Consolas");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	// 3) 能贾 芒 弥措拳 (趣篮 盔窍绰 农扁肺 捞悼)
	//    - 弊成 拳搁 啊垫 盲快妨搁 SW_MAXIMIZE
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
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor);
}

void Engine::setColor(int txtColor, int bgColor)
{
	// 能贾 祸惑 汲沥
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | txtColor);
}

void Engine::SetMap(Cell** mapData, int width, int height)
{
	map = mapData;
	mapWidth = width;
	mapHeight = height;
}


=======
>>>>>>> parent of b773401 (1-22/ ally attack 頃橂姅欷� 頇旊┐ 鞎堧倶鞓�)
void Engine::ProcessInput()
{
	for (int ix = 0; ix < 255; ++ix)
	{
		keyState[ix].isKeyDown = (GetAsyncKeyState(ix) & 0x8000) ? true : false;
	}
}

void Engine::Update(float deltaTime)
{
	// 饭骇 诀单捞飘.
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
	Clear();  // 拳搁 檬扁拳
	if (mainLevel != nullptr)
	{
		mainLevel->Draw();  // 泅犁 饭骇狼 葛电 按眉甫 弊赋聪促.
	}
	Present();  // 滚欺 背券
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
		return Vector2(-1, -1); // 抗寇 惑怕甫 唱鸥郴绰 蔼 馆券
	}

	COORD fontSize = GetConsoleFontSize(hConsoleOutput, fontInfo.nFont);
	if (fontSize.X <= 0 || fontSize.Y <= 0) {
// 		std::cerr << "Error: GetConsoleFontSize failed or returned invalid values." << std::endl;
		return Vector2(-1, -1); // 抗寇 惑怕甫 唱鸥郴绰 蔼 馆券
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
	curInfo.dwSize = size; // 目辑 苯扁 (1~100)
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
	// 滚欺 丹绢静扁.
	for (int y = 0; y < screenSize.y; ++y)
	{
		// 滚欺 丹绢静扁.
		for (int x = 0; x < screenSize.x + 1; ++x)
		{
			auto& buffer = imageBuffer[(y * (screenSize.x + 1)) + x];
			buffer.Char.AsciiChar = ' ';
			buffer.Attributes = 0;
		}

		// 阿 临 场俊 俺青 巩磊 眠啊.
		auto& buffer = imageBuffer[(y * (screenSize.x + 1)) + screenSize.x];
		buffer.Char.AsciiChar = '\n';
		buffer.Attributes = 0;
	}

	// 付瘤阜俊 澄 巩磊 眠啊.
	auto& buffer = imageBuffer[(screenSize.x + 1) * screenSize.y];
	buffer.Char.AsciiChar = '\0';
	buffer.Attributes = 0;
}