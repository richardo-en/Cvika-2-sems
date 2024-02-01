#include <stdio.h>
void vymen_ukazovatele(int *first_pointer, int *second_pointer);

int main(int argc, char const *argv[])
{
    int first_number, second_number;
    printf("Input 2 numbers\n");
    scanf(" %d", &first_number);
    scanf(" %d", &second_number);
    printf("Adress %d have value %d\nAdress %d have value %d\n", &first_number, first_number, &second_number, second_number);
    vymen_ukazovatele(&first_number, &second_number);
    printf("\nAfter function vymen_ukazovatele\n\nAdress %d have value %d\nAdress %d have value %d\n", &first_number, first_number, &second_number, second_number);
    return 0;
}

void vymen_ukazovatele(int *first_pointer, int *second_pointer)
{
    int save_value;
    save_value = *first_pointer;
    *first_pointer = *second_pointer;
    *second_pointer = save_value;
}