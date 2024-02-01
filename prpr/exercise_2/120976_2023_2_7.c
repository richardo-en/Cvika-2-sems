#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a,b;
    char ch;
    scanf(" %d %d %c" , &a, &b, &ch);
    switch (ch)
    {
    case '+':
        printf("%d + %d = %d", a ,b, a+b);
        break;
    case '-':
        printf("%d - %d = %d", a ,b, a-b);
        break;
    case '*':
        printf("%d * %d = %d", a ,b, a*b);
        break;
    case '/':
        printf("%d / %d = %.2f", a ,b, ((float)a/b));
        break;
    
    default:
        printf("Wrong input");
        break;
    }

    return 0;
}