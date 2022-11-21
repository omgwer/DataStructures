#include <iostream>
#include <string>
#include "List.h"
#include "Tree.h"

void addElement(List* list, Tree* newTreeElement)
{	
	if (list->current == nullptr) {				// ���� ������ ������, ����� � ������ ������
		list->current = newTreeElement;
		list->next = nullptr;
		return;
	}

	std::string newName = newTreeElement->name; // ��� ���������� �������� ����� �������� �� ������������� ������
	bool isFind = false;

	List* varPtr = list;					// ��������� �� ������� ������� ������, �� �������� �������� ��������
	List* prevElementPtr = nullptr;				// ��������� �� ���������� ������� ������

	while (!isFind) {			
		if (newName <= varPtr->current->name) { // ���� ����� ��� ������ ��� ������� � ������,
			List *newElement = new List;
			newElement->current = newTreeElement;
			newElement->next = varPtr1;
			if (prevElementPtr != nullptr) {	
				prevElementPtr->next = newElement;
			}
			else {		
				List varPtr1 = *list;           // ���� ����� �������� ������ ������� ������				
				newElement->next = &varPtr1;
				(*list) = *newElement;
			}
			isFind = true;
			continue;
		}		
		if (varPtr->next == nullptr) {   // ���� ������ ��������, ������� ����� ������� � ���������� ��� � �����
			List* newElement = new List;
			newElement->current = newTreeElement;
			newElement->next = nullptr;
			varPtr->next = newElement;
			isFind = true;
			continue;
		}
		prevElementPtr = varPtr;   // ���������� ���������� ������� ������
		varPtr = varPtr->next;	   // ��������� �� ������ ������
	}
}

//bool isEmpty(List* list) {
//	return list->current == nullptr;
//}
//
//Tree* getElement(List *list, std::string elementName)
//{
//	Tree* ListElement = new Tree;
//	return ListElement;
//}

void printList(List* list) {
	List* var = list;
	if (var->current == nullptr) {
		return;
	}
	while (var->next != nullptr) {
		std::cout << "name = " << var->current->name << std::endl;
		var = var->next;
 	}
	std::cout << "name = " << var->current->name << std::endl;
}