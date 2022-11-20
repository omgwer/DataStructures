#pragma once
#include <string>
#include "Tree.h"

typedef struct ListElement {
	Tree* current;
	ListElement* next;

	ListElement() : current(nullptr), next(nullptr) {}
} ListElement;

void addElement(ListElement*, Tree*);

Tree* getElement(ListElement, std::string);

void deleteElement(ListElement, std::string);

void clear(ListElement);

bool isEmpty(ListElement);