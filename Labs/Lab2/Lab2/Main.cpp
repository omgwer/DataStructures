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