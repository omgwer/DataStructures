#pragma once
#include "FileHandler.h"
#include "Node.h"
#include "ListElement.h"

class FileManager {
private:
	std::string outFilePath;
	Node* variableNode;
	Node* rootNode;
	bool isRunProgram;
	Node* buffer;
	bool isCut;
public:
	FileManager(std::string, std::string);

	bool isRun();
	
	FileManager* readCommand();

	FileManager* drawNode();

	FileManager* drawHelp();
};