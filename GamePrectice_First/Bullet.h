#pragma once
#include "stdafx.h"
#include "CollisionAbleObejct.h"

class CAnimation;

class Bullet
	: public CollisionAbleObject
{
protected:
	CAnimation*	m_pExploAnimation;
	D3DXVECTOR2 m_LookVc;
	UINT		m_Speed;
	UINT		m_Damage;

	void MoveBullet();
public:
	Bullet(D3DXVECTOR2 pos,D3DXVECTOR2 direction, UINT speed);
	~Bullet();

	virtual bool Collision(CollisionAbleObject* obj) final;
};