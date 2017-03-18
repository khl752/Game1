#pragma once
class D3DApp
{
public:
	HWND				m_hWnd;
	HINSTANCE			m_hInst;

	LPDIRECT3D9         m_pD3D;
	LPDIRECT3DDEVICE9   m_pd3dDevice;
	LPD3DXSPRITE		m_pd3dSprite;

	int		m_FPS;
	int		m_tempFPS;
	int		m_CurrentTime;
	int		m_PrevTime;
	int		m_deltaTime;
	int		m_TotalTime;
	float	m_fdeltaTime;
public:
	D3DApp();
	virtual ~D3DApp();

	HRESULT InitD3D(HWND hWnd);

	// Application Main
	INT GameMain();
	//-----------------------------------------------------------------------------
	// Name: Cleanup()
	// Desc: Releases all previously initialized objects
	//-----------------------------------------------------------------------------
	VOID Cleanup();
	INT Create(HINSTANCE hInst);
	INT Run();


	//-----------------------------------------------------------------------------
	// Name: MsgProc()
	// Desc: The window's message handler
	//-----------------------------------------------------------------------------
	static LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	//Update Frame
	void UpdateFrame();

	//Main Logic
	virtual INT Init();
	virtual INT Update();
	virtual INT Render();
	virtual void Destroy();
};

