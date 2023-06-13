#include <stdio.h>

void main()
{
    char *p1, *p2;
    char str[] = {'S', 'k', 'u', 's', 'k', 'a', '?', 'Z', 'p', 'r', 'p', 'r', '2', '\0'};
    p1 = str;
    for (p2 = p1; (p2 - p1) < sizeof(str) && *p2 != '?'; p2++)
        ;
    printf("%d", (p2 < p1 + sizeof(str)) ? (p2 - p1 + 1) : -1);
    printf("%s", (p2 < p1 + sizeof(str)) ? (p2 + 1) : p1 + 1);
}