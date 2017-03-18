#include "CollisionAbleObejct.h"



CollisionAbleObject::CollisionAbleObject()
	: m_Radius(0)
	, m_bIsHit(false)
{

}


CollisionAbleObject::~CollisionAbleObject()
{
}

void CollisionAbleObject::InitCollider(UINT radius)
{
	m_Radius = radius;
}