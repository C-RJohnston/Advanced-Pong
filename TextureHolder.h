#pragma once
#ifndef  TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H

#include <SFML/Graphics.hpp>
#include <map>

class TextureHolder
{
private:
	//a map that contains related pairs of strings and textures
	std::map<std::string, sf::Texture> m_Textures;

	//A static pointer of the same type as the class itself
	static TextureHolder* m_s_Instance;

public:
	TextureHolder();
	static sf::Texture& GetTexture(std::string const& filename);
};


#endif // ! TEXTURE_HOLDER_H

