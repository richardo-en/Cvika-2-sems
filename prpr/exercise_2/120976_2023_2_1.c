#include <stdio.h>

int main(int argc, char const *argv[])
{
    float a,b,c;
    scanf(" %f %f %f", &a, &b, &c);
    printf("Priemer cisel: %.3f", ((a+b+c)/3));
    return 0;
}