#include "stdafx.h"
#include "Texture.h"

BitmapDataManager* BitmapDataManager::Instance = nullptr;

BitmapDataManager::BitmapDataManager()
{
}


BitmapDataManager::~BitmapDataManager()
{
	this->Clear();
}


Texture* BitmapDataManager::CreateTextureFromFile(std::string directory)
{
	LPDIRECT3DTEXTURE9 tex;
	D3DXIMAGE_INFO info;

	if (FAILED(D3DXCreateTextureFromFileEx(
		g_pApp->m_pd3dDevice
		, directory.c_str()
		, D3DX_DEFAULT_NONPOW2
		, D3DX_DEFAULT_NONPOW2
		, 1
		, 0
		, D3DFMT_UNKNOWN
		, D3DPOOL_MANAGED
		, D3DX_FILTER_NONE
		, D3DX_FILTER_NONE
		, NULL
		, &info
		, 0
		, &tex
	)))
	{
		MessageBox(GetActiveWindow(), "Texture Create Failed", "Err", MB_OK);
	}

	RECT rc;
	SetRect(&rc, 0, 0, info.Width, info.Height);

	Texture* texture = new Texture(tex, info, rc);

	return texture;
}

Texture* BitmapDataManager::GetTexture(std::string key)
{
	Texture* temp = m_TextureMap[key];
	if (temp == nullptr)
	{
		MessageBox(GetActiveWindow(), "Please check KeyValue", "Err", MB_OK);
		return nullptr;
	}

	return temp;
}
Sprite*  BitmapDataManager::GetSprite(std::string key)
{
	Sprite* temp = m_SpriteMap[key];
	if (temp == nullptr)
	{
		MessageBox(GetActiveWindow(), "Please check KeyValue", "Err", MB_OK);
		return nullptr;
	}

	return temp;
}

void	 BitmapDataManager::CreateTexture(std::string directory, std::string format, int start, int last, std::string KeyValue)
{
	Sprite * sprite = new Sprite(last - start);

	std::string DirStr;
	char temp[10];
	DirStr = directory;

	for (int i = 0; i <= last - start; ++i)
	{
		sprintf_s(temp, "%d", i);

		sprite->m_TexArray.push_back(CreateTextureFromFile(DirStr + temp + '.' + format));
	}

	m_SpriteMap[KeyValue] = sprite;
}
void	 BitmapDataManager::CreateTexture(std::string directory, std::string KeyValue)
{
	m_TextureMap[KeyValue] = CreateTextureFromFile(directory);
}

void	 BitmapDataManager::Clear()
{
	for (auto it = m_TextureMap.begin(); it != m_TextureMap.end(); ++it)
		delete (*it).second;


	for (auto it = m_SpriteMap.begin(); it != m_SpriteMap.end(); ++it)
		delete (*it).second;

	m_TextureMap.clear();
	m_SpriteMap.clear();
}