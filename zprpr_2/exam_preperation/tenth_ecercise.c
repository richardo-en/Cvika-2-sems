#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void nasledovnik(char ***string, char sentence[]){
    for (int i = 0; i < strlen(sentence); i++)
    {
        int true = 0;
        (*string)[i][0] = sentence[i];
        for (int a = i; a < strlen(sentence); a++)
        {
            if (sentence[a] > sentence[i])
            {
                (*string)[i][1] = sentence[a];
                true = 1;
                break;
            }
        }
        if (true == 0)
        {
            (*string)[i][1] = '8';
        }
        
    }
}

int main(int argc, char const *argv[])
{
    char sentence[100];
    scanf("%s" , sentence);
    char **string;
    string = malloc(sizeof(char*) * strlen(sentence));
    for (int i = 0; i < strlen(sentence); i++)
    {
        string[i] = malloc(sizeof(char) * 2);
    }
    nasledovnik(&string, sentence);
    for (int i = 0; i < strlen(sentence); i++)
    {
        printf("%c%c ", string[i][0] , string[i][1]);
    }
    return 0;
}