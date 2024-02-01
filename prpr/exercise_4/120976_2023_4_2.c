#include <stdio.h>
 double  tyzdenna_mzda(double  h_mzda,  double  hod){
    double res = h_mzda * hod; 
    printf("Hod. mzda: %.2lf Euro/hod, hodin: %.2lf, spolu: %.2lf Euro\n", h_mzda , hod, res);
    return res;
};

int main(int argc, char const *argv[])
{
    int a;
    double b, c, total = 0;
    scanf(" %d", &a);
    for (int i = 0; i < a; i++)
    {
        scanf(" %lf %lf", &b, &c);
        total += tyzdenna_mzda(b,c);
    }
    printf("Celkova mzda: %.2lf Euro.\n", total);
    return 0;
} 