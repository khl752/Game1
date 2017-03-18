#include "stdafx.h"
#include "IScene.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager()
{
	m_NowScene	= nullptr;
	m_NextScene = nullptr;
}


SceneManager::~SceneManager()
{
	this->Clear();
}

bool	SceneManager::AddScene(IScene* Scn, int key_Value)
{
	if (m_ScnMap.insert(std::pair<int, IScene*>(key_Value, Scn)).second == false)
	{
		MessageBox(GetActiveWindow(), "Scene Create Failed", "Err", MB_OK);
		return false;
	}

	return true;
}

IScene* SceneManager::GetNowScene()
{
	return m_NowScene;
}

void	SceneManager::ChangeScene(int Key_Value)
{
	m_NextScene = m_ScnMap[Key_Value];

	if (m_NextScene == nullptr)
	{
		MessageBox(GetActiveWindow(), "NextScene Nullptr", "Err", MB_OK);
	}
}

void	SceneManager::CheckChangeScene()
{
	if (m_NextScene != nullptr)
	{
		m_NextScene->Init();

		if (m_NowScene != nullptr)
			m_NowScene->Close();

		m_NowScene = m_NextScene;

		m_NextScene = nullptr;
	}
}

void	SceneManager::Clear()
{
	for (auto it = m_ScnMap.begin(); it != m_ScnMap.end(); ++it)
	{
		(*it).second->Close();
		delete (*it).second;
	}

	m_ScnMap.clear();
}