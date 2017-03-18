#pragma once
#include "stdafx.h"
#include "CollisionAbleObejct.h"

class WeaponSocket;
class CInput;

class CPlayer :
	public CollisionAbleObject
{
protected:
	WeaponSocket* m_Weapons;
	CInput* m_pInput;
	int		m_Speed;
public:
	CPlayer();
	virtual ~CPlayer();

	virtual INT Init();
	virtual INT Update();
	virtual INT Render();
	virtual INT Collision(GameObject* obj);
	virtual void Destroy();

	virtual bool Collision(CollisionAbleObject* obj);
};

