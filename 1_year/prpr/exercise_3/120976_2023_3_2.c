#include <stdio.h>

int main(int argc, char const *argv[])
{
    int array[4], is_right = 1;
    int lenght = sizeof(array) / sizeof(int);
    for (int i = 0; i < lenght; i++)
    {
        scanf(" %d", &array[i]);
    }

    for (int i = 0; i < lenght; i++)
    {
        if (i == 0 && (array[i] < 0 || array[i] > 10))
        {
            is_right = 0;
            break;
        }
        else if ((array[i] > 2 * array[i - 1]) || (array[i] < 0.5 * array[i - 1]))
        {
            if (i == 1 && array[0] == 0)
            {
                continue;
            }
            else
            {
                is_right = 0;
                break;
            }
        }
    }

    if (is_right == 0)
    {
        printf("Postupnost je nespravna\n");
    }
    else
    {
        printf("Postupnost je spravna\n");
    }
    return 0;
}