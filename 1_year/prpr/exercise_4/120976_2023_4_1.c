#include <stdio.h>
int zisti_prvocislo(int cislo){
    int devider_count = 0;
    for (int i = 1; i < cislo+1; i++)
    {
        if (cislo % i == 0)
        {
            devider_count++;
        }
    }
    
    if (devider_count == 2 || cislo == 1)
    {
        return 1;
    }else{
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    int a, b, midNum;
    scanf(" %d %d", &a, &b);
    midNum = a;
    if (a > b)
    {
       midNum =  b;
       b = a;
       a = midNum;
    }else if (a == b)
    {
        printf("\nBoth numbers are equal!\n");
        return 0;
    }
    
    for (int i = a; i < b; i++)
    {
        if (zisti_prvocislo(i))
        {
            printf("%d\n", i);
        }
    }
    return 0;
} 