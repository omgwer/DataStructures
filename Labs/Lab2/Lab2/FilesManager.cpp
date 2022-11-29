#include <iostream>
#include "FileHandler.h"
#include "Node.h"
#include "ListElement.h"
#include "FilesManager.h"

FileManager::FileManager(std::string inFilePath, std::string outFile)
{
	rootNode = readFile(inFilePath);
	variableNode = rootNode;
	isRunProgram = true;
	outFilePath = outFile;
}

bool FileManager::isRun() {
	return isRunProgram;
}

FileManager* FileManager::readCommand()
{
	std::string command;
	std::string parameter;
	std::cout << "  Write your command: ";
	std::cin >> command;
	if (command != "exit" && command != "save" && command != "paste") {
		std::cin>> parameter;
	}

	if (command == "exit") {
		isRunProgram = false;
		std::cout << "~~~~~~~~~~~~~Thanks for use this application~~~~~~~~~~" << std::endl;
		return this;
	}
	else if (command == "cd") {
		if (parameter == "..") {
			if (variableNode->parent == nullptr) {
				std::cout << "  Error! This Directory is root!!!" << std::endl;
			}
			else {
				variableNode = variableNode->parent;
				return this;
			}
		}
		else {
			Node* delNode = getElement(variableNode->folders, parameter);
			if (delNode == nullptr) {
				std::cout << "  Error! Directory not found!!!" << std::endl;
			}
			else {
				variableNode = delNode;
				return this;
			}
		}			
	}
	else if (command == "md") {
		if (isExist(variableNode->folders, parameter)) {
			std::cout << "  Error! Directory is exits!!!" << std::endl;
		}
		else {
			addFolder(variableNode, parameter);
			return this;
		}		
	}
	else if (command == "rd") {
		if (isExist(variableNode->folders, parameter))
		{
			deleteElement(variableNode->folders, parameter);
			return this;
		}
		else 
		{
			std::cout << "  Error! Directory is not found!!!" << std::endl;
		}
	}
	else if (command == "ed") {
		std::string newName = "";
		std::cin >> newName;
		if (newName == "") {
			std::cout << "   Error! new name is empty!!!" << std::endl;
		} else if (isExist(variableNode->folders, newName)) {
			std::cout << "  Error! Directory with new name is exits!!!" << std::endl;
		}
		else if (!isExist(variableNode->folders, parameter)) {
			std::cout << "  Error! Directory with current name is not exist exits!!!" << std::endl;
		}
		else {
			Node* editNode = getElement(variableNode->folders, parameter);
			editNode->name = newName;
			return this;
		}
	}
	else if (command == "mf") {
		if (parameter.find(".") == -1) {
			std::cout << "  Error! File is not valid (need extenshion)" << std::endl;			
		}
		else {
			if (isExist(variableNode->files, parameter)) {
				std::cout << "  Error! File is exist!!!" << std::endl;
			}
			else {
				addFile(variableNode, parameter);
				return this;
			}
		}			
	}
	else if (command == "rf") {
		if (isExist(variableNode->files, parameter)) {
			deleteElement(variableNode->files, parameter);
			return this;
		}
		else {
			std::cout << "  Error! File is not found!!!" << std::endl;
		}
	}
	else if (command == "ef") {
		std::string newName = "";
		std::cin >> newName;
		if (newName == "") {
			std::cout << "   Error! new name is empty!!!" << std::endl;
		}
		if (newName.find(".") == -1) {
			std::cout << "  Error! new file name is not valid (need extenshion)" << std::endl;
		}
		else if (isExist(variableNode->files, newName)) {
			std::cout << "  Error! files with new name is exits!!!" << std::endl;
		}
		else if (!isExist(variableNode->files, parameter)) {
			std::cout << "  Error! file is not exist!!!" << std::endl;
		}
		else {
			Node* editNode = getElement(variableNode->files, parameter);
			editNode->name = newName;
			return this;
		}
	}
	else if (command == "save") {
		writeFile(rootNode, outFilePath);
		std::cout << "  Output file will be saved!!" << std::endl;
	}
	else if (command == "copy" || command == "cut") {
		if (command == "cut") {
			isCut = true;
		}
		else {
			isCut = false;
		}
		if (isExist(variableNode->files, parameter)) {
			buffer = getElement(variableNode->files, parameter);
		}
		else if (isExist(variableNode->folders, parameter)) {
			buffer = getElement(variableNode->folders, parameter);
		}
		else {
			std::cout << " File is not found!!!" << std::endl;
		}
	}
	else if (command == "paste") {
		if (variableNode->folders == nullptr) {
			variableNode->folders = new List;
		} 
		if (variableNode->files == nullptr) {
			variableNode->files = new List;
		}
		if (isCut) {
			if (buffer->isFolder) {				
				addElement(variableNode->folders, buffer);
				Node* parentDeleteElement = buffer->parent;
				deleteElement(parentDeleteElement->folders, buffer->name);
				return this;
			}
			else {
				addElement(variableNode->files, buffer);
				Node* parentDeleteElement = buffer->parent;
				deleteElement(parentDeleteElement->files, buffer->name);
				return this;
			}
		}
		else {
			if (buffer->isFolder) {
				addElement(variableNode->folders, buffer);
				return this;
			}
			else {
				addElement(variableNode->files, buffer);
				return this;
			}
		}
	}
	else {
		std::cout << "  Error in input command!" << std::endl;
	}
	system("pause");
	return this;
}

FileManager* FileManager::drawHelp() {
	std::cout << "\033[2J\033[1;1H";
	std::cout << "                  FILES MANAGER v0.1" << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << std::endl << "  Commands :" << std::endl;
	std::cout << "    cd {directory name}                      : change directory" << std::endl;
	std::cout << "    md {directory name}                      : make directory" << std::endl;
	std::cout << "    rd {directory name}                      : remove directory" << std::endl;
	std::cout << "    ed {directory name} {new directory name} : edit directory name" << std::endl;
	std::cout << "    mf {file name}                           : make file" << std::endl;
	std::cout << "    rf {file name}                           : remove file" << std::endl;	
	std::cout << "    copy {element name}                      : copy element" << std::endl;	
	std::cout << "    cut {element name}                       : copy element" << std::endl;	
	std::cout << "    paste {element name}                     : copy element" << std::endl;	
	std::cout << "    ef {file name} {new file name}           : edit file name" << std::endl;	
	std::cout << "    save                                     : save input changes" << std::endl;	
	std::cout << "    exit                                     : close this app" << std::endl;	
	std::cout << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	return this;
}

FileManager* FileManager::drawNode() {
	if (buffer == nullptr) {
		std::cout << "~~~~ Buffer is empty ~~~~~" << std::endl;
	}
	else {
		std::cout << buffer->name << " is push to buffer " << std::endl;
	}
	printNode(variableNode);
	std::cout << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	return this;
}