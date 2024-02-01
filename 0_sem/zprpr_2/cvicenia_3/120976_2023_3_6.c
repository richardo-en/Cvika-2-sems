#include <stdio.h>
#include <stdlib.h>

int print_and_reset(int result[], int column_vount);

int main(int argc, char const *argv[])
{
    FILE *file;
    char ch;
    int count[26], index = 0, column_count = 0;
    for (int i = 0; i < 26; i++)
    {
        count[i] = 0;
    }

    file = fopen("vstup.txt", "r");
    for (int i = 65; i < 91; i++)
    {
        printf(" %c", i);
    }
    printf("\n");

    if (NULL == file)
    {
        printf("file sa neda otvorit\n");
        exit(1);
    }

    while (ch != EOF)
    {
        ch = (char)fgetc(file);
        for (int i = 65; i < 91; i++)
        {
            if (((int)ch == i) || ((int)ch == i + 32))
            {
                count[i - 65]++;
                break;
            }
        }

        if (ch == '\n' || ch == EOF)
        {
            ++column_count;
            print_and_reset(count, column_count);
            index = 0;
        }
    }
    fclose(file);

    return 0;
}

int print_and_reset(int result[], int column_vount)
{
    for (int i = 0; i < 26; i++)
    {
        printf(" %d", result[i]);
        result[i] = 0;
    }
    printf("\n");
}