#include "SingleMesh.h"

SingleMesh::SingleMesh() 
{
	//vertDesc = new VertexDescriptor();
	//vertDesc->AddComponent(VertexComponent::VertexType::VERTICIES3F);
	//vertDesc->AddComponent(VertexComponent::VertexType::TEXTURE2F);

}

SingleMesh::SingleMesh(Mesh_Style mStyle)
{
	vertDesc = new VertexDescriptor();
	vertDesc->AddComponent(VertexComponent::VertexType::VERTICIES3F);
	verticesList.clear();
	if (mStyle == Mesh_Style::TRIANGLE)
	{
		verticesList = 
		{
			-0.5f, -0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f,  0.5f, 0.0f,
		};
	}
	else if (mStyle == Mesh_Style::SQUARE)
	{
		verticesList =
		{
			0.5f,  0.5f, 0.0f,
			-0.5f, 0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			0.5f, 0.5f, 0.0f,
			-0.5f,  -0.5f, 0.0f,
			0.5f,  -0.5f, 0.0f,
		};
	}
	else if (mStyle == Mesh_Style::CUBE)
	{
		verticesList =
		{
			-0.5f, -0.5f, -0.5f, 
			0.5f, -0.5f, -0.5f,  
			0.5f,  0.5f, -0.5f,  
			0.5f,  0.5f, -0.5f,  
			-0.5f,  0.5f, -0.5f, 
			-0.5f, -0.5f, -0.5f, 

			-0.5f, -0.5f,  0.5f, 
			0.5f, -0.5f,  0.5f,  
			0.5f,  0.5f,  0.5f,  
			0.5f,  0.5f,  0.5f,  
			-0.5f,  0.5f,  0.5f, 
			-0.5f, -0.5f,  0.5f, 

			-0.5f,  0.5f,  0.5f, 
			-0.5f,  0.5f, -0.5f, 
			-0.5f, -0.5f, -0.5f, 
			-0.5f, -0.5f, -0.5f, 
			-0.5f, -0.5f,  0.5f, 
			-0.5f,  0.5f,  0.5f, 

			0.5f,  0.5f,  0.5f,  
			0.5f,  0.5f, -0.5f,  
			0.5f, -0.5f, -0.5f,  
			0.5f, -0.5f, -0.5f,  
			0.5f, -0.5f,  0.5f,  
			0.5f,  0.5f,  0.5f,  

			-0.5f, -0.5f, -0.5f, 
			0.5f, -0.5f, -0.5f,  
			0.5f, -0.5f,  0.5f,  
			0.5f, -0.5f,  0.5f,  
			-0.5f, -0.5f,  0.5f, 
			-0.5f, -0.5f, -0.5f, 

			-0.5f,  0.5f, -0.5f, 
			0.5f,  0.5f, -0.5f,  
			0.5f,  0.5f,  0.5f,  
			0.5f,  0.5f,  0.5f,  
			-0.5f,  0.5f,  0.5f, 
			-0.5f,  0.5f, -0.5f, 
		};
	}
	CreateBuffers();
}


SingleMesh::SingleMesh(Mesh_Style mStyle, Material* mat)
{
	vertDesc = new VertexDescriptor();
	vertDesc->AddComponent(VertexComponent::VertexType::VERTICIES3F);
	vertDesc->AddComponent(VertexComponent::VertexType::TEXTURE2F);

	verticesList.clear();
	if (mStyle == Mesh_Style::TRIANGLE)
	{
		verticesList =
		{
			-0.5f, -0.5f, 0.0f,		0.0f, 1.0f,
			0.5f, -0.5f, 0.0f,		1.0f, 1.0f,
			0.0f,  0.5f, 0.0f,		0.5f, 0.0f
		};
	}
	else if (mStyle == Mesh_Style::SQUARE)
	{
		verticesList =
		{
			0.5f, 0.5f, 0.0f,		 1.0f, 0.0f,
			-0.5f, 0.5f, 0.0f,		 0.0f, 0.0f,
			-0.5f, -0.5f, 0.0f,		 0.0f, 1.0f,
			0.5f, 0.5f, 0.0f,		 1.0f, 0.0f,
			-0.5f, -0.5f, 0.0f,		 0.0f, 1.0f,
			0.5f, -0.5f, 0.0f,		 1.0f, 1.0f
		};
	}
	else if (mStyle == Mesh_Style::CUBE)
	{
		verticesList =
		{
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
			0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
			0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
			0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

			0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
			0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
			0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
		};
	}
	hasTexture = true;
	material = mat;

	CreateBuffers();
	mat->Init();
}

SingleMesh::~SingleMesh() {

}

void SingleMesh::CreateBuffers()
{
	//create VAO and bind
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	//create VBO and bind
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	//pass vertices data to buffer
	glBufferData(GL_ARRAY_BUFFER, verticesList.size() * sizeof(GLfloat), &verticesList[0], GL_STATIC_DRAW);
		for (int j = 0; j < vertDesc->GetSize(); j++)
	{
		//enable arrary
		glEnableVertexAttribArray(j);

		//assign data to the array you enabled		 first argm is the pointer to the attrib array	 0 = 0
		glVertexAttribPointer(j, vertDesc->componentList[j].getFloats(), GL_FLOAT, GL_FALSE, vertDesc->stride, (void*)(vertDesc->componentList[j].offset));
	}

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

//
//void SingleMesh::addObject(std::vector<Vertex> objectVerts)
//{
//	verticesList = objectVerts;
//	CreateBuffers();
//}
//
//void SingleMesh::addObject(int prim)
//{
//	Vertex tempV;
//
//	if (prim == Mesh_Style::NONE)
//	{
//		prim = NONE;
//		verticesList.clear();
//	}
//	else if (prim == Mesh_Style::TRIANGLE)
//	{/*
//	 prim = TRIANGLE;
//
//	 verticesList.clear();
//
//	 tempV.pos = glm::vec3(0.0f, 0.5f, 0.0f);
//	 verticesList.push_back(tempV);
//	 tempV.uv = glm::vec2(0.0f, 0.0f);
//	 verticesList.push_back(tempV);
//
//	 tempV.pos = glm::vec3(-0.5f, -0.5f, 0.0f);
//	 verticesList.push_back(tempV);
//	 tempV.uv = glm::vec2(1.0f, 0.0f);
//	 verticesList.push_back(tempV);
//
//	 tempV.pos = glm::vec3(0.5f, -0.5f, 0.0f);
//	 verticesList.push_back(tempV);
//	 tempV.uv = glm::vec2(1.0f, 1.0f);
//	 verticesList.push_back(tempV);
//
//	 MeshManager::GetInstance()->Get(std::string("myShape"))->addObject(verticesList);*/
//
//	}
//	else if (prim == Mesh_Style::SQUARE)
//	{
//		prim = SQUARE;
//		verticesList.clear();
//
//		tempV.pos = glm::vec3(0.5f, 0.5f, 0.0f);
//		verticesList.push_back(tempV);
//		tempV.uv = glm::vec2(1.0f, 0.0f);
//		verticesList.push_back(tempV);
//
//		tempV.pos = glm::vec3(0.5f, -0.5f, 0.0f);
//		verticesList.push_back(tempV);
//		tempV.uv = glm::vec2(1.0f, 1.0f);
//		verticesList.push_back(tempV);
//
//		tempV.pos = glm::vec3(-0.5f, -0.5f, 0.0f);
//		verticesList.push_back(tempV);
//		tempV.uv = glm::vec2(0.0f, 1.0f);
//		verticesList.push_back(tempV);
//
//
//		tempV.pos = glm::vec3(-0.5f, -0.5f, 0.0f);
//		verticesList.push_back(tempV);
//		tempV.uv = glm::vec2(0.0f, 1.0f);
//		verticesList.push_back(tempV);
//
//
//		tempV.pos = glm::vec3(-0.5f, 0.5f, 0.0);
//		verticesList.push_back(tempV);
//		tempV.uv = glm::vec2(0.0f, 0.0f);
//		verticesList.push_back(tempV);
//
//		tempV.pos = glm::vec3(0.5f, 0.5f, 0.0f);
//		verticesList.push_back(tempV);
//		tempV.uv = glm::vec2(1.0f, 0.0f);
//		verticesList.push_back(tempV);
//
//		//MeshManager::GetInstance()->Get(std::string("myShape"))->addObject(verticesList);
//		//ShaderManager::GetInstance()->Get(std::string("myShader"))->setInt("texture1", 0);
//	}
//}

void SingleMesh::PreRender()
{
	if (hasTexture)
	{
		//access shader
		material->PreRender();
	}

}

void SingleMesh::Render() 
{
	
	if (hasTexture)
	{
		material->Render();
	}

	//// Draw our first triangle
	//glBindVertexArray(VAO);

	//for (int i = 0; i < shapeList.size(); i++)
	//{
	//	glDrawArrays(GL_TRIANGLES, 0, verticesList.size());
	//}
	//glBindVertexArray(0);
}

void SingleMesh::PostRender()
{
	if (hasTexture)
	{
		material->PostRender();
	}
}