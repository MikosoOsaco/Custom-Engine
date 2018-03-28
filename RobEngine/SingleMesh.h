#ifndef SINGLEMESH_H
#define SINGLEMESH_H

#include <vector>
#include "glew-2.1.0\include\GL\glew.h"
#include "glm-0.9.8.4\glm\glm.hpp"
#include "glm-0.9.8.4\glm\gtc\matrix_transform.hpp"
#include "glm-0.9.8.4\glm\gtc\type_ptr.hpp"
#include "VertDesc.h"
#include "ImageManager.h"
#include "ShaderManager.h"
#include "MaterialManager.h"


enum Mesh_Style
{
	TRIANGLE,
	SQUARE,
	CUBE
};

class SingleMesh
{
private:

	bool hasTexture = false;
	Material* material;
	

public:
	SingleMesh();
	SingleMesh(Mesh_Style mStyle);
	SingleMesh(Mesh_Style mStyle, Material* mat);
	~SingleMesh();
	void CreateBuffers();
	//void addObject(std::vector<Vertex> objectVerts);
	void addObject(int prim);
	void PreRender();
	void Render();
	void PostRender();

	unsigned int VBO, VAO;

	VertexDescriptor* vertDesc = nullptr;
	std::vector<GLfloat> verticesList;
	std::vector<SingleMesh*> shapeList;
	glm::vec3 meshPos;
};

#endif // !SINGLEMESH_H
