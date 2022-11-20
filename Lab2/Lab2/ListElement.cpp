#include <iostream>
#include <string>
#include "ListElement.h"
#include "Tree.h"

void addElement(ListElement* list, Tree* newTreeElement)
{
	if (list->current == nullptr) {    // если список пустой, пишем в начало списка
		list->current = newTreeElement;
		list->next = nullptr;
		return;
	}

	std::string newName = newTreeElement->name; // для сортировки вставкой нужно пройтись по существующему списку
	bool isFind = false;

	ListElement* varPtr = list;             // указатель на текущий элемент списка, по которому проходит итерация
	ListElement* prevElementPtr = nullptr;  // указатель на предыдущий элемент списка

	while (!isFind) {			
		if (newName <= varPtr->current->name) { // если новое имя меньше чем текущее в списке,
			ListElement *newElement = new ListElement;
			newElement->current = newTreeElement;
			newElement->next = varPtr;
			if (prevElementPtr == nullptr) {	// если нужно вставить первый элемент списка	
				list = newElement;   //ПЕРЕПИСЫВАЕМ начало списка, так как добавляется элемент в начало списка.				
			}
			else {
				prevElementPtr->next = newElement;				
			}	
			isFind = true;
			continue;
		}		
		if (varPtr->next == nullptr) {   // если список кончился, создаем новый элемент и записываем его в конец
			ListElement* newElement = new ListElement;
			newElement->current = newTreeElement;
			newElement->next = nullptr;
			varPtr->next = newElement;
			isFind = true;
			continue;
		}
		prevElementPtr = varPtr;   // записываем предыдущий элемент списка
		varPtr = varPtr->next;	   // двигаемся по списку вправо
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
