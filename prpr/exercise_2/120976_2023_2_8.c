#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b, c ,d, e;
    scanf(" %d %d %d %d %d", &a , &b , &c ,&d ,&e);
    int f= a, g = b, h = c, i = d , j = e;
    printf("%d\n" , e/--a*b++/c++ );
    // Najprv sa e predeli ackom ktore je este pred tou operaciou zmensene o jedna tzn ze podla vstupu  6 2 2 4 5 nam vrati e/--a = 1
    // Nasledne (1 * b) = 2  A nasledne sa 2 sa predeli 2mi co je 1  
    a = f, b = g, c = h, d = i, e = j;
    printf("%d\n" , a%=b=d=1+e/2);
    // Delenie ma prednost takze najprv sa vykona e/2 co nam pri vstupe vrati 2 lebo je to (5/2) a znizi sa to o jedno  a k tomu sa pripocita jedna
    // Nasledne ide module co predstavuje %= a nam predstavuje 6 modulo b = d co sa rovna nasej 1 + e/2 cize (6 % 3) = 2 zv 0  

    return 0;
}