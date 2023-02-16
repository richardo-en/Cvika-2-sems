#include <stdio.h>

int main(int argc, char const *argv[])
{
    int input, loop_through;
    printf("Input number:\n");

    while (1)
    {
        scanf(" %d", &input);
        if (input > 1 && input < 15)
        {
            loop_through = input;
            break;
        }
        else
        {
            printf("Cislo nie je z daneho intervalu\n");
            return 0;
        }
    }
    FILE *subor;
    subor = fopen("cvicenie1p2.txt", "w+");
    if (subor == NULL)
    {
        printf("\nStala sa chyba pri citani suboru. Pravdepodobne sa neda takyto subor otvorit.");
        return 0;
    }

    for (int column = 1; column < loop_through + 1; column++)
    {
        printf("%d:", column);
        fprintf(subor, "%d:", column);
        for (int i = 0; i < input; i++)
        {
            printf(" %d", input - i);
            fprintf(subor, " %d", input - i);
        }
        --input;
        if (input != 0)
        {
            printf("\n");
            fprintf(subor, "\n");
        }
    }

    fclose(subor);

    return 0;
}
