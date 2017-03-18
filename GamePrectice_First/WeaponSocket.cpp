#include "WeaponSocket.h"
#include "BasicPWeapon.h"

WeaponSocket::WeaponSocket(D3DXVECTOR2 socketPosition)
	: m_SocketPosition(socketPosition)
	, m_Weapon(nullptr)
{
}


WeaponSocket::~WeaponSocket()
{
	if (m_Weapon != nullptr)
		delete m_Weapon;
}

void WeaponSocket::ChangeWeapon(WeaponKind kind)
{
	if (m_Weapon != nullptr)
		delete m_Weapon;

	switch (kind)
	{
	case WK_PBaisc:
		m_Weapon = new BasicPWeapon(m_SocketPosition);
		break;
	case WK_PTRIPLESHOT:
		break;
	case WK_PLASER:
		break;
	case WK_PGUIDSHOT:
		break;
	default:
		break;
	}
}

void WeaponSocket::UseWeapon()
{
	if (m_Weapon != nullptr)
		m_Weapon->UseWeapon();
}