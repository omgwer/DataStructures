#pragma once
#include "CommentData.h"
#include <string>

using namespace std;

struct _stackStructure
{
	CommentData *commentData;
	_stackStructure *next;
} Stack, *PStack;

void init();

void push( int numberOfString, int numberOfPositionInString , string newCommentSymbol);

CommentData pop();

CommentData lookAtHead();

void clear();

bool isEmpty();