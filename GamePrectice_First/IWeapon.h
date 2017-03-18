#include "stdafx.h"
#define DEFAULT_DIRECTION_X 1
#define DEFAULT_DIRECTION_Y 0

class GameObject;
class Bullet;

class IWeapon
{
public:
	IWeapon();
	virtual ~IWeapon();

	virtual Bullet* UseWeapon() = 0;
};

class Weapon
	: public IWeapon
{
protected:
	D3DXVECTOR2 m_Position;
	UINT		m_nForce;
	float		m_fElapsedTime;
	float		m_fAttackDelay;
public:
	Weapon(D3DXVECTOR2 sorketPosition);
	virtual ~Weapon();

	virtual Bullet* UseWeapon() = 0;
};
