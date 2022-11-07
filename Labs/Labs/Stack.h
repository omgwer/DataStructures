#include "CommentData.h"
#include <string>

using namespace std;

typedef struct _stackStructure
{
	CommentData *commentData;
	_stackStructure *next;
} Stack, *PStack;

void push( int numberOfString, int numberOfPositionInString , string newCommentSymbol);

CommentData pop();

CommentData lookAtHead();

void clear();

bool isEmpty();