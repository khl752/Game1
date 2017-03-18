#pragma once
#include "IScene.h"

class GameObject;
class CInput;

class TestScene :
	public SceneObject
{
private:
	CInput* m_Input;
	std::vector<GameObject*> m_BackGrounds;
public:
	TestScene();
	virtual ~TestScene();

	virtual INT Init();
	virtual INT Update();
	virtual INT Render();
	virtual void Close();
};

