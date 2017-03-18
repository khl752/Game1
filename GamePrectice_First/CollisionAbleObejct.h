#pragma once
#include "stdafx.h"
#include "GameObject.h"


// GameObject를 상속받고 있다
class CollisionAbleObject
	:public GameObject
{
private:
	bool m_bIsHit;
protected:
	UINT m_Radius;

	void InitCollider(UINT radius);
	bool CircleCollision(CollisionAbleObject* obj)
	{
		UINT Range = static_cast<UINT>(m_Position.x - obj->m_Position.x + m_Position.y*obj->m_Position.y);
		UINT RadiusSqrt = m_Radius*m_Radius;

		if (Range <= RadiusSqrt)
		{
			return true;
		}

		return false;
	}
public:
	CollisionAbleObject();
	virtual ~CollisionAbleObject();

	virtual bool Collision(CollisionAbleObject* obj) = 0;
};

