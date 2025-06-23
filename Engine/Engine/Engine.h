#pragma once

#include "Core.h"
#include "Math/Vector2.h"
#include "Actor/Type.h"

// 키 입력 상태를 저장하기 위한 구조체.
struct KeyState
{
        bool isKeyDown = false;
        bool wasKeyDown = false;
};

class Level;
class Actor;
class ScreenBuffer;
class ENGINE_API Engine
{
public:
        Engine();
        virtual ~Engine();

        void Run();
        void LoadLevel(Level* newLevel);
        void AddActor(Actor* newActor);
        void DestroyActor(Actor* targetActor);

        void SetCursorType(CursorType cursorType);
        void Draw(const Vector2& position, const char* image, Color color = Color::White);
        inline Vector2 ScreenSize() const { return screenSize; }
        void SetTargetFrameRate(float targetFrameRate);
        bool GetKey(int key);
        bool GetKeyDown(int key);
        bool GetKeyUp(int key);
        void QuitGame();
        static Engine& Get();
        void SetupConsole();

        void lockDragAndClick();
        void lockConsoleScroll();
        BOOL gotoxy(int x, int y);
        BOOL gotoxy(const Vector2& pos);
        void setColor(int txtColor = 15, int bgColor = 0);
        float getDeltaTime() const { return deltaTime; }
        void SetMap(Cell** mapData, int width, int height);
        Vector2 getMousePos();
        void setCursorVisible(bool vis, DWORD size);
        void lockResize();
        COORD getConsoleResolution();
        bool getMouseInput();

protected:
        void ProcessInput();
        void Update(float deltaTime);
        void Clear();
        void Draw();
        void Present();
        void SavePreviouseKeyStates();

        inline ScreenBuffer* GetRenderer() const { return renderTargets[currentRenderTargetIndex]; }
        void ClearImageBuffer();

protected:
        float targetFrameRate = 60.0f;
        float targetOneFrameTime = 0.0f;
        bool quit;
        KeyState keyState[255];
        static Engine* instance;
        Level* mainLevel;
        bool shouldUpdate = true;
        Vector2 screenSize;
        CHAR_INFO* imageBuffer = nullptr;
        ScreenBuffer* renderTargets[2];
        int currentRenderTargetIndex = 0;

private:
        float deltaTime = 0.0f;
        Cell** map;
        int mapWidth, mapHeight;
};
