#include <stdio.h>

int main(int argc, char const *argv[])
{
    char input[50];
    int count =0;
    scanf("%s" , input);
    while (1)
    {
        if (input[count] == '\0')
        {
            break;
        }else if (input[count] != '*')
        {
            printf(" ");
        }else{
            printf("^");
        }
        count++;
    }
    return 0;
}
