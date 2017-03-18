#pragma once
#include "Bullet.h"

struct Texture;

class BasicBullet :
	public virtual Bullet
{
public:
	BasicBullet(D3DXVECTOR2 pos, D3DXVECTOR2 direction, UINT speed, Texture* tex);
	virtual ~BasicBullet();

	virtual INT Init()		override;
	virtual INT Update()	override;
	virtual INT Render()	override;
	virtual void Destroy()	override;
};

