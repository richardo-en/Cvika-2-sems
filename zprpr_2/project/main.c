#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int load_file();
int get_lines();

int main(int argc, char const *argv[])
{
    char input;
    int is_input_correct = 0;
    char correct_inputs[] = {'v', 'p', 'n', 's', 'w', 'h', 'z', 'd', 'k'};
    // while (is_input_correct == 0)
    // {
    //     scanf(" %c", &input);
    //     for (int i = 0; i < 8; i++)
    //     {
    //         if (input == correct_inputs[i])
    //         {
    //             is_input_correct = 1;
    //         }
    //     }

    //     if (is_input_correct == 0)
    //     {
    //         printf("Invalid input");
    //     }
    // }
    load_file();
    return 0;
}

int load_file()
{
    FILE *data;
    data = fopen("KonferencnyZoznam.txt", "r");
    int record_counter = 0, read = 0, lines = get_lines(), is_end = 0;
    char get_string[150];

    char **article_id = malloc(sizeof(char) * lines);
    char **article_title = malloc(sizeof(char) * lines);
    char **article_autor = malloc(sizeof(char) * lines);
    char **article_time = malloc(sizeof(char) * lines);

    for (int i = 0; i < lines; i++)
    {   
        article_id[i] = malloc(sizeof(char) * 11);
        article_title[i] = malloc(sizeof(char) * 50);
        article_autor[i] = malloc(sizeof(char) * 50);
        article_time[i] = malloc(sizeof(char) * 13);
    }

    while(is_end == 0){
        if (fgets(get_string, sizeof(get_string), data) == NULL)
        {
            is_end = 1;
        }
        if (read == 0)
        {
            strcpy(article_id[record_counter], get_string);
            read++;
        }
        else if (read == 1)
        {
            strcpy(article_title[record_counter], get_string);
            read++;
        }
        else if (read == 2)
        {
            strcpy(article_autor[record_counter], get_string);
            read++;
        }
        else if (read == 3)
        {
            strcpy(article_time[record_counter], get_string);
            read++;
        }else if (read == 4){
            record_counter++;
            read = 0;
        }
    };

    for (int i = 0; i < record_counter; i++)
    {    
        printf("\n artcile_id %s", article_id[i]);
        printf("\n artcile_title %s", article_title[i]);
        printf("\n artcile_autor %s", article_autor[i]);
        printf("\n artcile_time %s\n-------------------------\n", article_time[i]);
    }
    // free(article_id);
    // free(article_title);
    // free(article_autor);
    // free(article_time);
    fclose(data);
}

int get_lines(){
    FILE *data_lines;
    data_lines = fopen("KonferencnyZoznam.txt", "r");
    char get_lines[150];
    int lines = 0;

    if (data_lines == NULL)
    {
        printf("Chyba pri otvarani suboru\n");
        return 0;
    }

    do
    {
        lines++;
    } while (fgets(get_lines, sizeof(get_lines), data_lines) != NULL);
    fclose(data_lines);

    return ((lines-1)/2);
}