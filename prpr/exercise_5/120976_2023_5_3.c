#include <math.h>
#include <stdio.h>

void kvadraticka_rovnica(float *a, float *b, int x, int y , int z){
    double v = ((y*y) - 4 *x*z);
    double disk = sqrt(v);
    *a = (-y + disk)/2*x;
    *b = (-y - disk)/2*x;
}

int main(int argc, char const *argv[])
{
    float a, b;
    int x,y,z;
    scanf("%d %d %d", &x, &y, &z);
    kvadraticka_rovnica(&a, &b,x,y,z);
    printf("Prvy koren ma hodnotu: %f\n", a);
    printf("Druhy koren ma hodnotu: %f\n", b);
    return 0;
}