#include <stdio.h>

typedef union clovek
{
    char meno[20];
    char priezvisko[20];
    union clovek *matka;
    union clovek *otec;
    int pocet_deti;
    union clovek **deti;
} CLOVEK;

void main()
{
    CLOVEK pom;
    printf(" %d ", sizeof(pom));
}