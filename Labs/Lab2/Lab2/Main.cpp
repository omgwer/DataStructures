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
#include "List.h"
#include "Node.h"

int main() {
	List* newTestList = new List;
	Node* test1 = new Node;
	Node* test2 = new Node;
	Node* test3 = new Node;
	Node* test4 = new Node;
	test1->name = "a";
	test2->name = "b";
	test3->name = "c";
	test4->name = "d";
	addElement(newTestList, test2);
	addElement(newTestList, test3);
	addElement(newTestList, test1);
	addElement(newTestList, test2);
	deleteElement(newTestList, "b");	
	printList(newTestList);
	Node* test = getElement(newTestList, "c");
	bool kek1 = isExist(newTestList, "a");

	return 1;	
}