#include <iostream>
#include <string>
#include "ListElement.h"
#include "Tree.h"

void addElement(ListElement* list, Tree* newTreeElement)
{
	if (list->current == nullptr) {    // ���� ������ ������, ����� � ������ ������
		list->current = newTreeElement;
		list->next = nullptr;
		return;
	}

	std::string newName = newTreeElement->name; // ��� ���������� �������� ����� �������� �� ������������� ������
	bool isFind = false;

	ListElement* varPtr = list;             // ��������� �� ������� ������� ������, �� �������� �������� ��������
	ListElement* prevElementPtr = nullptr;  // ��������� �� ���������� ������� ������

	while (!isFind) {			
		if (newName <= varPtr->current->name) { // ���� ����� ��� ������ ��� ������� � ������,
			ListElement *newElement = new ListElement;
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
			ListElement* newElement = new ListElement;
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

bool isEmpty(ListElement* list) {
	return list->current == nullptr;
}

Tree* getElement(ListElement *test, std::string)
{
	Tree* ListElement = new Tree;
	return ListElement;
}
