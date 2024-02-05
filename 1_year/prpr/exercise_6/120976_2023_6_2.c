#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fr = fopen("subor.txt", "r");
    if (fr == NULL)
    {
        printf("neotvoreny subor");
    }
    else
    {
        char ch;
        int *count, characters = ('Z' - 'A') + 1, index = 0, lines = 1;;
        for (int i = 'A'; i < 'Z' + 1; i++)
        {
            printf("    %c", i);
        }
        count = malloc(sizeof(int) * characters);
        for (int i = 0; i < characters; i++)
        {
            count[i] = 0;
        }

        int is_infinite = 1;

        while (is_infinite)
        {
            if (ch == '\n' || ch == EOF)
            {
                printf("\n%d", lines);
                lines++;
                for (int i = 'A'; i < 'Z' + 1; i++)
                {
                    printf("    %d" , count[index]);
                    count[index] = 0;
                    index++;
                }
                if (ch == EOF)
                    is_infinite = 0;

            }

            ch = fgetc(fr);
            for (int i = 'A'; i < 'Z' + 1; i++)
            {
                if (ch == i || ch == i - ('A' - 'a'))
                {
                    count[index]++;
                    break;
                }
                index++;
            }
            index = 0;
        }
        free(count);
    }

    return 0;
}