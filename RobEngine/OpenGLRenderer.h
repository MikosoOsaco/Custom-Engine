#ifndef OPEN_GL_RENDERER_H
#define OPEN_GL_RENDERER_H
#pragma once

#include "AbstractRenderer.h"
#include "Shader.h"
#include "glut-3.7.6-bin\glut.h"
#include "Window.h"
#include "MeshManager.h"
#include "ShaderManager.h"
#include "Camera.h"

class OpenGLRenderer : public AbstractRenderer
{
private:


	enum RenderPrim
	{
		NONE,
		TRIANGLE,
		SQUARE
	};

	RenderPrim prim;
	Camera* camera;
	/*std::vector<Vertex> verticesList;
	Vertex tempV;*/
	// timing
	float currentFrame;
	float deltaTime = 0.0f;	// time between current frame and last frame
	float lastFrame = 0.0f;

	float angle = 0.0f;

public:
	Window *window;
	OpenGLRenderer();
	~OpenGLRenderer();
	void PreRender();
	void Render();
	void PostRender();

	void RenderPrimitive(int prim) override;


	std::vector<SingleMesh*> shapeList;
};

#endif // !OPEN_GL_RENDERER_H
