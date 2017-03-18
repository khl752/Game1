#pragma once
#include "stdafx.h"

struct Texture
{
	const LPDIRECT3DTEXTURE9	m_lpTex;
	const D3DXIMAGE_INFO		m_Info;
	const RECT					m_ImageRect;

	Texture(LPDIRECT3DTEXTURE9 tex, D3DXIMAGE_INFO info, RECT rect)
	: m_lpTex(tex),m_Info(info),m_ImageRect(rect){				};
	~Texture() {}
};

struct Sprite
{
	std::vector<Texture*> m_TexArray;
	int		  m_CurrentIndex;
	const int m_Length;

	Sprite(int length)
		: m_Length(length)
	{
		m_CurrentIndex = 0;
	}
	~Sprite()
	{
		for (UINT i = 0; i < m_TexArray.size(); ++i)
			delete m_TexArray[i];

		m_TexArray.clear();
	}

	Texture* GetcurrentTex()
	{
		return m_TexArray[m_CurrentIndex];
	}

	bool SetIndex(int num)
	{
		if (m_CurrentIndex <= m_Length)
			m_CurrentIndex = num;
		else
			return false;

		return true;
	}

	void FlowSprite()
	{
		if (m_CurrentIndex < m_Length)
			m_CurrentIndex += 1;
		else
			m_CurrentIndex = 0;
	}
	void ReFlowSprite()
	{
		if (m_CurrentIndex < 0)
			m_CurrentIndex -= 1;
		else
			m_CurrentIndex = m_Length;
	}
};

class CTexture
{
protected:
	Texture* m_Tex;
protected:
	DWORD		m_Color;
	D3DXVECTOR2 m_Position;
	D3DXVECTOR2 m_Pivot;
	D3DXVECTOR2 m_Scale;
	D3DXVECTOR2 m_ScalePivot;
	D3DXVECTOR2 m_RotatePivot;
	int			m_RotateAngle;

	D3DXVECTOR2 PivotConvert(D3DXVECTOR2 pivot, float width, float height)
	{
		D3DXVECTOR2 piv;

		piv.x = -(width * pivot.x);
		piv.y = -(height * pivot.y);

		return piv;
	}
	D3DXMATRIX CTexture::Transformation2D(const D3DXVECTOR2& Position
		, const D3DXVECTOR2 Pivot
		, const D3DXVECTOR2 Scale
		, const D3DXVECTOR2 ScalePivot
		, const D3DXVECTOR2 RotatePivot
		, const int Rotate)
	{
		D3DXMATRIX mtW;
		D3DXMATRIX mtP;

		D3DXMatrixIdentity(&mtW);
		D3DXMatrixIdentity(&mtP);

		D3DXMatrixTransformation2D(&mtW, &ScalePivot, NULL, &Scale
			, &RotatePivot, D3DXToRadian(Rotate), &Position);

		D3DXMatrixTranslation(&mtP, Pivot.x, Pivot.y, 0.0f);

		mtW *= mtP;

		return mtW;
	}

public:
	CTexture()
	{
		m_Color			= 0xFFFFFFFF;
		m_Position		= D3DXVECTOR2(0.0f,0.0f);
		m_Pivot			= D3DXVECTOR2(0.0f,0.0f);
		m_Scale			= D3DXVECTOR2(1.0f,1.0f);
		m_ScalePivot	= D3DXVECTOR2(0.0f,0.0f);
		m_RotatePivot	= D3DXVECTOR2(0.0f,0.0f);
		m_RotateAngle = 0;
	}
	CTexture(Texture* tex
		, D3DXVECTOR2 pos		  = {0.0f,0.0f}
		, D3DXVECTOR2 pivot		  = {0.0f,0.0f}
		, D3DXVECTOR2 scale		  = {1.0f,1.0f}
		, D3DXVECTOR2 scalepivot  = {0.0f,0.0f}
		, D3DXVECTOR2 rotatepviot = {0.0f,0.0f}
		, int rotate  = 0 
		, DWORD Color = 0xFFFFFFFF)
		: m_Tex(tex)
		, m_Position(pos)
		, m_Pivot(pivot)
		, m_Scale(scale)
		, m_ScalePivot(scalepivot)
		, m_RotatePivot(rotatepviot)
		, m_RotateAngle(rotate)
		, m_Color(Color)
	{
	
	}
	virtual ~CTexture() {}


	void SetPivot(D3DXVECTOR2 pivot)
	{
		m_Pivot = pivot;
	}
	void SetPosition(D3DXVECTOR2 m_Pos)
	{
		m_Position = m_Pos;
	}
	void SetPositionX(float x)
	{
		m_Position.x = x;
	}
	void SetPositionY(float y)
	{
		m_Position.y = y;
	}
	void SetScale(D3DXVECTOR2 scale)
	{
		m_Scale = scale;
	}
	void SetScalePivot(D3DXVECTOR2 pivot)
	{
		m_ScalePivot = pivot;
	}
	void SetRotatePivot(D3DXVECTOR2 pivot)
	{
		m_RotatePivot = pivot;
	}
	void SetColor(DWORD Color)
	{
		m_Color = Color;
	}
	void SetRotate(int angle)
	{
		m_RotateAngle = angle;
	}
	
	int GetRotate()
	{
		return m_RotateAngle;
	}

	D3DXVECTOR2 GetPosition()
	{
		return m_Position;
	}
	float GetPositionX()
	{
		return m_Position.x;
	}
	float GetPositionY()
	{
		return m_Position.y;
	}

	
	void CTexture::Draw()
	{
		D3DXMATRIX mtW;
		D3DXVECTOR2 Pivot;
		D3DXVECTOR2 ScalePivot;
		D3DXVECTOR2 RotatePivot;

		Pivot = PivotConvert(m_Pivot, (float)m_Tex->m_Info.Width, (float)m_Tex->m_Info.Height);
		ScalePivot = PivotConvert(m_ScalePivot, (float)m_Tex->m_Info.Width, (float)m_Tex->m_Info.Height);
		RotatePivot = PivotConvert(m_RotatePivot, (float)m_Tex->m_Info.Width, (float)m_Tex->m_Info.Height);

		mtW = Transformation2D(m_Position, Pivot,m_Scale, ScalePivot, RotatePivot,m_RotateAngle);

		g_pApp->m_pd3dSprite->Begin(D3DXSPRITE_ALPHABLEND);

		//http://stackoverflow.com/questions/1988387/turning-a-directx-sprite-solid-white
		//Texture White Blending
		//device->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_ADD);
		//device->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
		//device->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

		g_pApp->m_pd3dSprite->SetTransform(&mtW);
		g_pApp->m_pd3dSprite->Draw(m_Tex->m_lpTex, &m_Tex->m_ImageRect, NULL, NULL, m_Color);
		

		D3DXMatrixIdentity(&mtW);
		g_pApp->m_pd3dSprite->SetTransform(&mtW);

		g_pApp->m_pd3dSprite->End();

	}

	virtual void LoadTexture(std::string key);
};

class CSprite
	:public CTexture
{
protected:
	Sprite* m_Sprite;
	int m_CurrentIndex;
public:
	virtual int GetCurrentIndex()
	{
		return m_CurrentIndex;
	}
	virtual bool SetCurrentIndex(int num)
	{
		if (num <= m_Sprite->m_Length)
		{
			m_CurrentIndex = num;
			m_Tex=m_Sprite->m_TexArray[m_CurrentIndex];
			return true;
		}
		return false;
	}
	virtual void LoadTexture(std::string key);
};

class CAnimation
	:public CSprite
{
	int m_FPS;
	int m_StartIndex;
	int m_LastIndex;
	float m_IntervalTime;
	float m_ElpasedTime;
public:
	CAnimation()
	{
		m_FPS = 0;
		m_StartIndex = 0;
		m_LastIndex = 0;
		m_IntervalTime = 0.0f;
		m_ElpasedTime = 0.0f;
	}
	~CAnimation() {}

	virtual void InitAnimation(int FPS, int start, int last)
	{
		m_FPS = FPS;
		m_StartIndex = start;
		m_LastIndex = last;
		m_IntervalTime = 1 / (float)m_FPS;
	}
	virtual void CAnimation::UpdateAnimation(float fdeltaTime)
	{
		if (m_ElpasedTime >= m_IntervalTime)
		{
			++m_CurrentIndex;
			if (m_CurrentIndex > m_LastIndex)
			{
				m_CurrentIndex = m_StartIndex;
			}

			m_ElpasedTime = 0;
		}
		m_ElpasedTime += fdeltaTime;

		m_Tex = m_Sprite->m_TexArray[m_CurrentIndex];
	}


};
