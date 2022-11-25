#include <iostream>
#include <string>
#include "List.h"
#include "Node.h"
#include "ListElement.h"

void addElement(List* list, Node* newNodeElement)
{	
	ListElement* newElement = new ListElement;
	newElement->node = newNodeElement;

	if (isEmpty(list)) {				          // если список пустой, пишем в начало списка
		newElement->next = nullptr;
		list->next = newElement;
		return;
	}	
	ListElement* iterableListElement = list->next;		 // указатель на текущий элемент списка, по которому проходит итерация
	ListElement* prevListElement = nullptr;					 // указатель на предыдущий элемент списка
	bool isFind = false;
	while (!isEmpty(iterableListElement)) {
		if (newNodeElement->name <= iterableListElement->node->name) { // если новое имя меньше чем текущее в списке,			
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
		if (iterableListElement->next == nullptr) {				// если список кончился, создаем новый элемент и записываем его в конец
			newElement->next = nullptr;
			iterableListElement->next = newElement;
			return;
		}
		prevListElement = iterableListElement;					// записываем предыдущий элемент списка
		iterableListElement = iterableListElement->next;		// двигаемся по списку вправо
	}
}

void deleteElement(List* list, std::string elementName) {
	if (isEmpty(list)) {
		return;
	}
	ListElement* iterableListElement = list->next;
	ListElement* prevListElement = nullptr;
	while (!isEmpty(iterableListElement)) {
		if (iterableListElement->node->name == elementName) {  // если имя файла совпало, очищаем списки ноды и удаляем указатели на списки
			clear(iterableListElement->node->folders);
			clear(iterableListElement->node->files);
			delete iterableListElement->node->folders;
			delete iterableListElement->node->files;
			if (prevListElement == nullptr && iterableListElement->next == nullptr) {	// удаляемый элемент списка один
				list->next = nullptr;
				delete iterableListElement;
				return;
			}
			if (prevListElement == nullptr) {  //удаляемый элемент первый в списке, смещаем указатель начала списка вперед, удаляем указатель
				list->next = iterableListElement->next;
				delete iterableListElement;
				return;
			}
			if (iterableListElement->next == nullptr) {		//удаляемый элемент последний в списке		
				prevListElement->next = nullptr;
				delete iterableListElement;
				return;
			}
			// элемент не первый и не последний в списке
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
	if (isEmpty(list) || isEmpty(list->next)) {    //проверяем что список не пустой, надеемся на ленивое или
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