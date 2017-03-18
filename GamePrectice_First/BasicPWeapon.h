#pragma once
#include "PlayerWeapon.h"

struct Sprite;

class BasicPWeapon :
	public PlayerWeapon
{
protected:
	Sprite* m_BulletApper;
public:
	BasicPWeapon(D3DXVECTOR2 socketPosition);
	virtual ~BasicPWeapon();

	virtual Bullet* UseWeapon();
};

