#pragma once
#include "Node.h"

typedef struct ListElement {
	struct Node* node;
	ListElement* next;

	ListElement() : node(nullptr), next(nullptr) {}
} ListElement;
