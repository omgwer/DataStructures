#pragma once
#include <string>
#include "Tree.h"

typedef struct _list {
	Tree* current;
	_list* next;

	_list() : current(nullptr), next(nullptr) {}
} ListElement;

void addElement(ListElement*, Tree*);

Tree* getElement(ListElement, std::string);

void deleteElement(ListElement, std::string);

void clear(ListElement);

bool isEmpty(ListElement);