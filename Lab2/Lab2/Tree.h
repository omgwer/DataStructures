#pragma once
#include <string>
#include "ListElement.h"

typedef struct _tree {
	std::string  name;
	bool  isFolder;
	_tree* father;
	ListElement* test;
	_tree() : father(nullptr), isFolder(false) {}
} Tree;

void addElement(Tree);

void removeElement();

bool isEmpty();

void clear();