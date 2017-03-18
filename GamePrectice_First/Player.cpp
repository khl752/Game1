#include "Player.h"
#include "Input.h"
#include "Texture.h"
#include "WeaponSocket.h"

CPlayer::CPlayer()
{
	m_pInput = nullptr;
}


CPlayer::~CPlayer()
{
	if (m_pInput != nullptr)
		delete m_pInput;

	if (m_Tex != nullptr)
		delete m_Tex;

	if (m_Weapons != nullptr)
		delete m_Weapons;
}

INT CPlayer::Init()
{
	if (m_pInput == nullptr)
	{
		m_pInput = new CInput();
	}

	if(m_Tex == nullptr)
		m_Tex = new CTexture();

	if (m_Weapons == nullptr)
		m_Weapons = new WeaponSocket(m_Position);

	m_Weapons->ChangeWeapon(WK_PBaisc);
	m_Tex->LoadTexture("PlayerShip");
	m_Speed = 300;
	return 0;
}
INT CPlayer::Update()
{
	m_pInput->Update();

	if (m_pInput->KeyPress('W'))
	{
		m_Position.y -= m_Speed * g_pApp->m_fdeltaTime;;
	}
	if (m_pInput->KeyPress('A'))
	{
		m_Position.x -= m_Speed * g_pApp->m_fdeltaTime;
	}
	if (m_pInput->KeyPress('S'))
	{
		m_Position.y += m_Speed * g_pApp->m_fdeltaTime;
	}
	if (m_pInput->KeyPress('D'))
	{
		m_Position.x += m_Speed* g_pApp->m_fdeltaTime;
	}

	if (m_pInput->KeyPress(VK_SPACE))
	{
 		m_Weapons->UseWeapon();
	}

	m_Tex->SetPosition(m_Position);
	return 0;
}
INT CPlayer::Render()
{
	m_Tex->Draw();
	return 0;
}

INT CPlayer::Collision(GameObject* obj)
{

	return false;
}

void CPlayer::Destroy()
{

}

bool CPlayer::Collision(CollisionAbleObject* obj)
{

	return false;
}