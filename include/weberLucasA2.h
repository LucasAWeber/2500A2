#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20
#define MAX_WORDS 50

char * readFile (char * filename);

char * stretchMe (char * aStringToStretch);

int splitMe (char * aStringToSplit, char static2D [MAX_WORDS][MAX_LENGTH]);

int shrinkMe (char * aStringToShrink);

bool isItAPalindrome (char * aString);

void printSuffixes (char * aString, int whichWord, char * desiredSuffix);