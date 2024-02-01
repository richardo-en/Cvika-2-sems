#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a,b;
    scanf(" %d %d" , &a, &b);
    if (a < b)
    {
        printf("Cislo C1 = %d je mnesie ako C2 = %d" , a, b);
    }else if (a > b)
    {
        printf("Cislo C2 = %d je mnesie ako C1 = %d" , b, a);
    }else{
        printf("Cisla su rovnka C = %d", a);
    }

    return 0;
}