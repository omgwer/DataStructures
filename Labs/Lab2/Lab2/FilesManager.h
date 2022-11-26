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
public:
	FileManager(std::string, std::string);

	bool isRun();
	
	FileManager* readCommand();

	FileManager* drawNode();

	FileManager* drawHelp();
};