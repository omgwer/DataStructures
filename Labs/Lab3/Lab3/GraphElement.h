#pragma once
#include <vector>
#include "LinkNode.h"

class GraphElement
{
public:
	int graphElementNumber;   // ����� �������

	std::vector<class LinkNode> links;   // ������ �������� ���� (������ �� �������, ������������ ��� )
};

