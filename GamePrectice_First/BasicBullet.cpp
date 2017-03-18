#include "BasicBullet.h"
#include "Texture.h"

BasicBullet::BasicBullet(D3DXVECTOR2 pos, D3DXVECTOR2 direction, UINT speed, Texture* tex)
	: Bullet(pos,direction,speed)
{
	m_Tex = new CTexture(tex);
}


BasicBullet::~BasicBullet()
{
}

INT BasicBullet::Init()
{
	InitCollider(2);
	return 0;
}
INT BasicBullet::Update()
{
	MoveBullet();
	m_Tex->SetPosition(m_Position);
	return 0;
}
INT BasicBullet::Render()
{
	m_Tex->Draw();
	return 0;
}
void BasicBullet::Destroy()
{
	if (m_Tex != nullptr)
		delete m_Tex;
}