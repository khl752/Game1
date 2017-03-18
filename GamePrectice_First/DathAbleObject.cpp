#include "DathAbleObject.h"
#include "GameObject.h"
#include "Texture.h"

#define FLICKERINGINTERVAL 0.2
#define MAX_FLICKINGCOUNT 4

DathAbleObject::DathAbleObject()
{
	m_HP			= 0;
	m_bflip			= false;
	m_bIsHit		= false;

	m_fElapsedTime	= 0.0f;
}


DathAbleObject::~DathAbleObject()
{
}

// ������ �̹����� ��¦�Ÿ��� ����
// ������ true�� ����
bool DathAbleObject::HitUpdate(GameObject* obj)
{
	if (m_HP <= 0)
	{
		m_HP = 0;
		return true;
	}
	else if (m_bIsHit)
	{
		if (m_fElapsedTime >= FLICKERINGINTERVAL)
		{
			m_fElapsedTime = 0;

			m_bflip ? obj->m_Tex->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f))
				: obj->m_Tex->SetColor(D3DXCOLOR(1.0f, 0.2f, 0.2f, 1.0f));

			m_bflip = !m_bflip;
		}
		else if(m_bIsHit)
		{
			m_bIsHit = false;
			m_bflip = false;

			obj->m_Tex->SetColor(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		}
		m_fElapsedTime += g_pApp->m_fdeltaTime;
	}

	return false;
}

// �� ������Ʈ�� ����
void DathAbleObject::Hit(int Damage)
{
	if (m_HP > 0)
	{
		m_HP -= Damage;
		m_bIsHit = true;
	}
}