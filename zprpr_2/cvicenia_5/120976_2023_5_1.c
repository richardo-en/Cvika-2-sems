#include <stdio.h>
void print_reversed(int loop_number, int position, char alphabet[]);
void print_snake(int number_one, int count, char alphabet[]);

int main(int argc, char const *argv[])
{
    int number_one, number_two, count = 0;
    char alphabet[25], reversing_part[25];
    for (int i = 0; i < 25; i++)
    {
        alphabet[i] = (97 + i);
    }

    printf("Input number one:\n");
    scanf(" %d", &number_one);
    printf("Input number two:\n");
    scanf(" %d", &number_two);

    print_snake(number_one, count, alphabet);
    count *= count;
    print_snake(number_two, count, alphabet);

    return 0;
}

void print_snake(int number_one, int count, char alphabet[])
{
    for (int i = 0; i < number_one; i++)
    {
        if (i % 2 == 0)
        {
            for (int a = 0; a < number_one; a++)
            {
                printf("%c ", alphabet[count]);
                count++;
                if (count >= 25)
                {
                    count = 0;
                }
            }
        }
        else
        {
            print_reversed(number_one, count, alphabet);
            count += number_one;
        }
        printf("\n");
    }
    if (count >= 25)
    {
        count = 0;
    }
}

void print_reversed(int loop_number, int position, char alphabet[])
{
    position += (loop_number - 1);
    for (int i = 0; i < loop_number; i++)
    {
        printf("%c ", alphabet[position - i]);
    }
}