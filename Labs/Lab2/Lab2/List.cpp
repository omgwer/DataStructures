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
		if (iterableListElement->node->name == elementName) {  // ���� ��� ����� �������, ������� ������ ���� � ������� ��������� �� ������
			clear(iterableListElement->node->folders);
			clear(iterableListElement->node->files);
			delete iterableListElement->node->folders;
			delete iterableListElement->node->files;
			if (prevListElement == nullptr && iterableListElement->next == nullptr) {	// ��������� ������� ������ ����
				list->next = nullptr;
				delete iterableListElement;
				return;
			}
			if (prevListElement == nullptr) {  //��������� ������� ������ � ������, ������� ��������� ������ ������ ������, ������� ���������
				list->next = iterableListElement->next;
				delete iterableListElement;
				return;
			}
			if (iterableListElement->next == nullptr) {		//��������� ������� ��������� � ������		
				prevListElement->next = nullptr;
				delete iterableListElement;
				return;
			}
			// ������� �� ������ � �� ��������� � ������
			prevListElement->next = iterableListElement->next;
			delete iterableListElement;
			return;
		}
		prevListElement = iterableListElement;
		iterableListElement = iterableListElement->next;
	}
}

bool isEmpty(List* list) {
	if (list == nullptr) {
		return true;
	}
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
}

Node* getElement(List* list, std::string elementName) {
	if (isEmpty(list) || isEmpty(list->next)) {    //��������� ��� ������ �� ������, �������� �� ������� ���
		return nullptr;
	}
	ListElement* iterableListElement = list->next;
	while (!isEmpty(iterableListElement)) {
		if (iterableListElement->node->name == elementName) {
			return iterableListElement->node;
		}
		iterableListElement = iterableListElement->next;
	}
	return nullptr;
}

bool isExist(List* list, std::string elementName) {
	return getElement(list, elementName) != nullptr;
}