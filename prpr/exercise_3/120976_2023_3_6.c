#include <stdio.h>

int main(int argc, char const *argv[])
{
    int number, number_two;
    scanf(" %d", &number);
    while (number < 1 || number > 15)
    {
        scanf(" %d", &number);
    }

    number_two = number;
    for (int i = 0; i < number; i++)
    {
        printf("\n%d : ", (i + 1));
        for (int a = 0; a < number_two; a++)
        {
            printf("%d ", number_two - a);
        }
        number_two--;
    }
    printf("\n\n");
    return 0;
}