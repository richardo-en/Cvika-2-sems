#include <stdio.h>
#include <stdlib.h>
int vypis(int array[], int array_lenght);
int alokuj(int input_number);
int nacitaj(int array[], int array_lenght);

int main(int argc, char const *argv[])
{
    int input_number;
    printf("Input how much numbers you want to insert.\n");
    scanf(" %d" , &input_number);
    while (1)
    {
        if (input_number > 24 || input_number < 0)
        {
            printf("Input how much numbers you want to insert.\n");
            scanf(" %d" , &input_number);
        }else{
            break;
        }
        
    }
    alokuj(input_number);
    return 0;
}

int alokuj(int input_number){
    int *array_of_numbers = malloc(sizeof(int)*input_number);
    nacitaj(array_of_numbers , input_number);
}

int nacitaj(int array[] , int array_lenght){
    for (int i = 0; i < array_lenght; i++)
    {
        printf("Input %d. number from %d numbers.\n" ,i+1 , array_lenght);
        scanf(" %d" , &array[i]);
    }
    vypis(array , array_lenght);
}

int vypis(int array[] , int array_lenght){
    printf("Your numbers are:");
    for (int i = 0; i < array_lenght; i++)
    {   
        if (i == 0)
        {
            printf(" %d" , array[i]);
        }else{
            printf(", %d" , array[i]);
        }
    }

}