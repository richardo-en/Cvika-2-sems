#include <stdio.h>

int main(int argc, char const *argv[])
{
    int lines, count = 0, number;
    scanf(" %d", &lines);
    for (int i = 0; i < lines; i++)
    {
        scanf(" %d", &number);
        if (number > 0 && number < 100)
        {
            count++;
        }
    }
    printf(" %d\n\n", count);
    return 0;
}