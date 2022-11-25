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
*/

#include <iostream>
#include "List.h"
#include "Node.h"
#include "FileHandler.h"

int main() {
	std::string textFile = "E:\\Projects\\DataStructures\\Labs\\Lab2\\Lab2\\Files\\in.txt";
	Node* node = readFile(textFile);
	
	printNode(node);

	return 1;	
}