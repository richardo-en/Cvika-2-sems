#include <stdio.h>

int main(int argc, char const *argv[])
{
    float v;
    scanf(" %f", &v);
    printf(" %d %d", (int)(v), (int)(v+0.5));
    return 0;
}