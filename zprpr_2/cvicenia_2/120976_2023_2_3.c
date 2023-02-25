#include <stdio.h>
#include <math.h>

int kvadraticka_rovnica(float *first, float *second, float *third);

int main(int argc, char const *argv[])
{
    float first_number, second_number, third_number;
    int counter;

    printf("Input 3 numbers\n");
    scanf(" %f", &first_number);
    scanf(" %f", &second_number);
    scanf(" %f", &third_number);
    counter = kvadraticka_rovnica(&first_number, &second_number, &third_number);
    switch (counter)
    {
    case 2:
        printf("We found only one root that is %.2f", first_number);
        break;
    case 3:
        printf("We found two roots that are %.2f and %.2f", first_number, second_number);
        break;
    case 4:
        printf("We didn't find any roots");
        break;
    default:
        break;
    }
    return 0;
}

int kvadraticka_rovnica(float *first, float *second, float *third)
{
    float a = *first;
    float b = *second;
    float c = *third;
    float calculation = ((b * b) - (4 * a * c)), first_root, second_root;
    if (calculation == 0)
    {
        *first = (-b + sqrt(calculation)) / (2 * a);
        return 2;
    }
    else if (calculation > 0)
    {
        *first = (-b + sqrt(calculation)) / (2 * a);
        *second = (-b - sqrt(calculation)) / (2 * a);
        return 3;
    }
    else
    {
        *first = 0;
        *second = 0;
        return 4;
        printf("This function does not have roots");
    }
}