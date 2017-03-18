#pragma once
#include "stdafx.h"
#include "ObjectManager.h"
#include "GameObject.h"

class IScene
{
public:
	IScene();
	virtual ~IScene();

	virtual void AddObject(GameObject*) = 0;
	virtual GameObject* PopObject(GameObject*, PopState pop_state = PS_REMOVE) = 0;

	virtual INT Init()		= 0;
	virtual INT Render()	= 0;
	virtual INT Update()	= 0;
	virtual void Close()	= 0;
};

class SceneObject
	: public IScene
{
public:
	ObjectManager m_ObjectManager;
public:
	SceneObject();
	virtual ~SceneObject();

	virtual void AddObject(GameObject*) final;
	virtual GameObject* PopObject(GameObject*, PopState pop_state = PS_REMOVE) final;
	virtual INT Init();
	virtual INT Render();
	virtual INT Update();
	virtual void Close();
};