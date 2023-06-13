#include <stdio.h>
#include <stdlib.h>

void function1(int *p);
void function2(int **p);
void pointer_learn(void **p1, void **p2, void *x, void *y);

int main(int argc, char const *argv[])
{
    // int value = 5;
    // int *p = &value;
    /*
    PROPER DECLARATION
    1.)  int *p = &address; => will be pointing to variable "address" and *p's value will be same as value of variable "address"
    2.)  int *p;
         p= &address;
    3.)  int *p;
         *p = (5 || 'c') => specified value;
    */
    // printf("value of pointer - %d\n", *p);
    // printf("address of value stored in pointer - %p\n", p); // &value
    // printf("address of pointer - %p\n", &p);
    // function1(p);
    // function2(&p);
    int a=3, b=5, *p1 = &a, *p2 = &b;
    char ch1 = 'a', ch2 = 'b', *pch1 = &ch1, *pch2 = &ch2;
    printf("%p - %p\n", p1, p2);
    printf("%p - %p\n", pch1, pch2);
    pointer_learn((void**)&p1, (void**)&p2, &a, &b);
    pointer_learn((void**)&pch1, (void**)&pch2, &ch1, &ch2);
    printf("%p - %p\n", p1, p2);
    printf("%p - %p\n", pch1, pch2);
    return 0;
}

void function1(int *p)
{
    /*
        If pointer is passed to function this way, you work with same declaration as in main function
    */
    printf("value of pointer - %d\n", *p);
    printf("\naddress of value that is stored in pointer - %p\n", p); // &value
    printf("should be addres to p(&p) but for some reason its different address - %p\n", &p);
    int x = 4;
    p = &x;
    printf("\nnew adress of value stored in pointer - %p\n", p);
    printf("new address where pointer is pointing - %p\n", &x);
}

void function2(int **p)
{
    /*
        If pointer is passed to function this way, you work with same declaration as in main function
        BUT you need to add one more start before pointer. So in main function &p prints adress of pointer itself
        and in function2 just p prints address of pointer.
    */
    printf("value of pointer - %d\n", **p);
    printf("\naddress of value stored in pointer - %p\n", *p); // &value
    printf("address of pointer - %p\n", p);
}

void pointer_learn(void **p1, void **p2, void *x, void *y)
{
    *p1 = y;
    *p2 = x; 
}