#include "stdafx.h"

#include "BitmapDataManager.h"
#include "Texture.h"
#include "IScene.h"

#include "TestScene.h"

CGame::CGame()
{
	
}


CGame::~CGame()
{
}

INT CGame::Init() {

	//Texture Load
	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/background_0.png"	,"BG_base"	 );
	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/background_1.png"	,"BG_Back1"	 );
	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/background_2.png"	,"BG_Back2"	 );
	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/background_3.png"	,"BG_Back3"	 );
	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/background_4.png"	,"BG_Middle" );
	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/background_5.png"	,"BG_Front"	 );
	BitmapDataManager::GetInstance()->CreateTexture("Texture/BackGround/floor.png"			,"BG_Floor"	 );

	//Player Texture Images
	BitmapDataManager::GetInstance()->CreateTexture("Texture/shooting/player/player.png", "PlayerShip");
	BitmapDataManager::GetInstance()->CreateTexture("Texture/shooting/player/bullet_", "png", 1, 5, "PlayerBullets");
	//Player Bullet

	//Scene Load
	SceneManager::GetInstance()->AddScene(new TestScene, 0);
	SceneManager::GetInstance()->ChangeScene(0);
	SceneManager::GetInstance()->CheckChangeScene();

	return 0;
}
INT CGame::Update() {

	SceneManager::GetInstance()->GetNowScene()->Update();



	return 0;
}
INT CGame::Render() {

	if (NULL == m_pd3dDevice)
		return -1;

	// Clear the backbuffer to a blue color
	m_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	// Begin the scene
	if (SUCCEEDED(m_pd3dDevice->BeginScene()))
	{
		//---------- SceneRender
		SceneManager::GetInstance()->GetNowScene()->Render();

		// Rendering of scene objects can happen here

		// End the scene
		m_pd3dDevice->EndScene();
	}

	// Present the backbuffer contents to the display
	m_pd3dDevice->Present(NULL, NULL, NULL, NULL);

	return 0;
}
void CGame::Destroy() {
	
	SceneManager::GetInstance()->Clear();
	BitmapDataManager::GetInstance()->Clear();
}