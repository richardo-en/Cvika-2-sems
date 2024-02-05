#include <math.h>
#include <stdio.h>

int delitele(int x[], int pocetx, int y[], int k){
    int write_index = 0;
    for (int i = 0; i < pocetx; i++)
    {
        if (k % x[i] == 0)
        {
            y[write_index] = x[i];
            write_index++;
        }
    }
    return write_index;
}

int main(int argc, char const *argv[])
{
    int x[] = {4, 7, 10, 2, 3, 9, 6, 5, 8, 12}, pocetx = sizeof(x)/ sizeof(int); 
    int y[pocetx], pocety;
    pocety = delitele(x,pocetx,y,24);
    printf("pocety: %d\n",pocety);
    return 0;
}