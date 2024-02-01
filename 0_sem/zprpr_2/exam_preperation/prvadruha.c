#include <stdio.h>

int i1 = 0, i2 = 1;

void prva(){
    int i1 = 10, j1 = 20;
    printf("\n %3d %3d %3d", i1, i2, j1);
}

static int j1 = 50, j2 = 25;

int druha(){
    auto int i2 = 25, j2 = 75, k1 = 100;
    printf("\n %3d %3d %3d %3d %3d", i1,i2,j1,j2,k1);
}

void main(){
    prva();
    druha();
}