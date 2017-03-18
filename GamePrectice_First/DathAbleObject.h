#pragma once
#include "stdafx.h"

class GameObject;

class DathAbleObject
{
protected:
	INT m_HP;
	bool m_bflip;
	bool m_bIsHit;
	float m_fElapsedTime;

	bool HitUpdate(GameObject* obj);
public:
	DathAbleObject();
	~DathAbleObject();

	void Hit(int Damage);
};

