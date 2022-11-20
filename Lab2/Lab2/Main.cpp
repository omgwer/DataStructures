/*
17. Информация  о  файлах  на  жестких  дисках   компьютера
записана  с  помощью  дерева.Обеспечить выполнение следующих
операций :
1) загрузку дерева в память из файла;
2) обход дерева папок в  режиме  диалога(раскрытие папок,
подъем на уровень и т.п.);
3) корректировку  дерева при создании новых папок и файлов,
их переименовании, копировании, переносе и удалении.
4) сохранение дерева в файле(13).
*/
/*
1) в текстовом файле расписываешь структуру формата:
C
.Documents
..doc.doc
.Users
..Alexey
И т.д.
То есть, есть корень C, у него есть листья Documents и Users. У каждого уровня может быть много листев. 
Организовывется это так: если есть дочерний элемент, то он идёт вниз от текущего.
Остальные прицепляются к первому по ветке вправо.
2) структура для лучшей записи дерева должна быть
String name;
Pointer father, down, right
3) считывая файл заполняешь дерево
*/

#include <iostream>
#include "Tree.h"
#include "List.h"

int main() {
	List* newTestList = new List;
	Tree* test1 = new Tree;
	Tree* test2 = new Tree;
	Tree* test3 = new Tree;

	test1->name = "bbb";
	test2->name = "aaa";
	test3->name = "ccc";

	addElement(newTestList, test3);
	addElement(newTestList, test2);
	addElement(newTestList, test1);

	printList(newTestList);
	
}