#include <stdio.h>

int sum(int max, int start, int total)
{
    if (start < max && start % 2 != 0)
    {
        total += start;
    }else if(start >= max){
        return total;
    }
    sum(max, start + 1, total);
}

int main(int argc, char const *argv[])
{
    int a, res = 0;
    scanf(" %d", &a);
    res = sum(a , res, res);
    printf(" %d\n", res);
    return 0;
}