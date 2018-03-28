#pragma once
#ifndef VERTEXDESCRIPTOR_H
#define VERTEXDESCRIPTOR_H

#include <vector>
#include "VertComp.h"

class VertexDescriptor
{
public:
	VertexDescriptor();
	~VertexDescriptor();

	void AddComponent(VertexComponent::VertexType type);
	int GetSize() const;
	VertexComponent GetComponent(int index) const;

	std::vector<VertexComponent> componentList;
	int stride = 0;
};

#endif