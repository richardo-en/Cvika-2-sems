#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a;
    float pi = 3.14;
    printf("Input number\n");
    scanf(" %d", &a);
    printf("Druha mocnina cisla 8 je:  %.2f\n" , (2*pi*a));
    return 0;
}
