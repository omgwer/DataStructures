#pragma once
#include "CommentData.h"

using namespace std;

typedef struct _stackStructure
{
	CommentData *commentData;
	_stackStructure *next;
} Stack, *PStack;

void push( int numberOfString, int numberOfPositionInString );

CommentData pop();

void lookAtHead();

void clear();

bool isEmpty();