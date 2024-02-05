#include <stdio.h>

int main(int argc, char const *argv[])
{
    char a,b;
    int c,d;
    scanf(" %c %c", &a, &b);
    c = (int)(a) + ('A' - 'a');
    d = (int)(b) + ('A' - 'a');
    printf(" %c %d\n%c %d", c, c ,d ,d);
    return 0;
}