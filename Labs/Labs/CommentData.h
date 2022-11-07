#pragma once
#include <string>

using namespace std;

typedef struct _commentDataStructure
{
	string commentSymbol;
	int numberOfString;
	int numberOfPositionInString;	
} CommentData, * PCommentData;