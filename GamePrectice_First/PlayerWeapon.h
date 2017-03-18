#pragma once
#include "IWeapon.h"
class PlayerWeapon :
	public Weapon
{
public:
	PlayerWeapon(D3DXVECTOR2 socketPosition);
	virtual ~PlayerWeapon();

	virtual Bullet* UseWeapon() = 0;
};
