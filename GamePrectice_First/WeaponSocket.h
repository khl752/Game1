#pragma once
#include "stdafx.h"

enum WeaponKind
{
	WK_PBaisc,
	WK_PTRIPLESHOT,
	WK_PLASER,
	WK_PGUIDSHOT,


};

class IWeapon;
class GameObject;

class WeaponSocket
{
private:
	IWeapon* m_Weapon;
	D3DXVECTOR2 m_SocketPosition;
public:
	WeaponSocket(D3DXVECTOR2 socketPosition);
	virtual ~WeaponSocket();

	//void UpdateSocket()
	void ChangeWeapon(WeaponKind kind);
	void UseWeapon();
};

