#include "stdafx.h"

D3DApp* m_pD3DApp;

D3DApp::D3DApp()
{
	m_pD3DApp = this;

	m_hWnd	= NULL;
	m_hInst  = NULL;

	m_pD3D		 = NULL;
	m_pd3dDevice = NULL;
	m_pd3dSprite = NULL;

	m_CurrentTime = GetTickCount();
	m_PrevTime = m_CurrentTime;
	m_FPS = 0;
	m_tempFPS = 0;
	m_deltaTime = 0;
	m_TotalTime = 0;
	m_fdeltaTime = 0.0f;
}
D3DApp:: ~D3DApp()
{

}
LRESULT WINAPI D3DApp::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	return m_pD3DApp->MsgProc(hWnd, msg, wParam, lParam);
}
INT D3DApp:: Create(HINSTANCE hInst)
{
	m_hInst = hInst;

	UNREFERENCED_PARAMETER(hInst);

	// Register the window class
	WNDCLASSEX wc =
	{
		sizeof(WNDCLASSEX), CS_CLASSDC, WndProc, 0L, 0L,
		GetModuleHandle(NULL), NULL, NULL, NULL, NULL,
		"D3D Tutorial", NULL
	};
	RegisterClassEx(&wc);

	// Create the application's window
	m_hWnd = CreateWindow("D3D Tutorial", "D3D Tutorial 01: CreateDevice10",
		WS_OVERLAPPEDWINDOW, 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT,
		NULL, NULL, wc.hInstance, NULL);

	// Initialize Direct3D
	if (FAILED(InitD3D(m_hWnd)))
		return -1;
	// Show the window
	ShowWindow(m_hWnd, SW_SHOWDEFAULT);
	UpdateWindow(m_hWnd);

	if (FAILED(Init()))
		return -1;

	return 0;
}
HRESULT D3DApp::InitD3D(HWND hWnd)
{
	// Create the D3D object, which is needed to create the D3DDevice.
	if (NULL == (m_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;

	// Set up the structure used to create the D3DDevice. Most parameters are
	// zeroed out. We set Windowed to TRUE, since we want to do D3D in a
	// window, and then set the SwapEffect to "discard", which is the most
	// efficient method of presenting the back buffer to the display.  And 
	// we request a back buffer format that matches the current desktop display 
	// format.
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;

	// Create the Direct3D device. Here we are using the default adapter (most
	// systems only have one, unless they have multiple graphics hardware cards
	// installed) and requesting the HAL (which is saying we want the hardware
	// device rather than a software one). Software vertex processing is 
	// specified since we know it will work on all cards. On cards that support 
	// hardware vertex processing, though, we would see a big performance gain 
	// by specifying hardware vertex processing.
	if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &m_pd3dDevice)))
	{
		return E_FAIL;
	}

	if (FAILED(D3DXCreateSprite(m_pd3dDevice, &m_pd3dSprite)))
		return -1;
	// Device state would normally be set here

	return S_OK;
}
VOID D3DApp::Cleanup()
{
	delete BitmapDataManager::GetInstance();
	delete SceneManager::GetInstance();

	if (m_pd3dSprite != NULL)
		m_pd3dSprite->Release();

	if (m_pd3dDevice != NULL)
		m_pd3dDevice->Release();

	if (m_pD3D != NULL)
		m_pD3D->Release();
}

INT D3DApp::Run()
{
	MSG msg;
	memset(&msg, 0, sizeof(msg));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			if (FAILED(GameMain()))
				SendMessage(m_hWnd, WM_DESTROY, 0, 0);
		}
	}

	return UnregisterClass("D3D Tutorial", m_hInst);
}
LRESULT WINAPI D3DApp::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		Cleanup();
		PostQuitMessage(0);
		return 0;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			SendMessage(hWnd, WM_DESTROY, wParam, lParam);
			return 0;
		}
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

INT D3DApp::GameMain()
{
	
	if (FAILED(m_pd3dDevice == NULL))
		return -1;

	if (FAILED(Update()))
		return -1;

	if (FAILED(Render()))
		return -1;

	SceneManager::GetInstance()->CheckChangeScene();

	this->UpdateFrame();
	return 0;
}

void D3DApp::UpdateFrame()
{
	m_CurrentTime = GetTickCount();
	m_deltaTime = m_CurrentTime - m_PrevTime;
	m_fdeltaTime = (float)m_deltaTime / 1000;

	m_TotalTime += m_deltaTime;

	++m_tempFPS;

	if (m_TotalTime >= 1000)
	{
		m_TotalTime -= 1000;
		m_FPS = m_tempFPS;

		m_tempFPS = 0;
	}

	m_PrevTime = m_CurrentTime;
}

INT D3DApp::Init() {
	return 0;
}
INT D3DApp::Update() {
	return 0;
}
INT D3DApp::Render() {
	return 0;
}
void D3DApp::Destroy() {

}