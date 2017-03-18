#include "IScene.h"
#include "ObjectManager.h"

// IScene
IScene::IScene()
{
}
IScene::~IScene()
{
}



// SceneObject
SceneObject::SceneObject()
{
}
SceneObject::~SceneObject()
{
}

INT SceneObject::Init()
{
	
	return 0;
}
INT SceneObject::Render()
{
	
	return 0;
}
INT SceneObject::Update()
{

	return 0;
}
void SceneObject::Close()
{

}

void SceneObject::AddObject(GameObject* obj)
{
	m_ObjectManager.AddObject(obj);
}
//PopState : PS_REMOVE 
//			 PS_POP
GameObject* SceneObject::PopObject(GameObject* obj,PopState pop_state)
{
	return m_ObjectManager.PopObject(obj,pop_state);
}
