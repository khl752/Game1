#pragma once

struct Texture;
struct Sprite;

class BitmapDataManager
{	
	std::map<std::string, Texture*> m_TextureMap;
	std::map<std::string, Sprite*> m_SpriteMap;

	static BitmapDataManager* Instance;
	BitmapDataManager();

	Texture* CreateTextureFromFile(std::string directory);
public:
	static BitmapDataManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new BitmapDataManager();

		return Instance;
	}
	virtual ~BitmapDataManager();

	Texture*	GetTexture(std::string key);
	Sprite*		GetSprite(std::string key);

	void CreateTexture(std::string directory, std::string format, int start, int last, std::string KeyValue);
	void CreateTexture(std::string directory, std::string KeyValue);

	void Clear();
};

