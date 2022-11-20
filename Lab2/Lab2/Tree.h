#pragma once
#include <string>
#include "List.h"

typedef struct Tree {
	std::string  name;
	bool  isFolder;
	Tree* father;
	struct List* folders;
	struct List* files;
	Tree() : father(nullptr), isFolder(false), folders(nullptr), files(nullptr) {}
} Tree;

void addElement(Tree);

void removeElement();

bool isEmpty();

void clear();