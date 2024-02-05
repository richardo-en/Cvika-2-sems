#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int count, index = 0;
    char *string, s[50];
    scanf(" %d", &count);
    scanf(" %s",s);
    string = malloc(sizeof(char) * (count+1));
    for (int i = count - 1;i >= 0; i--)
    {
        string[index] = s[i];
        index++;
    }
    printf("%s\n", string);
    free(string);
    return 0;
}