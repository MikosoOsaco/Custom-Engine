#ifndef MATRIX_STACK_H
#define MATRIX_STACK_H

#include "glm-0.9.8.4\glm\glm.hpp"
#include "glm-0.9.8.4\glm\gtc\matrix_transform.hpp"
#include "glm-0.9.8.4\glm\gtx\transform.hpp"
#include "glm-0.9.8.4\glm\gtc\type_ptr.hpp"
#include "glm-0.9.8.4\glm\gtc\quaternion.hpp"
#include <stack>

class MatrixStack
{
private:
	std::stack<glm::mat4>		modelStack;
	std::stack<glm::mat4>		projectionStack;
	glm::vec3					fgColor;
	glm::vec3					bgColor;
	bool						modelStackDirty = true;
	bool						projectionStackDirty = true;

public:

	MatrixStack();
	~MatrixStack();

	void orthographic(float xMin, float xMax, float yMin, float yMax, float zMin, float zMax);
	void perspective(float fovy, float aspect, float nearZ, float farZ);
	void lookAt(const glm::vec3& posn, const glm::vec3& at, const glm::vec3& up);
	void lookAt(float camX, float camY, float camZ, float atX, float atY, float atZ, float upX, float upY, float upZ);
	
	const glm::mat4 getProjectionMatrix() const;
	const glm::mat4 getModelMatrix() const;
	const float* getProjectionMatrixValue() const;
	const float* getModelMatrixValue() const;

	void getProjectionMatrixValue(float *values) const;
	void getModelMatrixValue(float *values) const;
	void pushModelView();
	void popModelView();
	void pushProjection();
	void popProjection();

	void rotateBy(const glm::quat &quat);
	void rotateBy(float angle, float vx, float vy, float vz);
	void scaleBy(float xFactor, float yFactor, float zFactor);
	void translateBy(float xAmt, float yAmt, float zAmt);
	void setProjectionToIdentity();
	void setModelViewToIdentity();

	void setFgColor(const glm::vec3& clr);
	glm::vec3 getFgColor() const;
	void setBgColor(const glm::vec3& clr);
	glm::vec3 getBgColor() const;

	bool isModelViewDirty() const;
	bool isProjectionDirty() const;
	void clearModelViewDirty();
	void clearProjectionDirty();
};

#endif

