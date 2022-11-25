#include <string>
#include <fstream>
#include <iostream>
#include "Node.h"
#include "List.h"
#include "FileHandler.h"

Node* readFile(std::string fileName) {
	int currentDeep = 0; // глубина относительно основной папки	
	Node* rootNode = new Node;  //точка входа в структуру
	Node* variableNode = rootNode;
	rootNode->isFolder = true;
	rootNode->parent = nullptr;

	std::ifstream in(fileName);
	if (in.is_open()) {
		std::string variableElement;
		while (getline(in, variableElement)) {
			int newDeep = getDeepInString(variableElement);
			std::string elementName = getElementName(newDeep, variableElement);
			bool elementNameIsFile = isFile(elementName);
			if (currentDeep == newDeep) { //мы находимся на одном уровне чтобы добавить элемент нужно еще раз вернуться вверх
				if (variableNode->parent == nullptr) { // это для первой папки
					rootNode->name = elementName;
				}				
			}
		}
	}

	return rootNode;
}

int getDeepInString(std::string string) {
	int deep = 0;
	for (int i = 0; i < string.size(); i++) {
		if (string[i] == '.') {
			deep++;
		}
	}
	return deep;
}

std::string getElementName(int deep ,std::string string) {
	return string.substr(deep);
}

bool isFile(std::string string) {
	bool result = string.find('.') == std::string::npos;
	if (result)
		return false;
	else
		return true;
}

void writeFile(Node*, std::string) {
}