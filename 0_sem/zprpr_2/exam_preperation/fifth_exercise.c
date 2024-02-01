#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void **p1, void **p2, void *x, void *y);
void swap_values(int *x, int *y);
void allocation(char **alloc, char str[]);

int main() {
    char ch1 = 'a', ch2 = 'b', *pch1 = &ch1, *pch2 = &ch2, *alloc, str[100];
    int num1 = 5, num2 = 6, *pnum1 = &num1, *pnum2 = &num2;

    // printf("Zadajte vetu:\n");
    // scanf(" %99[^\n]", str);
    // allocation(&alloc , str);
    // printf("%s\n" ,alloc);

    printf("pch1 address: %p, pch2 address: %p\n", pch1, pch2);
    printf("pnum1 address: %p, pnum2 address: %p\n", pnum1, pnum2);
    swap((void**)&pch1, (void**)&pch2, (void*)&ch1 , (void*)&ch2);
    swap((void**)&pnum1, (void**)&pnum2, (void*)&num1 , (void*)&num2);
    printf("pch1 address: %p, pch2 address: %p\n", pch1, pch2);
    printf("pnum1 address: %p, pnum2 address: %p\n", pnum1, pnum2);
    // printf("%d , %d\n" , *pnum1, *pnum2);
    // swap_values(pnum1, pnum2);
    // printf("%d , %d\n" , *pnum1, *pnum2);

    return 0;
}

void swap(void **p1, void **p2, void *x, void *y){
    *p1 = y;
    *p2 = x;
}

void swap_values(int *x, int *y){
    int temp = *y;
    *y = *x;
    *x = temp;
}

void allocation(char **alloc , char str[]){
    (*alloc) = (char *)malloc(strlen(str) * sizeof(char));
    int i = 0;
    while (str[i] != '\n')
    {
        (*alloc)[i] = str[i++];
    }
}
