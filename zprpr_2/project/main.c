#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int load_file(char *article_id, char *article_title, char *article_author, char *article_time, char inputs[]);
int get_lines();
int find_in_inputs(char input, char input_list[], int number_of_inputs);
void output(char *inputs, int number_of_inputs, int array_length, char *article_id, char *article_title, char *article_author, char *article_time);

int main(int argc, char const *argv[])
{
    char input;
    int is_input_correct = 0, inputs_count = 1;
    char correct_inputs[] = {'v', 'p', 'n', 's', 'w', 'h', 'z', 'd', 'k'};
    char *inputs = malloc(sizeof(char) * inputs_count);

    // Allocation of arrays
    char **article_id = malloc(sizeof(char) * 1);
    char **article_title = malloc(sizeof(char) * 1);
    char **article_author = malloc(sizeof(char) * 1);
    char **article_time = malloc(sizeof(char) * 1);
    while (is_input_correct == 0)
    {
        scanf(" %c", &input);
        for (int i = 0; i < 8; i++)
        {
            if (input == correct_inputs[i])
            {
                is_input_correct = 1;
            }
        }

        if (is_input_correct == 0)
        {
            printf("Invalid input");
        }
    }
    // load_file();
    // output(inputs , inputs_count , 1 , article_id,article_title,article_author,article_time);
    return 0;
}
// Control functions
void check_id(char *id_list[])
{
    if ((*id_list[0] == 'P' || *id_list[0] == 'U') && (*id_list[1] == 'P' || *id_list[1] == 'D'))
    {
        for (int i = 2; i < 9; i++)
        {
            if (*id_list[i] < 48 || *id_list[i] > 57)
            {
                printf("ID prispevku: Nespravne ID\n");
                return;
            }
        }
        printf("ID prispevku: ");
        for (int i = 0; i < 9; i++)
        {
            printf("%c", *id_list[i]);
        }
        printf("\n");
        return;
    }
}

void check_for_zeros_in_date(char number_one, char number_two, char devider)
{
    if (number_one == '0')
    {
        printf("%c%c", number_two, devider);
    }
    else
    {
        printf("%c%c%c", number_one, number_two, devider);
    }
}

// Prtint function
void print_name(char article_authors[])
{
    for (int i = 0; i < 300; i++)
    {
        if (article_authors[i] != '#')
        {
            printf("%c", article_authors[i]);
        }
        else if (article_authors[i] == '#')
        {
            printf(", ");
        }

        if (article_authors[i] == '\n')
        {
            printf("\n");
            return;
        }
    }
}

void print_date(char article_date[])
{
    printf("Datum a cas prezentovania:");
    check_for_zeros_in_date(article_date[6], article_date[7], '.');
    check_for_zeros_in_date(article_date[4], article_date[5], '.');
    for (int i = 0; i < 4; i++)
    {
        printf("%c", article_date[i]);
    }
    printf(" ");
    check_for_zeros_in_date(article_date[8], article_date[9], ':');
    check_for_zeros_in_date(article_date[10], article_date[11], '\n');
}

void output(char *inputs, int number_of_inputs, int array_length, char *article_id, char *article_title, char *article_author, char *article_time)
{
    char file_input[300];
    if (find_in_inputs('v', inputs, number_of_inputs))
    {
        if (find_in_inputs('n', inputs, number_of_inputs) || find_in_inputs('p', inputs, number_of_inputs))
        {
            for (int i = 0; i < array_length; i++)
            {
                check_id(article_id[i]);
                printf(article_title[i]);
                print_name(article_author[i]);
                print_date(article_time[i]);
            }
        }
    }
    else
    {
        FILE *data;
        data = fopen("KonferencnyZoznam.txt", "r");
        if (data == NULL)
        {
            printf("\nStala sa chyba pri citani suboru. Pravdepodobne sa neda takyto subor otvorit.");
            return;
        }
        while (!feof(data))
        {
            fgets(file_input, sizeof(file_input), data);
            printf("%s\n", file_input);
        }
    }
}

int load_file(char *article_id, char *article_title, char *article_author, char *article_time, char inputs[])
{
    FILE *data;
    data = fopen("KonferencnyZoznam.txt", "r");
    int record_counter = 0, read = 0, lines = get_lines(), is_end = 0;
    char get_string[150];

    // for (int i = 0; i < lines; i++)
    // {
    //     article_id[i] = malloc(sizeof(char) * 11);
    //     article_title[i] = malloc(sizeof(char) * 50);
    //     article_author[i] = malloc(sizeof(char) * 50);
    //     article_time[i] = malloc(sizeof(char) * 13);
    // }

    while (is_end == 0)
    {
        if (fgets(get_string, sizeof(get_string), data) == NULL)
        {
            is_end = 1;
        }
        switch (read)
        {
        case 0:
            strcpy(article_id[record_counter], get_string);
            read++;
            break;
        case 1:
            strcpy(article_title[record_counter], get_string);
            read++;
            break;
        case 2:
            strcpy(article_author[record_counter], get_string);
            read++;
            break;
        case 3:
            strcpy(article_time[record_counter], get_string);
            read++;
            break;
        case 4:
            record_counter++;
            read = 0;
            break;
        default:
            break;
        }
    };

    // for (int i = 0; i < record_counter; i++)
    // {
    //     printf("\n artcile_id %s", article_id[i]);
    //     printf("\n artcile_title %s", article_title[i]);
    //     printf("\n artcile_autor %s", article_author[i]);
    //     printf("\n artcile_time %s\n-------------------------\n", article_time[i]);
    // }
    fclose(data);
}

int get_lines()
{
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

    return ((lines - 1) / 2);
}

int find_in_inputs(char input, char input_list[], int number_of_inputs)
{
    for (int i = 0; i < number_of_inputs; i++)
    {
        if (input == input_list[i])
        {
            return 1;
        }
    }
    return 0;
}