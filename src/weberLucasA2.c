#include "../include/weberLucasA2.h"

char * readFile (char * filename)
{
    FILE * fptr = fopen(filename, "r");
    char * ptr = malloc(sizeof(char)*2);
    int i = 0;
    
    while(!feof(fptr))
    {
        fscanf(fptr, "%c", &ptr[i]);
        i++;
        ptr = realloc(ptr, sizeof(char) * (i+1));
    }

    fclose(fptr);

    return ptr;
}

char * stretchMe (char * aStringToStretch)
{
    int stringLength = strlen(aStringToStretch);
    int intInput[stringLength];
    char * finalString = malloc(sizeof(char)*2);
    int currCharacter = 0;

    for (int i = 0; i < stringLength; i++)
    {
        intInput[i] = 0;
    }

    for (int i = 0; i < stringLength; i++)
    {
        while(intInput[i] <= 0)
        {
            scanf("%d", &intInput[i]);
        }
    }
    
    for (int i = 0; i < stringLength; i++)
    {
        for (int j = 0; j < intInput[i]; j++)
        {
            finalString[currCharacter] = aStringToStretch[i];
            currCharacter++;
            finalString = realloc(finalString, sizeof(char)*(currCharacter+2));
        }
    }
    finalString[currCharacter+1] = '\0';

    return finalString;
}

int splitMe (char * aStringToSplit, char static2D [MAX_WORDS][MAX_LENGTH])
{
    int words = 0;
    int letters = 0;
    if (aStringToSplit[0] != ' ' && aStringToSplit[0] != '\n')
    {
        words++;
    }
    for (int i = 0; i < strlen(aStringToSplit); i++)
    {
        if (aStringToSplit[i] == ' ' || aStringToSplit[i] == '\n')
        {
            if (aStringToSplit[i+1] != ' ' && aStringToSplit[i+1] != '\n' && aStringToSplit[i+1] != '\0')
            {
                static2D[words-1][letters] = '\0';
                words++;
                letters = 0;
            }
        }
        else
        {
            static2D[words-1][letters] = aStringToSplit[i];
            letters++;
        }
    }
    return words;
}

int shrinkMe (char * aStringToShrink)
{
    int punctuation = 0;
    char temp[strlen(aStringToShrink)];
    for (int i = 0; i < strlen(aStringToShrink); i++)
    {
        if (aStringToShrink[i] != '.' && aStringToShrink[i] != ':' && aStringToShrink[i] != ';' && aStringToShrink[i] != '?' && aStringToShrink[i] != '!')
        {
            temp[i-punctuation] = aStringToShrink[i];
        }
        else
        {
            punctuation++;
        }
    }

    temp[strlen(aStringToShrink) - punctuation] = '\0';
    strcpy(aStringToShrink, temp);

    return punctuation;
}

bool isItAPalindrome (char * aString)
{
    char static2D [MAX_WORDS][MAX_LENGTH];
    int words;
    char temp[MAX_LENGTH];
    shrinkMe(aString);
    words = splitMe(aString, static2D);

    for (int i = 0; i < words; i++)
    {
        for (int j = strlen(static2D[i])-1; j >= 0; j--)
        {
            temp[(strlen(static2D[i])-1)-j] = static2D[i][j];
        }
        if (strcmp(static2D[i], temp) != 0)
        {
            return false;
        }
    }
    return true;
}

void printSuffixes (char * aString, int whichWord, char * desiredSuffix)
{
    int words;
    char static2D [MAX_WORDS][MAX_LENGTH];
    words = splitMe(aString, static2D);
    for (int i = 0; i < strlen(static2D[whichWord-1]); i++)
    {
        printf("%c", static2D[whichWord-1][i]);
        printf("%s\n", desiredSuffix);
    }
}