#include "OpenGLRenderer.h"

OpenGLRenderer::OpenGLRenderer()
{
	window = new Window("Rob HUMDINGER", 800, 600);

	//Initialize glew and get the error message from the initialize function
	if (GLEW_OK != glewInit()) {
		std::cerr << "Failed to initialize GLEW. \n";
	}

	camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));


	glEnable(GL_DEPTH_TEST);
	prim = NONE;
}

OpenGLRenderer::~OpenGLRenderer()
{

	window->~Window();
}

void OpenGLRenderer::PreRender()
{

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	MeshManager::GetInstance()->Get(std::string("myShape"))->PreRender();
	//MeshManager::GetInstance()->Get(std::string("myShape2"))->PreRender();
	camera->updateMatrices();
	// note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
	ShaderManager::GetInstance()->Get(std::string("myShader"))->setMat4("projection", camera->projectionM);
	ShaderManager::GetInstance()->Get(std::string("myShader"))->setMat4("view", camera->viewM);
}

void OpenGLRenderer::Render()
{
	currentFrame = (float)SDL_GetTicks() / 1000;
	deltaTime = currentFrame - lastFrame;
	lastFrame = currentFrame;

	window->pollEvents();
	switch (window->event.type)
	{
	case SDL_KEYDOWN:
		switch (window->event.key.keysym.sym)
		{
		case SDLK_UP:
			camera->ProcessKeyboard(FORWARD, deltaTime);
			break;
		case SDLK_DOWN:
			camera->ProcessKeyboard(BACKWARD, deltaTime);
			break;
		case SDLK_LEFT:
			camera->ProcessKeyboard(LEFT, deltaTime);
			break;
		case SDLK_RIGHT:
			camera->ProcessKeyboard(RIGHT, deltaTime);
			break;
		}
		break;

	default:
		break;
	}

	MeshManager::GetInstance()->Get(std::string("myShape2"))->meshPos += glm::vec3(0.0f, 0.001f, 0.0f);
	angle += deltaTime * 50.0f;
	shapeList[0]->Render();

	// Draw our first triangle
	glBindVertexArray(shapeList[0]->VAO);

	for (int i = 0; i < shapeList.size(); i++)
	{
		glm::mat4 model;
		model = glm::translate(model, shapeList[i]->meshPos);
		model = glm::rotate(model, glm::radians(angle), glm::vec3(0.5f, 1.0f, 0.0f));
		
		ShaderManager::GetInstance()->Get(std::string("myShader"))->setMat4("model", model);

		glDrawArrays(GL_TRIANGLES, 0, shapeList[i]->verticesList.size());
	}
	glBindVertexArray(0);

	//MeshManager::GetInstance()->Get(std::string("myShape"))->Render();
	//MeshManager::GetInstance()->Get(std::string("myShape2"))->Render();
}

void OpenGLRenderer::PostRender()
{
	MeshManager::GetInstance()->Get(std::string("myShape"))->PostRender();
	MeshManager::GetInstance()->Get(std::string("myShape2"))->PostRender();
	SDL_GL_SwapWindow(window->getWindow());
	window->clear();
}

void OpenGLRenderer::RenderPrimitive(int prim)
{
	if (prim == RenderPrim::NONE)
	{
		prim = NONE;
		//verticesList.clear();
	}
	else if (prim == RenderPrim::TRIANGLE)
	{/*
		prim = TRIANGLE;

		verticesList.clear();

		tempV.pos = glm::vec3(0.0f, 0.5f, 0.0f);
		verticesList.push_back(tempV);
		tempV.uv = glm::vec2(0.0f, 0.0f);
		verticesList.push_back(tempV);

		tempV.pos = glm::vec3(-0.5f, -0.5f, 0.0f);
		verticesList.push_back(tempV);
		tempV.uv = glm::vec2(1.0f, 0.0f);
		verticesList.push_back(tempV);

		tempV.pos = glm::vec3(0.5f, -0.5f, 0.0f);
		verticesList.push_back(tempV);
		tempV.uv = glm::vec2(1.0f, 1.0f);
		verticesList.push_back(tempV);

		MeshManager::GetInstance()->Get(std::string("myShape"))->addObject(verticesList);*/

	}
	else if (prim == RenderPrim::SQUARE)
	{/*
		prim = SQUARE;
		verticesList.clear();

		tempV.pos = glm::vec3(0.5f, 0.5f, 0.0f);
		verticesList.push_back(tempV);
		tempV.uv = glm::vec2(1.0f, 0.0f);
		verticesList.push_back(tempV);

		tempV.pos = glm::vec3(0.5f, -0.5f, 0.0f);
		verticesList.push_back(tempV);
		tempV.uv = glm::vec2(1.0f, 1.0f);
		verticesList.push_back(tempV);

		tempV.pos = glm::vec3(-0.5f, -0.5f, 0.0f);
		verticesList.push_back(tempV);
		tempV.uv = glm::vec2(0.0f, 1.0f);
		verticesList.push_back(tempV);


		tempV.pos = glm::vec3(-0.5f, -0.5f, 0.0f);
		verticesList.push_back(tempV);
		tempV.uv = glm::vec2(0.0f, 1.0f);
		verticesList.push_back(tempV);


		tempV.pos = glm::vec3(-0.5f, 0.5f, 0.0);
		verticesList.push_back(tempV);
		tempV.uv = glm::vec2(0.0f, 0.0f);
		verticesList.push_back(tempV);

		tempV.pos = glm::vec3(0.5f, 0.5f, 0.0f);
		verticesList.push_back(tempV);
		tempV.uv = glm::vec2(1.0f, 0.0f);
		verticesList.push_back(tempV);
		
		MeshManager::GetInstance()->Get(std::string("myShape"))->addObject(verticesList);*/
		//ShaderManager::GetInstance()->Get(std::string("myShader"))->setInt("texture1", 0);
	}
}