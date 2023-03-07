#include <stdio.h>
#include <stdlib.h>

int vypis(int **array, int array_lenght);
int alokuj(int **array, int input_number);
int nacitaj(int **array, int array_lenght);

int main(int argc, char const *argv[])
{
    int input_number;
    int **array_of_numbers;
    printf("Input how much numbers you want to insert.\n");
    scanf(" %d", &input_number);
    while (1)
    {
        if (input_number > 24 || input_number < 0)
        {
            printf("Input how much numbers you want to insert.\n");
            scanf(" %d", &input_number);
        }
        else
        {
            break;
        }
    }

    alokuj(array_of_numbers ,input_number);
    free(array_of_numbers);
    return 0;
}

int alokuj(int **array ,int input_number)
{
    int **array_of_numbers = malloc(sizeof(int) * input_number);
    for (int i = 0; i < input_number; i++)
    {
        array_of_numbers[i] = malloc(sizeof(int) * input_number);
    }
    nacitaj(array_of_numbers, input_number);
}

int nacitaj(int **array, int array_lenght)
{
    for (int i = 0; i < array_lenght; i++)
    {
        for (int a = 0; a < array_lenght; a++)
        {
            printf("Input %d. row for number %d numbers.\n", i + 1, a);
            scanf(" %d", &array[i][a]);
        }
    }
    vypis(array, array_lenght);
}

int vypis(int **array, int array_lenght)
{
    printf("Your numbers are:");
    for (int i = 0; i < array_lenght; i++)
    {
        for (int a = 0; a < array_lenght; a++)
        {
            if (i == 0 && a == 0)
            {
                printf(" %d", array[i][a]);
            }
            else
            {
                printf(", %d", array[i][a]);
            }
        }
    }
}