#include "Material.h"

Material::Material()
{
	mType = NONE;
}

Material::Material(glm::vec3 color)
{
	mType = COLOUR;	///TO DO
	//shader = ShaderManager::GetInstance()->Get("NOTHING");
}

Material::Material(Image* image)
{
	mType = TEXTURE;

	imgRef = ImageManager::GetInstance()->Get(image->GetName());

	//default texture shader
	//ShaderManager::GetInstance()->Put(std::string("myShader"), "../RobEngine/Shaders/textureShader.vs", "../RobEngine/Shaders/textureShader.fs");
	imgShader = ShaderManager::GetInstance()->Get(std::string("myShader"));
}

Material::Material(Image* image, Shader* shader)
{
	mType = TEXTURE;

	imgRef = ImageManager::GetInstance()->Get(image->GetName());

	//TO DO
	imgShader = ShaderManager::GetInstance()->Get(shader->GetName());
}

Material::~Material()
{

}

void Material::SetName(std::string &_name)
{
	name = _name;
}

std::string Material::GetName()
{
	return name;
}

void Material::Init()
{
	if (mType == TEXTURE)
	{
		imgRef->CreateTexture();
	}
	//glGenTextures(1, &texture1);
	//glBindTexture(GL_TEXTURE_2D, texture1);
	////ShaderManager::GetInstance()->Get(std::string("myShader"))->setInt("texture1", 0);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// set texture wrapping to GL_REPEAT (default wrapping method)
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//// set texture filtering parameters
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//texture = new SDL_Surface();
	//texture = IMG_Load("../Resources/itsa.jpg");
	//if (texture == NULL)
	//{
	//	std::cerr << "Unable to load image + " << std::endl;
	//	printf(IMG_GetError());
	//}
	//else
	//{
	//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture->w, texture->h, 0, GL_RGB, GL_UNSIGNED_BYTE, texture->pixels);
	//	glGenerateMipmap(GL_TEXTURE_2D);
	//}
	////SDL_FreeSurface(texture);
	////clear VAO and VBO binds
	//glBindTexture(GL_TEXTURE_2D, 0);
}

void Material::PreRender()
{
	// tell opengl for each sampler to which texture unit it belongs to (only has to be done once)
	// -------------------------------------------------------------------------------------------
	// don't forget to activate/use the shader before setting uniforms!
	imgShader->use();
}

void Material::Render()
{
	// bind textures on corresponding texture units
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, imgRef->GetTextID());
}

void Material::PostRender()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}