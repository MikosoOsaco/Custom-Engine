#include "MatrixStack.h"


MatrixStack::MatrixStack()
{
	glm::mat4 ident(1.0f), ident2(1.0);
	projectionStack.push(ident);
	modelStack.push(ident2);
}


MatrixStack::~MatrixStack()
{
}


void MatrixStack::orthographic(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax)
{
	projectionStack.top() = glm::ortho(xMin, xMax, yMin, yMax, zMin, zMax);
	projectionStackDirty = true;
}


void MatrixStack::perspective(float fovy, float aspect, float nearZ, float farZ)
{
	projectionStack.top() = glm::perspective(fovy, aspect, nearZ, farZ);
	projectionStackDirty = true;
}


const glm::mat4 MatrixStack::getProjectionMatrix() const
{
	if (projectionStack.empty())
	{
		return glm::mat4();
	}
	return projectionStack.top();
}


const glm::mat4 MatrixStack::getModelMatrix() const
{
	if (modelStack.empty())
	{
		return glm::mat4();
	}
	return modelStack.top();
}

const float* MatrixStack::getProjectionMatrixValue() const
{
	return glm::value_ptr(getProjectionMatrix());
}

const float* MatrixStack::getModelMatrixValue() const
{
	return glm::value_ptr(getModelMatrix());
}

void MatrixStack::getProjectionMatrixValue(float *values) const
{
	const float *vals = getProjectionMatrixValue();
	for (int i = 0; i < 16; i++) values[i] = vals[i];
}


void MatrixStack::getModelMatrixValue(float *values) const
{
	const float *vals = getModelMatrixValue();
	for (int i = 0; i < 16; i++) values[i] = vals[i];
}

void MatrixStack::setProjectionToIdentity()
{
	projectionStack.top() = glm::mat4(1.0);
	projectionStackDirty = true;
}


void MatrixStack::setModelViewToIdentity()
{
	modelStack.top() = glm::mat4(1.0);
	modelStackDirty = true;
}


void MatrixStack::pushModelView()
{
	modelStack.push(modelStack.top());
}


void MatrixStack::popModelView()
{
	if (!modelStack.empty())
	{
		modelStack.pop();
		modelStackDirty = true;
	}	
}

void MatrixStack::pushProjection()
{
	projectionStack.push(projectionStack.top());
}


void MatrixStack::popProjection()
{
	if (!projectionStack.empty())
	{
		projectionStack.pop();
		projectionStackDirty = true;
	}	
}


void MatrixStack::rotateBy(const glm::quat& q)
{
	float angle = glm::angle(q);
	glm::vec3 vect = glm::axis(q);

	modelStack.top() = modelStack.top() * glm::rotate(angle, vect);
	modelStackDirty = true;
}

void MatrixStack::rotateBy(float angle, float vx, float vy, float vz)
{
	modelStack.top() = modelStack.top() * glm::rotate(angle, glm::vec3(vx, vy, vz));
	modelStackDirty = true;
}


void MatrixStack::scaleBy(float xFactor, float yFactor, float zFactor)
{
	modelStack.top() = modelStack.top() * glm::scale(glm::vec3(xFactor, yFactor, zFactor));
	modelStackDirty = true;
}


void MatrixStack::translateBy(float xAmt, float yAmt, float zAmt)
{
	modelStack.top() = modelStack.top() * glm::translate(glm::vec3(xAmt, yAmt, zAmt));
	modelStackDirty = true;
}

void MatrixStack::setFgColor(const glm::vec3& clr)
{
	fgColor = clr;
}

glm::vec3 MatrixStack::getFgColor() const
{
	return fgColor;
}


void MatrixStack::setBgColor(const glm::vec3& clr)
{
	bgColor = clr;
}

glm::vec3 MatrixStack::getBgColor() const
{
	return bgColor;
}

void MatrixStack::lookAt(const glm::vec3& posn, const glm::vec3& at, const glm::vec3& up)
{
	modelStack.top() = glm::lookAt(posn, at, up);
	modelStackDirty = true;
}

void MatrixStack::lookAt(float camX, float camY, float camZ, float atX, float atY, float atZ, float upX, float upY, float upZ)
{
	lookAt(glm::vec3(camX, camY, camZ), glm::vec3(atX, atY, atZ), glm::vec3(upX, upY, upZ));
	modelStackDirty = true;
}

bool MatrixStack::isModelViewDirty() const
{
	return modelStackDirty;
}


bool MatrixStack::isProjectionDirty() const
{
	return projectionStackDirty;
}


void MatrixStack::clearModelViewDirty()
{
	modelStackDirty = false;
}


void MatrixStack::clearProjectionDirty()
{
	projectionStackDirty = false;
}