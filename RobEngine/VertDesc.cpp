#include "VertDesc.h"


VertexDescriptor::VertexDescriptor()
{
}


VertexDescriptor::~VertexDescriptor()
{
}

void VertexDescriptor::AddComponent(VertexComponent::VertexType typ)
{
	VertexComponent desc;

	desc.type = typ;
	desc.offset = stride;
	stride += desc.getSize();
	componentList.push_back(desc);
}

int VertexDescriptor::GetSize() const
{
	return componentList.size();
}

VertexComponent VertexDescriptor::GetComponent(int index) const
{
	VertexComponent result;

	result = componentList[index];
	return result;
}