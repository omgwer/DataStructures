#pragma once
#include <string>
#include "ListElement.h"

typedef struct Tree {
	std::string  name;
	bool  isFolder;
	Tree* father;
	struct ListElement* folders;
	struct ListElement* files;
	Tree() : father(nullptr), isFolder(false), folders(nullptr), files(nullptr) {}
} Tree;

void addElement(Tree);

void removeElement();

bool isEmpty();

void clear();