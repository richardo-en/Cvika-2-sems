#include <stdio.h>

int *maximum(int *a, int *b){
    if (*a > *b)
    {
        return a;
    }else{
        return b;
    }
    
}

int main(int argc, char const *argv[])
{
    int a,b, *c;
    // printf("%p - c| %p - b| %p - a\n", c, &a, &b);
    scanf(" %d %d", &a, &b);
    c = maximum(&a, &b);
    // printf("%p - c\n", c);
    printf("Cislo %d je vacsie\n", *c);
    return 0;
}