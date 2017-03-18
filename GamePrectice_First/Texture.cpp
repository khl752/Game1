#include "Texture.h"

void CTexture::LoadTexture(std::string key)
{
	m_Tex = BitmapDataManager::GetInstance()->GetTexture(key);
}



void CSprite::LoadTexture(std::string key)
{
	m_Sprite = BitmapDataManager::GetInstance()->GetSprite(key);
	m_Tex = m_Sprite->m_TexArray[0];
}