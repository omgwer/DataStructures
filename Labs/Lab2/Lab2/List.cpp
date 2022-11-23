#include <iostream>
#include <string>
#include "List.h"
#include "Node.h"
#include "ListElement.h"

void addElement(List* list, Node* newNodeElement)
{	
	ListElement* newElement = new ListElement;
	newElement->node = newNodeElement;

	if (isEmpty(list)) {				          // ���� ������ ������, ����� � ������ ������
		newElement->next = nullptr;
		list->next = newElement;
		return;
	}	
	ListElement* iterableListElement = list->next;		 // ��������� �� ������� ������� ������, �� �������� �������� ��������
	ListElement* prevListElement = nullptr;					 // ��������� �� ���������� ������� ������
	bool isFind = false;
	while (!isEmpty(iterableListElement)) {
		if (newNodeElement->name <= iterableListElement->node->name) { // ���� ����� ��� ������ ��� ������� � ������,			
			if (prevListElement != nullptr) {
				newElement->next = iterableListElement;
				prevListElement->next = newElement;
			}
			else {
				newElement->next = list->next;
				list->next = newElement;
			}
			return;
		}		
		if (iterableListElement->next == nullptr) {				// ���� ������ ��������, ������� ����� ������� � ���������� ��� � �����
			newElement->next = nullptr;
			iterableListElement->next = newElement;
			return;
		}
		prevListElement = iterableListElement;					// ���������� ���������� ������� ������
		iterableListElement = iterableListElement->next;		// ��������� �� ������ ������
	}
}

void deleteElement(List* list, std::string elementName) {
	if (isEmpty(list)) {
		return;
	}
	ListElement* iterableListElement = list->next;
	ListElement* prevListElement = nullptr;

	while (!isEmpty(iterableListElement)) {
		if (iterableListElement->node->name == elementName) {  // ���� ��� ����� �������, �������
			if (prevListElement == nullptr) {
				
				return;
			}
			if (iterableListElement->next == nullptr) {
				prevListElement->next = nullptr;
				return;
			}
			


			clear(iterableListElement->node->folders);
			clear(iterableListElement->node->files);
		}
		prevListElement = iterableListElement;
		iterableListElement = iterableListElement->next;
	}
}

bool isEmpty(List* list) {
	return list->next == nullptr;
}

bool isEmpty(ListElement* listElement) {
	return listElement == nullptr;
}

void printList(List* list) {
	ListElement* listElement = list->next;	
	while (!isEmpty(listElement)) {
		std::cout << "name = " << listElement->node->name << std::endl;
		listElement = listElement->next;
 	}
	std::cout << "name = " << listElement->node->name << std::endl;
}

void clear(List* list) {
	if (isEmpty(list)) {
		return;
	}
	ListElement* listElement = list->next;
	while (!isEmpty(listElement)) {
		clear(listElement);
		ListElement* newListElement = listElement->next;
		delete listElement;
		listElement = newListElement;
	}	
}

void clear(ListElement* listElement) {
	clear(listElement->node->folders);
	clear(listElement->node->files);	
	delete listElement->node->folders;
	delete listElement->node->files;
	delete listElement->node->parent;
}