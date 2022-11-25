#include <iostream>
#include <string>
#include "List.h"
#include "Node.h"

void addFile(Node* currentNode, std::string name) {
	if (!currentNode->isFolder) {
		std::cout << "This node is not folder!!!" << std::endl;
		return;
	}
	Node* newNode = new Node;
	newNode->name = name;
	newNode->isFolder = false;
	newNode->parent = currentNode;	

	if (isExist(currentNode->files, name)) {
		std::cout << "File is this name = "<< name << " is exist!" << std::endl;
		return;
	};
	if (currentNode->files == nullptr) {
		currentNode->files = new List;
	}
	addElement(currentNode->files, newNode);
}

void addFolder(Node* currentNode, std::string name) {
	if (!currentNode->isFolder) {
		std::cout << "This node is not folder!!!" << std::endl;
		return;
	}
	Node* newNode = new Node;
	newNode->name = name;
	newNode->isFolder = true;
	newNode->parent = currentNode;	
	if (isExist(currentNode->folders, name)) {
		std::cout << "Folder is this name = " << name << " is exist!" << std::endl;
		return;
	};
	if (currentNode->folders == nullptr) {
		currentNode->folders = new List;
	}
	addElement(currentNode->folders, newNode);
}

void deleteElement(Node* node, std::string nodeName) {
	if (isEmpty(node)) {
		return;
	}
	if (isExist(node->folders, nodeName)) {
		deleteElement(node->folders, nodeName);
	}
	else {
		deleteElement(node->files, nodeName);
	}
}

bool isEmpty(Node* node) {
	return node == nullptr;
}

void printNode(Node* node) {
	if (!isEmpty(node)) {
		std::cout << std::endl;
		std::cout << "       " << node->name << ": " << std::endl;
		if (!isEmpty(node->folders)) {
			printList(node->folders);
		}
		if (!isEmpty(node->files)) {
			printList(node->files);
		}
		std::cout << std::endl;
	}
}

Node* gotoParent(Node* node) {
	if (node->parent == nullptr) {
		return nullptr;
	}
	return node->parent;
}