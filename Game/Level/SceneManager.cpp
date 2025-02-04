#include<string>
#include "SceneManager.h"
#include "Define.h"
#include <Windows.h>
SceneManager* SceneManager::m_pInst = nullptr;

void SceneManager::registerScene(const string& sceneName, Scene* scene)
{
	_sceneMap.insert({ sceneName, scene });
}
void SceneManager::loadScene(const string& sceneName)
{
	system("cls");
	auto iter = _sceneMap.find(sceneName);
	if (iter != _sceneMap.end())
	{
		_pActiveScene = iter->second;
		_pActiveScene->init();
	}
}

void SceneManager::init()
{
	_pActiveScene = nullptr;
}
void SceneManager::update()
{
	if (_pActiveScene)
	{
		_pActiveScene->update();
	}
	else
	{
		// Handle the case where _pActiveScene is null
		std::cerr << "Error: _pActiveScene is null" << std::endl;
	}
}

void SceneManager::draw()
{
	if (_pActiveScene)
	{
		_pActiveScene->Draw();
	}
	else
	{
		std::cerr << "Error: _pActiveScene is null" << std::endl;
	}
}
