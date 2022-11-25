#include <iostream>
#include <string>
#include "List.h"
#include "Node.h"

void addElement(Node* currentNode, bool isFolder, std::string name) {
	if (!currentNode->isFolder) {
		std::cout << "This node is not folder!!!" << std::endl;
		return;
	}
	Node* newNode = new Node;
	newNode->name = name;
	newNode->isFolder = isFolder;
	newNode->parent = currentNode;
	if (isFolder) {
		if (isExist(currentNode->files, name) {
			std::cout << "Folder is this name is exist!">> std::endl;
		})
		addFolder(currentNode, newNode);
	}
	else {
		addFile(currentNode, newNode);
	}
}

void addFolder(Node* currentNode, Node* fileNode) {
	if (currentNode->folders == nullptr) {
		currentNode->folders = new List;
	}
	addElement(currentNode->folders, fileNode);
}

void addFile(Node* currentNode, Node* fileNode) {
	if (currentNode->files == nullptr) {
		currentNode->files = new List;
	}
	addElement(currentNode->files, fileNode);
}