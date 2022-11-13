#include "CommentData.h"
#include "Stack.h"
#include <iostream>
#include <string>

using namespace std;

Stack *stackStartPtr;

void init() {
	stackStartPtr = NULL;
}

void push(int numberOfString, int numberOfPositionInString, string newCommentSymbol)
{
	Stack *current = new Stack();
	current->commentData = new CommentData();
	current->commentData->numberOfString = numberOfString;
	current->commentData->numberOfPositionInString = numberOfPositionInString;
	current->commentData->commentSymbol = newCommentSymbol;
	current->next = stackStartPtr;
	stackStartPtr = current;
}

CommentData pop() 
{
	if (isEmpty()) {
		throw exception("Stack is empty, check stack before pop!");
	}

	CommentData varData;
	varData.numberOfPositionInString = stackStartPtr->commentData->numberOfPositionInString;
	varData.numberOfString = stackStartPtr->commentData->numberOfString;	
	varData.commentSymbol = stackStartPtr->commentData->commentSymbol;
	_stackStructure *varPtr = stackStartPtr->next;
	delete stackStartPtr->commentData;  // delete Ptr to commentData
	delete stackStartPtr;               // delete Ptr to stack element
	stackStartPtr = varPtr;
	return varData;
}

CommentData lookAtHead() {
	CommentData varData;
	varData.numberOfPositionInString = stackStartPtr->commentData->numberOfPositionInString;
	varData.numberOfString = stackStartPtr->commentData->numberOfString;
	varData.commentSymbol = stackStartPtr->commentData->commentSymbol;
	return varData;
}

bool isEmpty() {
	return ( stackStartPtr == NULL) ? true : false;
}

void clear() {
	while (!isEmpty) {
		pop();
	}
}