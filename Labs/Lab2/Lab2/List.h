#pragma once
#include "ListElement.h"

typedef struct List {
	ListElement* next;

	List() : next(nullptr) {}
};


void addElement(List*, Node*);

//Tree* getElement(List* list, std::string elementName);

void deleteElement(List*, std::string);

void clear(List*);

void clear(ListElement*);

bool isEmpty(List*);

bool isEmpty(ListElement*);

void printList(List*);