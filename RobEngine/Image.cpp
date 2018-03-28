#include "Image.h"

Image::Image(std::string &name, std::string fileName)
{
	text = new SDL_Surface();
	text = IMG_Load(fileName.c_str());
	SetName(name);

	if (text == NULL)
	{
		std::cerr << "Unable to load image + " << fileName << std::endl;
		printf(IMG_GetError());
	}
}

Image::~Image()
{
	SDL_FreeSurface(text);
	text = nullptr;
	delete text;
}

void Image::CreateTexture()
{
	/// Let's generate two textures in the GPU and bind the first one
	glGenTextures(1, &textID);
	/// Bind the first one
	glBindTexture(GL_TEXTURE_2D, textID);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GetMode(), text->w, text->h, 0, GetMode(), GL_UNSIGNED_BYTE, text->pixels);
	glGenerateMipmap(GL_TEXTURE_2D);
}

void Image::SetName(std::string &_name)
{
	name = _name;
}

std::string Image::GetName()
{
	return name;
}

GLuint Image::GetTextID()
{
	return textID;
}

int Image::GetWidth()
{
	return text->w;
}

int Image::GetHeight()
{
	return text->h;
}

Uint8 Image::GetBitsPerPixel()
{
	return text->format->BitsPerPixel;
}

GLenum Image::GetMode()
{
	if (text->format->BytesPerPixel == 4 || text->format->BytesPerPixel == 8)
	{
		return GL_RGBA;
	}
	else
	{
		return GL_RGB;
	}
}

void* Image::GetImageData()
{
	return text->pixels;
}



