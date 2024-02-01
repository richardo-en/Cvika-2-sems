#include <stdio.h>

void mocnina(double x, int n)
{
    double result;
    for (int i = 0; i < n; i++)
    {
        result = x;
        for (int a = 0; a < i; a++)
        {
            result *= x;
        }
        printf(" %.2lf^%d = %.2lf\n", x, i + 1, result);
    }

    printf("\n\n");
}
int main(int argc, char const *argv[])
{
    int number_two;
    double number_one;
    scanf(" %lf %d", &number_one, &number_two);
    mocnina(number_one, number_two);
    return 0;
}