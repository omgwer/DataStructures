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
� �.�.
�� ����, ���� ������ C, � ���� ���� ������ Documents � Users. � ������� ������ ����� ���� ����� ������. 
��������������� ��� ���: ���� ���� �������� �������, �� �� ��� ���� �� ��������.
��������� ������������ � ������� �� ����� ������.
2) ��������� ��� ������ ������ ������ ������ ����
String name;
Pointer father, down, right
3) �������� ���� ���������� ������
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