#pragma once
#include <vector>
#include "LinkNode.h"

class GraphElement
{
public:
	int graphElementNumber;   // номер вершины

	std::vector<class LinkNode> links;   // массив структур вида (ссылка на вершину, максимальный вес )
};

