#ifndef MATERIAL_H
#define MATERIAL_H

#include "ImageManager.h"
#include "ShaderManager.h"
#include "glm-0.9.8.4\glm\glm.hpp"
#include "glm-0.9.8.4\glm\gtc\matrix_transform.hpp"
#include "glm-0.9.8.4\glm\gtc\type_ptr.hpp"
#include "glew-2.1.0\include\GL\glew.h"
#include "glut-3.7.6-bin\glut.h"

enum Material_Style
{
	NONE,
	COLOUR,
	TEXTURE
};

class Material
{
private:

	Material_Style mType;
	Image* imgRef;
	std::string name;
	GLuint texture1;
	Shader* imgShader;

public:
	Material();
	Material(glm::vec3 color);
	Material(Image* image);
	Material(Image* image, Shader* shader);
	~Material();

	void SetName(std::string &_name);
	std::string GetName();

	void Init();
	void PreRender();
	void Render();
	void PostRender();

};

#endif // !MATERIAL_H

