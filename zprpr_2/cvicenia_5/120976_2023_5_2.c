#include <stdio.h>
#include <stdlib.h>
void allocate_list(int *list[], int allocation_limit);
void assign_values(int *list[], int input_number);
void print_out_list(int *list[], int loop_number);

int main(int argc, char const *argv[])
{
    int number_one, number_two, count = 0;
    printf("Input number one:\n");
    scanf(" %d", &number_one);
    printf("Input number two:\n");
    scanf(" %d", &number_two);

    int **first_numbers = malloc(sizeof(int) * (number_one));
    // int **second_list =  malloc(sizeof(int) * (number_two));

    allocate_list(first_numbers, number_one);
    // allocate_list(second_list , number_two);

    assign_values(first_numbers, number_one);

    print_out_list(first_numbers, number_one);
    return 0;
}

void allocate_list(int *list[], int allocation_limit)
{
    for (int i = 0; i < allocation_limit; i++)
    {
        list[i] = malloc(sizeof(int) * allocation_limit);
    }
}

void assign_values(int *list[], int input_number)
{
    int assign_number;
    for (int i = 0; i < input_number; i++)
    {
        for (int a = 0; a < input_number; a++)
        {
            scanf("%d", &assign_number);
            list[i][a] = assign_number;
        }
    }
}

void print_out_list(int *list[], int loop_number)
{
    for (int i = 0; i < loop_number; i++)
    {
        for (int a = 0; a < loop_number; a++)
        {
            printf("%d ", list[i][a]);
        }
        printf("\n");
    }
}

int output_result(int *list[], int loop_through)
{
    int count = 0, count_to_compare = 0, is_not_equal = 1;
    for (int i = 0; i < loop_through; i++)
    {
        for (int a = 0; a < loop_through; a++)
        {
            if (i == 0)
            {
                count += list[i][a];
            }
            else
            {
                count_to_compare += list[i][a];
            }
        }

        if (i == 0)
        {
            continue;
        }
        else if (count == count_to_compare)
        {
            continue;
        }
        else
        {
            printf("\nSquer is not magic");
            break;
        }
    }
}