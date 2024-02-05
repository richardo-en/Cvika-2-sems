#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int input_number;
    printf("Input how much numbers you want to insert.\n");
    scanf(" %d" , &input_number);
    int *array_of_numbers = malloc(sizeof(int)*input_number);
    for (int i = 0; i < input_number; i++)
    {
        printf("Input %d. number from %d numbers.\n" ,i+1 , input_number);
        scanf(" %d" , &array_of_numbers[i]);
    }
    printf("Your numbers are:");
    for (int i = 0; i < input_number; i++)
    {   
        if (i == 0)
        {
            printf(" %d" , array_of_numbers[i]);
        }else{
            printf(", %d" , array_of_numbers[i]);
        }
    }
    return 0;
}