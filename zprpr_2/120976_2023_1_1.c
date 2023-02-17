#include <stdio.h>

int main(int argc, char const *argv[])
{
    int current_input, previous_input, single_num = -1, correctness = 1;
    float calcul;
    printf("Input number from 1-10:\n");
    while (1)
    {
        scanf(" %d", &single_num);
        if (single_num > 0 && single_num < 10)
        {
            break;
        }
    }

    previous_input = single_num;
    for (int i = 0; i < single_num; i++)
    {
        scanf(" %d", &current_input);
        calcul = (float)current_input / 2;
        if ((calcul > previous_input) || (current_input > (2 * previous_input)))
        {
            correctness = 0;
        }
        previous_input = current_input;
    }
    if (correctness == 0)
    {
        printf("Postupnost je nespravna\n");
    }
    else
    {
        printf("postupnost je Spravna\n");
    }
    return 0;
}