#pragma once

#include <RobEngine\Window.h>
#include <RobEngine\GameEngine.h>
#include <RobEngine\OpenGLRenderer.h>
#include <RobEngine\MaterialManager.h>
#include <RobEngine\AABB.h>
#include <RobEngine\MatrixStack.h>

#include "glut-3.7.6-bin\glut.h"


class demoApp : public GameEngine
{
private:

	OpenGLRenderer* GLrender;

	AABB* box1;
	AABB* box2;

	MatrixStack matrixStack;

	Window *window;

public:
	demoApp();
	~demoApp();
	virtual void onStart() override;
	virtual void onEnd() override;
	virtual void render() override;/*
	void addRenderObject(int prim);*/

};
