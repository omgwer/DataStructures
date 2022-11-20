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
	List* prevElementPtr = nullptr;		// ��������� �� ���������� ������� ������

	while (!isFind) {			
		if (newName <= varPtr->current->name) { // ���� ����� ��� ������ ��� ������� � ������,
			List *newElement = new List;
			newElement->current = newTreeElement;
			newElement->next = varPtr;
			if (prevElementPtr == nullptr) {	// ���� ����� �������� ������ ������� ������	
				list = newElement;   //������������ ������ ������, ��� ��� ����������� ������� � ������ ������.				
			}
			else {
				prevElementPtr->next = newElement;				
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
	while (var->next != nullptr) {
		std::string  test = list->current->name;
		std::cout << "name = " << list->current->name << std::endl;
		var = var->next;
 	}
}