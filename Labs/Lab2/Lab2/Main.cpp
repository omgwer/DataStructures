/*
17. ����������  �  ������  ��  �������  ������   ����������
��������  �  �������  ������.���������� ���������� ���������
�������� :
1) �������� ������ � ������ �� �����;
2) ����� ������ ����� �  ������  �������(��������� �����,
������ �� ������� � �.�.);
3) �������������  ������ ��� �������� ����� ����� � ������,
�� ��������������, �����������, �������� � ��������.
4) ���������� ������ � �����(13).
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