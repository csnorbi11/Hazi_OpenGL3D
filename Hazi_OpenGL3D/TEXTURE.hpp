#ifndef TEXTURE_H
#define TEXTURE_H


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>



class Texture {
	unsigned int texture;
public:
	/**
	 * Parameter nelkuli konstruktor, ami nem állít be semmit.
	 * 
	 */
	Texture()
		:
		texture(0)
	{}
	/**
	 * Parameteres konstruktor ami a parameterben megkapja a textura eleresi utjat es azalapjan letrehozza a texturat.
	 * 
	 * \param path - textura eleresi utja
	 */
	Texture(const char* path)
		:
		texture(0)
	{
		try {
			loadTexture(path);
		}
		catch (const char* s)
		{
			std::cout << "Nem lehet betolteni a texturat:  " << s << std::endl;
			throw "hiba a textura betoltese kozben";
		}
	}
	~Texture()
	{
		if(texture!=0)
			glDeleteTextures(1, &texture);
	}
	/**
	 * Aktivalja a texturat.
	 * 
	 */
	void useTexture() const;

private:
	/**
	 * Betolti a texturat.
	 * 
	 * \param path
	 */
	void loadTexture(const char* path);
};

#endif // !TEXTURE_H
