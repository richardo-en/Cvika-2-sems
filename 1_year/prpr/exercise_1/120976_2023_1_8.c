#include <stdio.h>

int main(int argc, char const *argv[])
{
    float a,b,c;
    printf("Input 3 numbers with space\n");
    scanf(" %f %f %f", &a, &b, &c);
    printf("Objem je: %.3f\n" , (a*b*c));
    return 0;
}
