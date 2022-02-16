#include "weberLucasA2.h"

char * readFile (char * filename)
{
    FILE * fptr = fopen(filename, "r");
    char * ptr = malloc(sizeof(char));
    int i = 0;

    while(!feof(fptr))
    {
        fscanf(fptr, "%c", ptr[i]);
        i++;
        ptr = realloc(ptr, sizeof(char));
    }

    return ptr;
}