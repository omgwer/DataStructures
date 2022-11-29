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


#include <iostream>
#include "List.h"
#include "Node.h"
#include "FileHandler.h"
#include "FilesManager.h"

std::string inFile = "Files\\in.txt";
std::string outFile = "Files\\out.txt";

int main() {	
	FileManager* fileManager = new FileManager(inFile, outFile);

	while (fileManager->isRun()) {
		fileManager->drawHelp()->drawNode()->readCommand();
	}

	return 1337;	
}