#pragma once

class IScene;

class SceneManager
{
	std::map<int, IScene*> m_ScnMap;

	IScene* m_NowScene;
	IScene* m_NextScene;

	static SceneManager* Instance;
	SceneManager();
public:
	virtual ~SceneManager();
	static SceneManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new SceneManager;

		return Instance;
	}
	
	bool AddScene(IScene* Scn, int key_Value);
	
	IScene* GetNowScene();

	void ChangeScene(int Key_Value);
	void CheckChangeScene();

	void Clear();
};

