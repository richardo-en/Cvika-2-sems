#include <stdio.h>

void nacitaj(float *a, float *b){
    scanf("%f %f", a,b);
}

void vypocitaj(float *s, float *o, float a, float b){
    *s = a*b;
    *o = 2*a + 2*b;
}

int main(int argc, char const *argv[])
{
    float a,b,s,o;
    nacitaj(&a, &b);
    vypocitaj(&s, &o, a,b);
    printf("Obsah: %.3f\n", s);
    printf("Obvod: %.3f\n", o);
    return 0;
}