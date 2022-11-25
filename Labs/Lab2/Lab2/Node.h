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
* -- currentNodeName - pointer for current node
* -- isFolder - true if new element is Folder
* -- name - element name* 
*/
void addFolder(Node* currentNodeName, std::string name);

/**
* add new child element for current node
* -- currentNodeName - pointer for current node
* -- isFolder - true if new element is Folder
* -- name - element name*
*/
void addFile(Node* currentNodeName, std::string name);

/**
*	delete child element in this node
*  -- node - current node
*  -- nodeName - node name for delete
*/
void deleteElement(Node* node, std::string nodeName);

Node* gotoParent(Node* node);

/*
* recursive print node for console
*/
void printNode(Node*);

bool isEmpty(Node*);

///**
//*	For delete node need:
//*		0) put isFolder value
//*		1) go to parent current node
//*		2) if node == isFolder use removeElement for folders list, else removeElement is files;
//*		3) remove pointer;
//*/
//void deleteElement(Node* node, std::string nodeName);