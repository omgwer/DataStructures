#pragma once
#include "ListElement.h"

typedef struct List {
	ListElement* next;

	List() : next(nullptr) {}
} List;


void addElement(List*, Node*);

Node* getElement(List*, std::string);

bool isExist(List*, std::string);

void deleteElement(List*, std::string);

void clear(List*);

void clear(ListElement*);

bool isEmpty(List*);

bool isEmpty(ListElement*);

void printList(List*);