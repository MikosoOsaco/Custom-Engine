#ifndef VERTEXDESCRIPT_H
#define VERTEXDESCRIPT_H
#pragma once

#include <vector>

class VertexComponentDescriptor
{
public:

	enum VertexComponentType
	{
		VERTEX_COMP_TYPE_NULL = 0,
		VERTEX_COMP_TYPE_VERTEX_3F,
		VERTEX_COMP_TYPE_NORMAL_3F,
		VERTEX_COMP_TYPE_COLOR_3F,
		VERTEX_COMP_TYPE_COLOR_4F,
		VERTEX_COMP_TYPE_UV_2F
	};

	VertexComponentType type;

	//the offset in bytes of this comp from the start of the comps
	int offset;


	VertexComponentDescriptor() :
		type(VERTEX_COMP_TYPE_NULL), offset(0) {}; //type = null, offset = 0

	int getSize();
	int getNumFloats();
};

class VertexDescriptor
{
private:

	int compIndex[5];
	int stride = 0;

public:
	std::vector<VertexComponentDescriptor> compList;

	VertexDescriptor();

	int getStride() const;
	void addComponent(VertexComponentDescriptor::VertexComponentType typ);
	int getSize() const;

	VertexComponentDescriptor getComponent(int index) const;
	int getIndexForComponent(VertexComponentDescriptor::VertexComponentType typ) const;
};


#endif // !VERTEXDESCRIPT_H
