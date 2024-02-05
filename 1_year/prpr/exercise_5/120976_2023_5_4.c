#include <math.h>
#include <stdio.h>

void vymen_ukazovatele(int **a, int **b){
    int *c = *a;
    // c = *a;
    *a = *b;
    *b = c;
}

int main(int argc, char const *argv[])
{
    int *a , *b;
    *(a) = 10;
    *(b) = 14;
    printf("p_a: %p %d\n", &a, a);
    printf("p_b: %p %d\n", &b, b);
    vymen_ukazovatele(&a, &b);
    printf("p_a: %p %d\n", &a, a);
    printf("p_b: %p %d\n", &b, b);
    return 0;
}