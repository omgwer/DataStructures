#pragma once
#include <string>
#include "List.h"

typedef struct Node {
	std::string  name;
	bool  isFolder;
	Node* parent;
	struct List* folders;
	struct List* files;
	Node() : parent(nullptr), isFolder(false), folders(nullptr), files(nullptr) {}
} Node;

void addElement(Node*);

void removeElement();

bool isEmpty();

void clear();