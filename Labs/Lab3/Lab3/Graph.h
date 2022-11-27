#pragma once
#include "GraphElement.h"

class Graph
{
private:
	std::vector<GraphElement> graphElement;
public:
	void addElement(GraphElement*);
};

