#include <stdio.h>
int main() {
    float num;
    FILE * f = fopen("4_6_out.txt", "w");
    scanf(" %f", &num);

    for (int i = 1; i < 11; i++)
    {
        fprintf(f, "%d * %.2f = %.2f\n", i ,num , num*i);
    }
    fclose(f);
    return 0;
}
