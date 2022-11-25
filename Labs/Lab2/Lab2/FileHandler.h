#pragma once
#include <string>
#include "Node.h"

int getDeepInString(std::string);

bool isFile(std::string);

std::string getElementName(int deep, std::string string);

Node* readFile(std::string);

void writeFile(Node* , std::string);