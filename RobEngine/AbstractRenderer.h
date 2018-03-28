#ifndef ABSTRACT_RENDERER_H
#define ABSTRACT_RENDERER_H
#pragma once

class AbstractRenderer
{

public:
	AbstractRenderer();
	~AbstractRenderer();
	
	virtual void RenderPrimitive(int prim) = 0;

};

#endif // !ABSTRACT_RENDERER_H
