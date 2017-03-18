#include "TestScene.h"

#include "XScrollingObject.h"
#include "Texture.h"
#include "Input.h"
#include "Player.h"

static CPlayer P;

TestScene::TestScene()
{
}


TestScene::~TestScene()
{

}

INT TestScene::Init()
{
	m_Input = new CInput;

	P.Init();

	return 0;
}
INT TestScene::Update()
{
	m_ObjectManager.UpdateAll();
 	m_Input->Update();

	P.Update();
	
	return 0;
}
INT TestScene::Render()
{
	m_ObjectManager.RenderAll();

	P.Render();
	return 0;
}
void TestScene::Close()
{
	if (m_Input != nullptr)
		delete m_Input;

	m_ObjectManager.Clear();
}