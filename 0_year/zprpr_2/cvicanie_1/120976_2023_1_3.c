#include <stdio.h>
void mocnina();

int main(int argc, char const *argv[])
{
    int exponent;
    double main_number;
    scanf("%lf %d", &main_number, &exponent);
    mocnina(main_number, exponent);
    return 0;
}

void mocnina(double main_number, int exponent_num)
{
    double calculation;
    for (int i = 0; i < exponent_num; i++)
    {
        if (i == 0)
        {
            calculation = main_number;
        }
        else
        {
            calculation *= main_number;
        }
        printf("\n%.2lf^%d = %.2lf", main_number, i + 1, calculation);
    }
}