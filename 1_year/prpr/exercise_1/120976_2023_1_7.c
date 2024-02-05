#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a;
    printf("Input number\n");
    scanf(" %d", &a);
    printf("Cena bez dane: %d\n" , a);
    printf("Cena bez dane: %.1f\n" , (a*1.2));
    return 0;
}
