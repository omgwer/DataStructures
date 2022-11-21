#include <iostream>
#include <string>
#include "List.h"
#include "Tree.h"

void addElement(List* list, Tree* newTreeElement)
{	
	if (list->current == nullptr) {				// если список пустой, пишем в начало списка
		list->current = newTreeElement;
		list->next = nullptr;
		return;
	}

	std::string newName = newTreeElement->name; // для сортировки вставкой нужно пройтись по существующему списку
	bool isFind = false;

	List* varPtr = list;					// указатель на текущий элемент списка, по которому проходит итерация
	List* prevElementPtr = nullptr;				// указатель на предыдущий элемент списка

	while (!isFind) {			
		if (newName <= varPtr->current->name) { // если новое имя меньше чем текущее в списке,
			List *newElement = new List;
			newElement->current = newTreeElement;
			newElement->next = varPtr1;
			if (prevElementPtr != nullptr) {	
				prevElementPtr->next = newElement;
			}
			else {		
				List varPtr1 = *list;           // если нужно вставить первый элемент списка				
				newElement->next = &varPtr1;
				(*list) = *newElement;
			}
			isFind = true;
			continue;
		}		
		if (varPtr->next == nullptr) {   // если список кончился, создаем новый элемент и записываем его в конец
			List* newElement = new List;
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