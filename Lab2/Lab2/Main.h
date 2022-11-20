#pragma once

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
