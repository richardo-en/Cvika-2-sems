#include <stdio.h>
#include <stdlib.h>

#define na_velke(c) ((c >= 'a' && c <= 'z') ? (c - 'a' + 'A') : c)


int i1 = 9543, i2 = 1;
void prva(){
    int i1 = 10, j1 = 20;
    printf("\n %3d %3d %3d", i1, i2, j1);
}

static int j1 = 50, j2 = 25;

int druha(){
    auto int i2 = 25, j2 = 75, k1 = 100;
    printf("\n %3d %3d %3d", i1, i2, j1, j2, k1);
}

int main(int argc, char const *argv[])
{
    // prva();
    // druha();
    char d;
    scanf("%c" , &d);
    d = na_velke(d);
    printf("%c" , d);
    return 0;
}
