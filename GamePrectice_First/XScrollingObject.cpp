#include "XScrollingObject.h"
#include "Texture.h"

XScrollingObject::XScrollingObject(int direction, int endX, int startX, int speed, CTexture* texture)
	: m_dEndX(endX), m_dStartX(startX),m_dSpeed(speed),m_Direction(direction)
{
	m_Tex = texture;
}

XScrollingObject::~XScrollingObject()
{
	delete m_Tex;
}

INT XScrollingObject::Init()
{

	return 0;
}
INT XScrollingObject::Render()
{
	m_Tex->Draw();
	return 0;
}
INT XScrollingObject::Update()
{
	UpdateScrolling();
	return 0;
}
INT XScrollingObject::Collision(GameObject* obj)
{

	return 0;
}
void XScrollingObject::Destroy()
{

}

void XScrollingObject::UpdateScrolling()
{
	if (m_Tex->GetPositionX()*m_Direction > m_dEndX * m_Direction)
		m_Tex->SetPositionX((float)m_dStartX);
	else
		m_Tex->SetPositionX(m_Tex->GetPositionX() + m_dSpeed* m_Direction * g_pApp->m_fdeltaTime);
}