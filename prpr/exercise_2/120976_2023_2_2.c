#include <stdio.h>

int main(int argc, char const *argv[])
{
    float v,b,c;
    scanf(" %f %f", &v, &b);
    c = (v/100);
    printf("BMI: %.3f", (b/(c*c)));
    return 0;
}