#include <string>
#include <fstream>
#include <iostream>
#include "Node.h"
#include "List.h"
#include "FileHandler.h"

Node* readFile(std::string fileName) {
	int currentDeep = 0; // глубина относительно основной папки	
	Node* rootNode = new Node;  //точка входа в структуру
	rootNode->isFolder = true;
	rootNode->parent = nullptr;
	std::ifstream in(fileName);
	std::string rootName;
	getline(in, rootName);
	rootNode->name = rootName;

	Node* variableNode = rootNode;
	std::string prevFolderName;

	if (in.is_open()) {
		std::string variableElement;
		while (getline(in, variableElement)) {
			int newDeep = getDeepInString(variableElement);
			std::string elementName = getElementName(newDeep, variableElement);
			bool elementNameIsFile = isFile(elementName);
			
			while (currentDeep >= newDeep) { // нужно подниматься наверх
				variableNode = gotoParent(variableNode);
				currentDeep--;
			} // ожидается что получится указатель на папку выше, чем тот который в variableElement
			 // сейчас ожидается что указатель currentDeep  меньше на 1 чем newDeep
			if (currentDeep == newDeep - 1) {  // добавляем в текущую ноду
				if (elementNameIsFile) {
					addFile(variableNode, elementName);
				}
				else {
					addFolder(variableNode, elementName);
					prevFolderName = elementName;
				}
			}
			else {  // нужно упаcть на уровень ниже
				variableNode = getElement(variableNode->folders, prevFolderName);
				currentDeep++;
				if (elementNameIsFile) {
					addFile(variableNode, elementName);
				}
				else {
					addFolder(variableNode, elementName);
					prevFolderName = elementName;
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
		else {
			return deep;
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

void writeFile(Node* node, std::string path) {	
	std::ofstream out(path);
	out.clear();
	int deep = 0;
	recursivePrint(node, &out, deep);
}

void recursivePrint(Node* node, std::ofstream* out, int deep) {
	printNode(node, out, deep);	
	deep++;
	if (node->folders != nullptr && !isEmpty(node->folders->next)) {  // if node has folders -> goto folder and ++deep	
		ListElement* variableListElement = node->folders->next;
		while (!isEmpty(variableListElement)) {
			recursivePrint(variableListElement->node, out, ++deep);
			variableListElement = variableListElement->next;
			--deep;
		}		
	}	
	if (node->files != nullptr && !isEmpty(node->files->next)) {	  // if node has files -> print all files 
		ListElement* variableListElement = node->files->next;
		while (!isEmpty(variableListElement)) {
			printNode(variableListElement->node, out, ++deep);
			variableListElement = variableListElement->next;
		}		
	}
}

void printNode(Node* node, std::ofstream* out, int deep) {
	if (node == nullptr)
		return;
	std::string deepBuild = "";
	for (int i = 0; i < deep; i++) {
		deepBuild.append(".");
		i++;
	}
	*out << deepBuild <<node->name << std::endl;
}