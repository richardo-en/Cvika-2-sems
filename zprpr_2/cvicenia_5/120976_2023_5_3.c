#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int count_of_sentences, lenght, index = 0;
    char **sentences = NULL;
    char get_string[150];
    get_string[0] = '\0';
    printf("Insert count of all sentences: ");
    scanf("%d", &count_of_sentences);

    sentences = malloc(sizeof(char *) * count_of_sentences);
    for (int i = 0; i < count_of_sentences ; i++)
    {
        scanf(" %150[^\n]" , get_string);
        strcat(get_string , "\n");
        lenght = strlen(get_string);
        sentences[i] = malloc((sizeof(char) * lenght) + sizeof(char));
        strcpy(sentences[i] , get_string);
        get_string[0] = '\0';
    }

    printf("Tieto vety obashuju \'A\'\n");
    for (int i = 0; i < count_of_sentences; i++)
    {
        while (sentences[i][index] != '\n')
        {
            if (sentences[i][index] == 'A')
            {
                printf("%s", sentences[i]);
                break;
            }
            index++;
        }
        index = 0;
    }

    printf("\nTieto vety obashuju \'ako\'\n");
    for (int i = 0; i < count_of_sentences; i++)
    {
        while (sentences[i][index] != '\n')
        {
            if (sentences[i][index] == 'a' && sentences[i][index + 1] == 'k' && sentences[i][index + 2] == 'o')
            {
                printf("%s", sentences[i]);
                break;
            }
            index++;
        }
        index = 0;
    }
    return 0;
}