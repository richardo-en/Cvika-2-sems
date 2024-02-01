#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Visitors
{
    char *name;
    struct Visitors *next;
} Visitors;

void find_max(char ***NameList, int **count, int z){
    int index = 0, biggest_num = 0, biggest_index = 0;
    
    for (int i = 0; i < z; i++)
    {
        if ((*count)[i] > biggest_num)
        {
            biggest_num = (*count)[i];
            biggest_index = i;
        }
    }

    printf("Visitor with most visits is %s\n", (*NameList)[biggest_index]);
}

void compare_list(Visitors **head)
{
    Visitors *temp = *head;
    char **names = NULL;
    int *count = NULL;

    names = malloc(sizeof(char*) * 100);
    count = malloc(sizeof(int) * 100);
    int index = 0, biggest_num = 0, biggest_index = 0, was_compared = 0;

    while (temp->next != NULL)
    {
        if (index == 0)
        {
            names[index] = malloc(sizeof(char) * strlen(temp->name) + 1);
            strcpy(names[index], temp->name);
            index++;
        }
        else
        {
            for (int i = 0; i < index; i++)
            {
                if (strcmp(temp->name, names[i]) == 0)
                {
                    count[i]++;
                    was_compared = 1;
                    break;
                }
            }
            if (was_compared == 0)
            {
                names[index] = malloc(sizeof(char) * strlen(temp->name) + 1);
                strcpy(names[index], temp->name);
                index++;
            }else
                was_compared = 0;
            
        }
        temp = temp->next;
    }
    find_max(&names, &count, index);
}

int main(int argc, char const *argv[])
{
    printf("Input names if you want to sotp inputting name press k and enter\n");
    char input[20] = "\0";
    Visitors *visitor = NULL, *temp;
    visitor = malloc(sizeof(Visitors));
    visitor->next = NULL;
    temp = visitor;
    while (1)
    {
        scanf(" %s", input);
        if (input[0] == 'k' && input[1] == '\0')
            break;
        
        input[strcspn(input, "\r\n")] = '\0';
        temp->name = malloc(sizeof(char) * strlen(input) + 1);
        strcpy(temp->name, input);
        temp->next = malloc(sizeof(Visitors));
        temp = temp->next;
        temp->next = NULL;
    }

    compare_list(&visitor);

    return 0;
}
