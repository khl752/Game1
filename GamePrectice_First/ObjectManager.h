#pragma once
#include "stdafx.h"

class GameObject;
class CollisionAbleObject;


enum PopState
{
	PS_REMOVE,
	PS_POP
};

struct PopStruct
{
	GameObject *m_Obj;
	PopState m_State;
};

class ObjectManager
{
private:
	std::list<GameObject*> m_ObjList;
	std::list<PopStruct> m_PopList;

	std::list<CollisionAbleObject*> m_ColliderList;
public:
	ObjectManager();
	virtual ~ObjectManager();

	bool operator()(const GameObject* Left, const GameObject* Right);

	void AddObject(GameObject* obj);
	GameObject* PopObject(GameObject* obj, const PopState pop_state = PS_REMOVE);

	INT UpdateAll();
	INT RenderAll();
	INT Collision();

	void Clear();
};

