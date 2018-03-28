#ifndef IMAGE_H
#define IMAGE_H

#include <SDL\SDL2-2.0.4\include\SDL.h>
#include <SDL\SDL2_image-2.0.1\include\SDL_image.h>
#include <glew-2.1.0\include\GL\glew.h>
#include <string>
#include <iostream>

class Image
{
private: 
	SDL_Surface* text;
	GLuint textID;
		 
protected:
	std::string name;

public: 
	Image(std::string &name, std::string fileName);
	~Image();

	void SetName(std::string &_name);
	std::string GetName();
	
	void CreateTexture();
	GLuint GetTextID();
	int GetWidth();
	int GetHeight();

	Uint8 GetBitsPerPixel();
	GLenum GetMode();

	void* GetImageData();
};

#endif // !IMAGE_H
