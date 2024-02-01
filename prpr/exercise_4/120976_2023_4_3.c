#include <stdio.h>
long reverzne_cislo(long x)
{
    long reversed = 0;

    while (x != 0)
    {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    return reversed;
}

int main(int argc, char const *argv[])
{
    long a, res;
    while (1)
    {
        scanf(" %ld", &a);
        res = reverzne_cislo(a);
        printf(" %ld\n", res);
        if (res == a)
        {
           printf("Cislo %ld je palindrom\n", a);
        }else{
           printf("Cislo %ld nie je palindrom\n", a);
        }
        
    }

    return 0;
}