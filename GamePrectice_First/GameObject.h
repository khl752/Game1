#pragma once
#include "stdafx.h"
#include "IGameObject.h"

//전방 선언
class CTexture;

class GameObject :
	public IGameObject
{
public:
	CTexture* m_Tex;
	D3DXVECTOR2 m_Position;
	int			m_Rotate;

	int m_TAG;
	int m_Layer;
public:
	GameObject();
	virtual ~GameObject();

	virtual INT Init();
	virtual INT Render();
	virtual INT Update();
	virtual void Destroy();
};

