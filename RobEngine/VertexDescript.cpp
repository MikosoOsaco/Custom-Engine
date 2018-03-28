#include "VertexDescript.h"

int VertexComponentDescriptor::getSize()
{
	int result = 0;

	switch (type)
	{
		case VERTEX_COMP_TYPE_VERTEX_3F:
		case VERTEX_COMP_TYPE_NORMAL_3F:
		case VERTEX_COMP_TYPE_COLOR_3F:
			result = 3 * sizeof(float);
			break;
		case VERTEX_COMP_TYPE_COLOR_4F:
			result = 4 * sizeof(float);
			break;
		case VERTEX_COMP_TYPE_UV_2F:
			result = 2 * sizeof(float);
			break;
	}

	return result;
}

int VertexComponentDescriptor::getNumFloats()
{
	int result = 0;

	switch (type)
	{
	case VERTEX_COMP_TYPE_VERTEX_3F:
	case VERTEX_COMP_TYPE_NORMAL_3F:
	case VERTEX_COMP_TYPE_COLOR_3F:
		result = 3;
		break;
	case VERTEX_COMP_TYPE_COLOR_4F:
		result = 4;
		break;
	case VERTEX_COMP_TYPE_UV_2F:
		result = 2;
		break;
	}

	return result;
}

VertexDescriptor::VertexDescriptor()
{
	stride = 0;
}

int VertexDescriptor::getStride() const
{
	return stride;
}

void VertexDescriptor::addComponent(VertexComponentDescriptor::VertexComponentType typ)
{
	VertexComponentDescriptor desc;

	desc.type = typ;
	desc.offset = stride;
	stride += desc.getSize();
	compList.push_back(desc);
	compIndex[typ - 1] = compList.size() - 1;
}

int VertexDescriptor::getSize() const
{
	return compList.size();
}

VertexComponentDescriptor VertexDescriptor::getComponent(int index) const
{
	VertexComponentDescriptor result;

	result = compList[index];
	return result;
}

int  VertexDescriptor::getIndexForComponent(VertexComponentDescriptor::VertexComponentType typ) const
{
	return compIndex[typ - 1];
}