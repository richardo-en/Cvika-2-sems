#include <stdio.h>
#include <stdlib.h>

#define PCAT

typedef struct
{
    unsigned den : 5;
    unsigned mesiac : 4;
    unsigned rok : 7;
} DATUM;

void main()
{
    DATUM pom;
    pom.den = 22;
    pom.mesiac = 5;
    pom.rok = 2023 - 1988;
#ifndef PCAT
    printf("datum: %2d:%2d:%4d \n", pom.den, pom.mesiac, pom.rok + 1988);
#endif
#undef PCAT
#ifdef PCAT
    printf("datum: %2d:%2d:%4d \n", pom.den, pom.mesiac, pom.rok + 1980);
#endif
}
