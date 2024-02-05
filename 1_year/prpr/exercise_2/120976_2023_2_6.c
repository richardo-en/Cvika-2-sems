#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b;
    char ch;
    scanf(" %d %d %c", &a, &b, &ch);

    if (ch == '+')
    {
        printf("%d + %d = %d", a, b, a + b);
    }
    else if (ch == '-')
    {
        printf("%d - %d = %d", a, b, a - b);
    }
    else if (ch == '*')
    {
        printf("%d * %d = %d", a, b, a * b);
    }
    else if (ch == '/')
    {
        printf("%d / %d = %.2f", a, b, ((float)a / b));
    }

return 0;
}