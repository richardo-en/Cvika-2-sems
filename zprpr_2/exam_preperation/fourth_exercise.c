#include <stdio.h>
#include <stdlib.h>

void swap(void **p1, void **p2, void *j, void *j2);

int main(int argc, char const *argv[])
{
    int a = 5, b = 10, *p1 = &a, *p2 = &b;
    char ch1 = 'c', ch2 = 'f', *uch1 = &ch1, *uch2 = &ch2, input, *alloc_str = NULL, str[100];
    while (1)
    {
        scanf("%c", &input);
        if (input == 's' || input == 'a' || input == 'e')
        {
            switch (input)
            {
            case 's':
                printf("%x - %x\n", p1, p2);
                swap((void **)&p1, (void **)&p2, (void *)&a, (void *)&b);
                printf("%x - %x\n", p1, p2);
                swap((void **)&uch1, (void **)&uch2, (void *)&ch1, (void *)&ch2);

                break;
            case 'a':
                printf("Zadajte vetu:\n");
                scanf(" %99[^\n]s", str);
                alloc_str = (char *)malloc(sizeof(str) * sizeof(char));
                int i = 0;
                while (str[i] != '\0')
                {
                    alloc_str[i] = str[i];
                    i++;
                }
                i = 0;
                printf("vetaaaaaaaaaa - %s", alloc_str);
                break;
            case 'e':
                exit(1);
            }
        }
        else
        {
            printf("Zly input");
        }
    }

    return 0;
}

void swap(void **p1, void **p2, void *j, void *j2)
{
    *p1 = j2;
    *p2 = j;
}
