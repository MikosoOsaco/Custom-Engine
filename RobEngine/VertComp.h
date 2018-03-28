#pragma once
#ifndef VERTEXCOMPONENT_H
#define VERTEXCOMPONENT_H

class VertexComponent
{
public:
	VertexComponent() : type(NONE3F), offset(0) {};
	~VertexComponent() {};

	enum VertexType {
		NONE2F,
		NONE3F,
		NONE4F,
		VERTICIES3F,
		NORMAL3F,
		UV3F,
		COLOUR3F,
		COLOUR4F,
		TEXTURE2F,
	};

	int getSize();
	int getFloats();

	float *x, *y, *z, *a = nullptr;
	VertexType type;
	int offset;
};

#endif