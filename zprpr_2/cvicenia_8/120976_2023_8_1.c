#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void get_first_name(char full_name[] ,char **first_name){
    int index = 0;
    char extracted_first_name[50];
    while (full_name[index] != '#')
    {
        extracted_first_name[index] = full_name[index];
        index++;
    }
    *first_name = malloc(sizeof(char) * (strlen(extracted_first_name)));
    extracted_first_name[index] = '\0';
    strcpy(*first_name , extracted_first_name);
}

int main(int argc, char const *argv[])
{
    char get_string[50], *first_name, *extracted_first_name, *saved_name;
    char names[100][50];
    int index = 0, count = 0, temporary_count = 0, index_to_save;

    FILE *data;
    data = fopen("names.txt", "r");

    while (fgets(get_string, sizeof(get_string), data) != NULL)
    {
        strcpy(names[index] , get_string);
        index++;
    }
 
    for (int i = 0; i < index; i++)
    {
        get_first_name(names[i] , &first_name);
        for (int a = 0; a < index; a++)
        {
            get_first_name(names[a] , &extracted_first_name);
            if (strcmp(first_name , extracted_first_name) == 0)
            {
                temporary_count++;
            }
            free(extracted_first_name);
        }

        if (temporary_count > count)
        {
            count = temporary_count;
            index_to_save = i;
            get_first_name(names[i] , &saved_name);
        }
        temporary_count = 0;
        free(first_name);
    }
    printf("Name that does most visits to cinema is %s with count of %d visits ", saved_name, count);
    return 0;
}