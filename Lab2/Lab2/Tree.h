#pragma once
#include <string>
#include <List.h>

struct Tree {
	std::string  name;
	bool  isFolder;
	Tree *father;
	List *childers;
};
