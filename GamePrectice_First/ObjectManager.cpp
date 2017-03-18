#include "ObjectManager.h"
#include "CollisionAbleObejct.h"
#include "GameObject.h"

ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}
bool ObjectManager::operator() (const GameObject* Left, const GameObject* Right)
{
	return Left->m_Layer > Right->m_Layer;
}

void ObjectManager::AddObject(GameObject* obj)
{
	m_ObjList.push_back(obj);
	m_ObjList.sort(ObjectManager());

	CollisionAbleObject* pCollider = nullptr;
	pCollider = dynamic_cast<CollisionAbleObject*>(obj);

	if (pCollider != nullptr)
		m_ColliderList.push_back(pCollider);

}
GameObject* ObjectManager::PopObject(GameObject* obj, const PopState pop_state)
{
	switch (pop_state)
	{
	case PS_REMOVE:
		m_PopList.push_back({ obj,pop_state });
		return nullptr;
	case PS_POP:
		m_PopList.push_back({obj,pop_state});
		return obj;
	default:
		break;
	}

	return nullptr;
}

INT ObjectManager::UpdateAll()
{
	for (auto it = m_ObjList.begin(); it != m_ObjList.end(); ++it)
	{
		(*it)->Update();
	}
	return 0;
}
INT ObjectManager::RenderAll()
{
	for (auto it = m_ObjList.begin(); it != m_ObjList.end(); ++it)
	{
		(*it)->Render();
	}
	return 0;
}
INT ObjectManager::Collision()
{
	for (auto it_from = m_ColliderList.begin(); it_from != m_ColliderList.end(); ++it_from)
	{
		for (auto it_to = it_from; it_to != m_ColliderList.end(); ++it_to)
		{
			if (it_from == it_to)
				continue;

			if ((*it_from)->Collision((*it_to)))
			{
				(*it_to)->Collision((*it_from));
			}
		}
	}

	return 0;
}

void ObjectManager::Clear()
{
	for (auto it = m_ObjList.begin(); it != m_ObjList.end(); ++it)
	{
		(*it)->Destroy();
		delete (*it);
	}

	m_ObjList.clear();
	m_PopList.clear();
}
