#pragma once
#include <string>
#include "Tree.h"

struct List {
	Tree *current;
	List *next;

	List() : current(nullptr), next(nullptr) {}
};

void addElement(List, Tree);

Tree getElement(List, std::string);

void deleteElement(List, std::string);

void clear(List);

bool isEmpty(List);