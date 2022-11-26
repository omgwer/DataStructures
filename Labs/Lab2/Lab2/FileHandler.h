#pragma once
#include <string>
#include "Node.h"

int getDeepInString(std::string);

bool isFile(std::string);

std::string getElementName(int deep, std::string string);

Node* readFile(std::string);

void printNode(Node* , std::ofstream* , int );

void writeFile(Node* , std::string);

void recursivePrint(Node* node, std::ofstream* out, int deep);