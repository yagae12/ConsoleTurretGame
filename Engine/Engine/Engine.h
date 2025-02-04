#pragma once

#include "Core.h"
#include "Math/Vector2.h"
<<<<<<< HEAD
#include "Actor/Type.h"

=======
>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)

// �Է� ó���� ���� ����ü.
struct KeyState
{
	// ���� �����ӿ� Ű�� ���ȴ��� Ȯ��.
	bool isKeyDown = false;

	// ���� �����ӿ� Ű�� ���Ⱦ����� Ȯ��.
	bool wasKeyDown = false;
};

// ���� Ŭ����.
class Level;
class Actor;
class ScreenBuffer;
class ENGINE_API Engine
{
public:
	Engine();
	virtual ~Engine();

	// ���� ���� �Լ�.
	void Run();

	// ���� �߰� �Լ�.
	void LoadLevel(Level* newLevel);

	// ���� �߰�/���� �Լ�.
	void AddActor(Actor* newActor);
	void DestroyActor(Actor* targetActor);

	// ȭ�� ��ǥ ���� �Լ�.
	void SetCursorType(CursorType cursorType);
	//void SetCursorPosition(const Vector2& position);
	//void SetCursorPosition(int x, int y);

	void Draw(const Vector2& position, const char* image, Color color = Color::White);
// 	void Draw(const Vector2& position, const char* image, Color foreground, Color background);

	// ȭ�� ũ�� ��ȯ �Լ�.
	inline Vector2 ScreenSize() const { return screenSize; }

	// Ÿ�� ������ �ӵ� ���� �Լ�.
	void SetTargetFrameRate(float targetFrameRate);

	// �Է� ���� �Լ�.
	bool GetKey(int key);
	bool GetKeyDown(int key);
	bool GetKeyUp(int key);

	// ���� ���� �Լ�.
	void QuitGame();

	// �̱��� ��ü ���� �Լ�.
	static Engine& Get();

	//�ȼ�/ ��Ʈ ũ�� ����
	void SetupConsole();

<<<<<<< HEAD
	void lockDragAndClick();
	void lockConsoleScroll();


	BOOL gotoxy(int x, int y);
	BOOL gotoxy(const Vector2& pos);
	void setColor(int txtColor = 15, int bgColor = 0);

	float getDeltaTime() const { return deltaTime; } // deltaTime ��ȯ �Լ�

	//�� �����͸� �ʱ�ȭ�ϰų� ������Ʈ�� �� �ֵ��� �޼���
	void SetMap(Cell** mapData, int width, int height);
	Vector2 getMousePos();

	void setCursorVisible(bool vis, DWORD size);

	void lockResize();

	COORD getConsoleResolution();

	bool getMouseInput();

=======

>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)
protected:
	void ProcessInput();				// �Է� ó��.
	void Update(float deltaTime);		// Tick();

	void Clear();						// ȭ�� �����.
	void Draw();						// Render();
	void Present();

	// ���� �������� Ű ���¸� �����ϴ� �Լ�.
	void SavePreviouseKeyStates();


	inline ScreenBuffer* GetRenderer() const { return renderTargets[currentRenderTargetIndex]; }
	void ClearImageBuffer();

protected:

	// Ÿ�� ������ ����(�ʴ� ������).
	float targetFrameRate = 60.0f;

	// �� ������ �ð� ��(����: ��).
	float targetOneFrameTime = 0.0f;

	// ������ �� ������ ����.
	bool quit;

	// Ű ���¸� �����ϴ� �迭.
	KeyState keyState[255];

	// �̱��� ������ ���� ���� ���� ����.
	static Engine* instance;

	// ���� ���� ����.
	Level* mainLevel;

	// �������� ������Ʈ�ؾ� �ϴ��� ���θ� ��Ÿ���� ����.
	bool shouldUpdate = true;

	// ȭ�� ũ��.
	Vector2 screenSize;

	// ȭ�� ���� �� ����� ����(Buffer/Blob).
	CHAR_INFO* imageBuffer = nullptr;

	// ȭ�� ����.
	ScreenBuffer* renderTargets[2];
	int currentRenderTargetIndex = 0;
<<<<<<< HEAD

	private:
		float deltaTime = 0.0f; // deltaTime ���� ����
		Cell** map;           // 2D �迭 ������ �� ������
		int mapWidth, mapHeight; // �� ũ��
};

=======
};
>>>>>>> parent of b773401 (1-22/ ally attack 하는중 화면 안나옴)
