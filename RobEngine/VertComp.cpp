#include "VertComp.h"


int VertexComponent::getSize()
{
	int result = 0;

	switch (type)
	{
	case NONE3F:
	case VERTICIES3F:
	case NORMAL3F:
	case COLOUR3F:
		result = 3 * sizeof(float);
		break;
	case NONE4F:
	case COLOUR4F:
		result = 4 * sizeof(float);
		break;
	case NONE2F:
	case TEXTURE2F:
		result = 2 * sizeof(float);
		break;
	}

	return result;
}

int VertexComponent::getFloats()
{
	int result = 0;

	switch (type)
	{
	case NONE3F:
	case VERTICIES3F:
	case NORMAL3F:
	case COLOUR3F:
		result = 3;
		break;
	case NONE4F:
	case COLOUR4F:
		result = 4;
		break;
	case NONE2F:
	case TEXTURE2F:
		result = 2;
		break;
	}

	return result;
}
