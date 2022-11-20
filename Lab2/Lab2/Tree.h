#pragma once
#include <string>

struct Tree {
	std::string  name;
	bool  isFolder;
	Tree *father;

	//Tree() : father(nullptr), folders(nullptr), files(nullptr), isFolder(false) {}
};

void addElement(Tree);

void removeElement(Tree);

bool isEmpty();

void clear();