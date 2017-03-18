#pragma once
#include "stdafx.h"
#include "GameObject.h"

class XScrollingObject :
	public GameObject
{	
protected:
	int m_Direction;

	int m_dEndX;
	int m_dStartX;
	int m_dSpeed;
	
	void UpdateScrolling();
public:
	// -1 LEFT , 1 RIGHT
	XScrollingObject(int direction,int endX, int startX, int speed, CTexture* texture);
	virtual ~XScrollingObject();

	virtual INT Init();
	virtual INT Render();
	virtual INT Update();
	virtual INT Collision(GameObject* obj);
	virtual void Destroy();
};

