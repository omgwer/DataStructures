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
/*
1) � ��������� ����� ������������ ��������� �������:
C
*/

#include <iostream>
#include "List.h"
#include "Node.h"
#include "FileHandler.h"

std::string host = "E:\\Projects\\DataStructures\\Labs\\Lab2\\Lab2\\Files";
std::string inFile = host + "\\in.txt";
std::string outFile = host + "\\out.txt";

int main() {	
	Node* node = readFile(inFile);
	writeFile(node, outFile);

	return 1337;	
}