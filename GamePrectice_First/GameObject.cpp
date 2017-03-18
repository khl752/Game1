#include "GameObject.h"

GameObject::GameObject()
{
	m_Tex		= nullptr;

	m_Position	= D3DXVECTOR2(0.0f,0.0f);
	m_Rotate	= 0;

	m_TAG		= 0;
	m_Layer		= 0;
}

GameObject::~GameObject()
{
}

INT GameObject::Init()
{

	return 0;
}
INT GameObject::Render()
{

	return 0;
}
INT GameObject::Update()
{

	return 0;
}
void GameObject::Destroy()
{

}