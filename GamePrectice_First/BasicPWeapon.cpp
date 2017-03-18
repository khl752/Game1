#include "BasicPWeapon.h"
#include "BasicBullet.h"
#include "IScene.h"
#include "Texture.h"


BasicPWeapon::BasicPWeapon(D3DXVECTOR2 socketPosition)
	:PlayerWeapon(socketPosition)
{
	m_fAttackDelay = 0.5;
	m_nForce	   = 300;
	m_fElapsedTime = m_fAttackDelay;

	m_BulletApper = BitmapDataManager::GetInstance()->GetSprite("PlayerBullets");
}


BasicPWeapon::~BasicPWeapon()
{
}

Bullet* BasicPWeapon::UseWeapon()
{
	if (m_fElapsedTime >= m_fAttackDelay)
	{
		Bullet* bullet = new BasicBullet(
			m_Position,D3DXVECTOR2(DEFAULT_DIRECTION_X, DEFAULT_DIRECTION_Y)
			,m_nForce,m_BulletApper->GetcurrentTex());

		SceneManager::GetInstance()
			->GetNowScene()->AddObject(bullet);

		m_fElapsedTime = 0;
		m_BulletApper->FlowSprite();
		return bullet;
	}

	m_fElapsedTime += g_pApp->m_fdeltaTime;
	return nullptr;
}