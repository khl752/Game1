#include "stdafx.h"


//-----------------------------------------------------------------------------
// Name: wWinMain()
// Desc: The application's entry point
//-----------------------------------------------------------------------------
CGame* g_pApp;
INT WINAPI wWinMain( HINSTANCE hInst, HINSTANCE, LPWSTR, INT )
{
	CGame d3dApp;
	g_pApp = &d3dApp;

	if (FAILED(d3dApp.Create(hInst)))
		return -1;

    return d3dApp.Run();
}



