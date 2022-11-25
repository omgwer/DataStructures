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

/**
* add new child element for current node 
* -- Node* - pointer for current node
* -- isFolder - true if new element is Folder
* -- name - element name* 
*/
void addElement(Node* currentNodeName, bool isFolder, std::string name);

/**
*	For delete node need:
*		0) put isFolder value
*		1) go to parent current node
*		2) if node == isFolder use removeElement for folders list, else removeElement is files;
*		3) remove pointer;	
*/
void removeElement(Node* node, std::string nodeName);


/*
* recursive print node for console
*/
void printNode(Node*);