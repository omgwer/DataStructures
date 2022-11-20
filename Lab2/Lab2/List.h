#pragma once
#include <string>
#include "Tree.h"

typedef struct List {
	struct Tree* current;
	List* next;

	List() : current(nullptr), next(nullptr) {}
};

void addElement(List* list, Tree* newTreeElement);

//Tree* getElement(List* list, std::string elementName);

//void deleteElement(List, std::string);
//
//void clear(List);
//
//bool isEmpty(List* list);

void printList(List* list);