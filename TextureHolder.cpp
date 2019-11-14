#include "TextureHolder.h"
#include <assert.h>

using namespace sf;
using namespace std;

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

sf::Texture& TextureHolder::GetTexture(std::string const& filename)
{
	//Get a reference to m_Textures using m_S_Instance
	auto& m = m_s_Instance->m_Textures;
	//auto is the equivalent of map<string,Texture>

	//Create an iterator to hold a kvp and search for the required kvp using the passed in file name
	auto KeyValuePair = m.find(filename);

	if (KeyValuePair != m.end())
	{
		//found the texture in the map
		return KeyValuePair->second;
	}
	else
	{
		//couldn't find the texture in the map
		auto& texture = m[filename];
		//Load the texture from file in the usual way
		texture.loadFromFile(filename);

		return texture;
	}
}