#include "Bullet.h"
#include "DathAbleObject.h"
#include "Texture.h"
#include "IScene.h"

Bullet::Bullet(D3DXVECTOR2 pos, D3DXVECTOR2 direction, UINT speed)
	: m_LookVc(direction)
	, m_Speed(speed)
{
	GameObject::Init();

	m_Position = pos;
	m_pExploAnimation = nullptr;
	m_Damage = 1;
}


Bullet::~Bullet()
{
	if (m_pExploAnimation != nullptr)
		delete m_pExploAnimation;
}

void Bullet::MoveBullet()
{
	m_Position += m_LookVc*(float)m_Speed*g_pApp->m_fdeltaTime;
	if (ScreenCollisionTest(m_Position.x, m_Position.y))
	{
		SceneManager::GetInstance()->GetNowScene()->PopObject(this);
	}
}


bool Bullet::Collision(CollisionAbleObject* obj)
{
	if (CircleCollision(obj))
	{
		DathAbleObject* hitobj;
		hitobj = dynamic_cast<DathAbleObject*>(obj);

		if (hitobj != nullptr)
		{
			hitobj->Hit(m_Damage);
		}

		SceneManager::GetInstance()->GetNowScene()->PopObject(this);
		return true;
	}

	return false;
}