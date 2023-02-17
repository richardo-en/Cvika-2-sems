#include <stdio.h>

int main(int argc, char const *argv[])
{
    int id = 0, part_time_num, reversed_num;
    long number[10], switch_num;

    printf("If you want to end program insert 0\n");
    while (1)
    {
        scanf(" %ld", &switch_num);
        if (switch_num == 0)
        {
            break;
        }
        else
        {
            number[id] = switch_num;
        }
        ++id;
    }

    for (int i = 0; i < id; i++)
    {
        part_time_num = number[i];
        reversed_num = 0;
        while (part_time_num != 0)
        {
            reversed_num = reversed_num * 10 + part_time_num % 10;
            part_time_num = part_time_num / 10;
        }
        printf("%ld\n", reversed_num);
        if (reversed_num == number[i])
        {
            printf("Cislo %ld je palindrom\n", reversed_num);
        }
        else
        {
            printf("Cislo %ld nie je palindrom\n", number[i]);
        }
    }

    return 0;
}