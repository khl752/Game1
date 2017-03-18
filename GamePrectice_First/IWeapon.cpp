#include "IWeapon.h"

#include "stdafx.h"
#include "GameObject.h"
#include "IScene.h"

// IWeapon
IWeapon::IWeapon()
{

}
IWeapon::~IWeapon()
{
}


// Weapon
Weapon::Weapon(D3DXVECTOR2 socketposition)
	:m_Position(socketposition)
{
	m_fAttackDelay = 1;
	m_nForce	   = 300;
	m_fElapsedTime = m_fAttackDelay;
}
Weapon::~Weapon()
{


}
