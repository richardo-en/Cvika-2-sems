#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Control functions
void check_id(char id_list[])
{
    if ((id_list[0] == 'P' || id_list[0] == 'U') && (id_list[1] == 'P' || id_list[1] == 'D'))
    {
        for (int i = 2; i < 9; i++)
        {
            if (id_list[i] < 48 || id_list[i] > 57)
            {
                printf("ID prispevku: Nespravne ID\n");
                return;
            }
        }
        printf("ID prispevku: ");
        for (int i = 0; i < 9; i++)
        {
            printf("%c", id_list[i]);
        }
        printf("\n");
        return;
    }
}

void check_for_zeros_in_date(char number_one, char number_two, char devider)
{
    if (number_one == '0' && number_two == '0')
    {
        printf("00%c", devider);
    }
    else if (number_one == '0')
    {
        printf("%c%c", number_two, devider);
    }
    else
    {
        printf("%c%c%c", number_one, number_two, devider);
    }
}

int find_same_records(char ***article_title, int *total_records_count, char record_to_find[]){
    int count_of_same_records = 0;
    for (int i = 0; i < *total_records_count; i++)
    {
        int is_true = 1, count = 0;
        while (record_to_find[count] != '\0')
        {
            if ((*article_title)[i][count] != record_to_find[count])
            {
                is_true = 0;
                break;
            }
            count++;
        }
        if (is_true == 1)
        {
            count_of_same_records++;
        }
        is_true = 1;
    }
    return count_of_same_records;
}

int check_for_same_name(char ***writers, char name[], int index, int writes_count){
    int count_of_same_records = 0, is_true = 0;
    for (int i = 0; i < writes_count; i++)
    {
        is_true = 0;
        for (int letter = 0; letter < index; letter++)
        {
            if ((*writers)[i][letter] != name[letter])
            {
                is_true = 1;
                break;
            }
        }
        if (is_true == 0)
        {
            return 0;
        }
    }
    return 1;
}
// Prtint function
void print_name(char article_authors[] , int first_name)
{
    for (int i = 0; i < 300; i++)
    {
        if (article_authors[i] == '\n')
        {
            break;
        }

        if (article_authors[i] != '#')
        {
            printf("%c", article_authors[i]);
        }
        else if (article_authors[i] == '#')
        {
            if (first_name == 1)
            {
                break;
            }else{
                i += 2;
                if (article_authors[(i + 1)] != '\n')
                {
                    printf(", ");
                }
            }

        }
    }
}

void print_date(char article_date[])
{
    printf("Datum a cas prezentovania: ");
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

// Get functions (returns searched value)
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
    while (lines % 5 != 0)
    {
        lines++;
    }

    return (lines / 5);
}

int find_in_inputs(char input, char *input_list)
{
    for (int i = 0; i < sizeof(input_list) / sizeof(char); i++)
    {
        if (input == input_list[i])
        {
            return 1;
        }
    }
    return 0;
}

// Additional functions
void deallocate_array(char ***array, int p)
{
    for (int i = 0; i < p; i++)
    {
        free((*array)[i]);
    }
    free((*array));
}

// Assigment functions
void output(char *inputs, char ***article_id, char ***article_title, char ***article_author, char ***article_time, int *records_counter)
{
    char file_input[300];
    int line = 0;
    if ((find_in_inputs('v', inputs)) && (find_in_inputs('n', inputs) || find_in_inputs('p', inputs)))
    {
        for (int i = 0; i < *records_counter; i++)
        {
            check_id((*article_id)[i]);
            printf("Nazov prispevku: %sMena Autorov: ", (*article_title)[i]);
            print_name((*article_author)[i] , 0);
            printf("\n");
            print_date((*article_time)[i]);
            printf("\n");
        }
    }
    else
    {
        FILE *data;
        data = fopen("KonferencnyZoznam.txt", "r");
        if (data == NULL)
        {
            printf("Neotvoreny subor\n");
            return;
        }
        while (!feof(data))
        {
            fgets(file_input, sizeof(file_input), data);
            if (line == 0)
            {
                printf("ID prispevku: %s", file_input);
            }
            else if (line == 1)
            {
                printf("Nazov prispevku: %s", file_input);
            }
            else if (line == 2)
            {
                printf("Mena Autorov: ");
                print_name(file_input , 0);
                printf("\n");
            }
            else if (line == 3)
            {
                print_date(file_input);
            }
            else if (line == 4)
            {
                printf("%s", file_input);
                line = -1;
            }
            line++;
        }
        printf("\n");
        fclose(data);
    }
}

void add_record(char ***article_id, char ***article_title, char ***article_author, char ***article_time, int *total_records_count)
{
    *total_records_count += 1;
    (*article_id) = realloc((*article_id), *total_records_count * sizeof(char **));
    (*article_title) = realloc((*article_title), *total_records_count * sizeof(char **));
    (*article_author) = realloc((*article_author), *total_records_count * sizeof(char **));
    (*article_time) = realloc((*article_time), *total_records_count * sizeof(char **));

    (*article_id)[(*total_records_count) - 1] = malloc(sizeof(char *) * 11);
    (*article_title)[(*total_records_count) - 1] = malloc(sizeof(char *) * 150);
    (*article_author)[(*total_records_count) - 1] = malloc(sizeof(char *) * 300);
    (*article_time)[(*total_records_count) - 1] = malloc(sizeof(char *) * 13);

    scanf(" %s", (*article_id)[*total_records_count - 1]);
    scanf(" %[^\n]", (*article_title)[*total_records_count - 1]);
    scanf(" %[^\n]", (*article_author)[*total_records_count - 1]);
    scanf(" %s", (*article_time)[*total_records_count - 1]);

    strcat((*article_time)[*total_records_count - 1], "\n");
    strcat((*article_title)[*total_records_count - 1], "\n");
    strcat((*article_author)[*total_records_count - 1], "\n");
    strcat((*article_time)[*total_records_count - 1], "\n");

    printf("Zaznam sa podarilo pridat\n");
}

int load_file(char ***article_id, char ***article_title, char ***article_author, char ***article_time, char *inputs, int *total_records_count)
{
    int record_counter = 0, read = 0, is_end = 0;
    char get_string[80];

    if (find_in_inputs('v', inputs))
    {
        if (find_in_inputs('n', inputs) || *total_records_count != 0)
        {
            deallocate_array(article_id, *total_records_count);
            deallocate_array(article_title, *total_records_count);
            deallocate_array(article_author, *total_records_count);
            deallocate_array(article_time, *total_records_count);
        }
        *total_records_count = get_lines();

        (*article_id) = malloc(sizeof(char **) * (*total_records_count));
        (*article_title) = malloc(sizeof(char **) * (*total_records_count));
        (*article_author) = malloc(sizeof(char **) * (*total_records_count));
        (*article_time) = malloc(sizeof(char **) * (*total_records_count));

        for (int i = 0; i < (*total_records_count); i++)
        {
            (*article_id)[i] = malloc(sizeof(char *) * 11);
            (*article_title)[i] = malloc(sizeof(char *) * 150);
            (*article_author)[i] = malloc(sizeof(char *) * 300);
            (*article_time)[i] = malloc(sizeof(char *) * 13);
        }
        FILE *data;
        data = fopen("KonferencnyZoznam.txt", "r");
        while (fgets(get_string, sizeof(get_string), data) != NULL)
        {
            if (read == 0)
            {
                strcpy((*article_id)[record_counter], get_string);
                read++;
            }
            else if (read == 1)
            {
                strcpy((*article_title)[record_counter], get_string);
                read++;
            }
            else if (read == 2)
            {
                strcpy((*article_author)[record_counter], get_string);
                read++;
            }
            else if (read == 3)
            {
                strcpy((*article_time)[record_counter], get_string);
                read++;
            }
            else if (read == 4)
            {
                record_counter += 1;
                read = 0;
            }
        }
        printf("Nacitane data\n");
        fclose(data);
    }
    else if (!(find_in_inputs('v', inputs)))
    {
        printf("Neotvoreny subor\n");
    }
}

void search(char *inputs, char ***article_id, char ***article_title, char ***article_author, char ***article_time, int records_counter)
{
    if (find_in_inputs('v' , inputs))
    {
        char date[8], id[3];
        int count = 0;
        scanf("%s %s", date, id);
        for (int i = 0; i < records_counter; i++)
        {
            int is_true = 1;
            if ((*article_id)[i][0] == id[0] && (*article_id)[i][1] == id[1])
            {
                for (int a = 0; a < 8; a++)
                {
                    if (!(date[a] == (*article_time)[i][a]))
                    {
                        is_true = 0;
                    }
                }
                if (is_true == 1)
                {
                    count ++;
                    for (int e = 8; e < 12; e++)
                    {
                        printf("%c", (*article_time)[i][e]);
                    }
                    printf("  ");
                    print_name((*article_author)[i] , 1);
                    printf("\t%s", (*article_title)[i]);
                }
            }
        }
        if (count == 0)
        {
            printf("Pre dany vstup neexistuju zaznamy\n");
        }

    }else{
        printf("Polia nie su vytvorene\n");
    }

}

void print_writers(char ***article_author, char ***writers, char *inputs , int *writers_count, int *total_records_count){
    char name[300];
    for (int i = 0; i < *writers_count; ++i) {
        free((*writers)[i]);
    }
    free((*writers));
    *writers_count = 0;

    for (int i = 0; i < *total_records_count; i++)
    {
        char ch;
        int index = 0, author_index = 0;
        while ((*article_author)[i][author_index] != '\n')
        {
            if ((*article_author)[i][author_index] == '#')
            {
                if((*article_author)[i][author_index] != '\n'){
                    strupr(name);
                    if (check_for_same_name(writers, name, index, (*writers_count)))
                    {
                        (*writers_count)++;
                        (*writers) = realloc((*writers) , sizeof(char **) * (*writers_count));
                        (*writers)[(*writers_count)-1] = malloc((index) * sizeof(char));
                        strcpy((*writers)[(*writers_count)-1], name);
                    }
                    if ((*article_author)[i][author_index + 3] == '\n')
                    {
                        break;
                    }else{
                        author_index += 3;
                        index = 0;
                    }
                }
            }else if((*article_author)[i][author_index] != '#'){
                name[index] = (*article_author)[i][author_index];
                index++;
                author_index++;
            }
        }
    }

    for (int i = 0; i < *writers_count; i++)
    {
        printf("%s\n" , (*writers)[i]);
    }
}

void delete_record(char ***article_id, char ***article_title, char ***article_author, char ***article_time, char *inputs, int *total_records_count)
{
    if (find_in_inputs('n', inputs))
    {
        int can_break = 0, nieco = 0;
        char record_to_find[150], copy_to_string[150];
        scanf(" %[^\n]", record_to_find);
        int count_of_same_records = find_same_records(article_title, total_records_count, record_to_find);
        while (can_break != 1)
        {
            // printf("%d" , ++nieco);
            int deleted_records = 0;
            for (int i = 0; i < *total_records_count; i++)
            {
                int is_true = 1, count = 0;
                while (record_to_find[count] != '\0')
                {
                    if ((*article_title)[i][count] != record_to_find[count])
                    {
                        is_true = 0;
                        break;
                    }
                    count++;
                }
                if (is_true == 1)
                {
                    deleted_records++;
                    for (int a = i; a < *total_records_count -1; a++)
                    {
                        strcpy((*article_id)[a] , (*article_id)[a + 1]);
                        strcpy((*article_title)[a] , (*article_title)[a + 1]);
                        strcpy((*article_author)[a] , (*article_author)[a + 1]);
                        strcpy((*article_time)[a] , (*article_time)[a + 1]);
                    }
                }
            }

            if (deleted_records == 0)
            {
                can_break = 1;
                break;
            }
        }
        for (int i = (*total_records_count) - count_of_same_records; i < *total_records_count; i++)
        {
            free((*article_id)[i]);
            free((*article_title)[i]);
            free((*article_author)[i]);
            free((*article_time)[i]);
        }
        (*total_records_count) -= count_of_same_records;

        (*article_id) = realloc((*article_id), *total_records_count * sizeof(char **));
        (*article_title) = realloc((*article_title), *total_records_count * sizeof(char **));
        (*article_author) = realloc((*article_author), *total_records_count * sizeof(char **));
        (*article_time) = realloc((*article_time), *total_records_count * sizeof(char **));

        printf("Vymazalo sa : %d zaznamov !\n" , count_of_same_records);
    }
    // dealocate(inputs, article_id, article_title, article_author, article_time, *total_records_count);
}

void dealocate(char *inputs, char ***article_id, char ***article_title, char ***article_author, char ***article_time, int *records_counter)
{
    if (find_in_inputs('n', inputs))
    {
        deallocate_array(article_id, *records_counter);
        deallocate_array(article_title, *records_counter);
        deallocate_array(article_author, *records_counter);
        deallocate_array(article_time, *records_counter);
        *records_counter = 0;
    }
}

int main()
{
    char user_input;
    int is_input_correct = 0, inputs_count = 1;
    int *total_records_count = (int *)malloc(sizeof(int));
    *total_records_count = 0;
    int *writers_count = (int *)malloc(sizeof(int));
    *writers_count = 0;
    char correct_inputs[] = {'v', 'p', 'n', 's', 'w', 'h', 'z', 'd', 'k'};
    char *inputs = malloc(sizeof(char) * 3);

    // Allocation of arrays
    char **article_id = NULL, **article_title = NULL, **article_author = NULL, **article_time = NULL, **writers = NULL;

   while (1)
   {
       scanf(" %c", &user_input);
       for (int i = 0; i < 9; i++)
       {
           if (user_input == correct_inputs[i])
           {
               is_input_correct = 1;
               inputs = realloc(inputs, sizeof(char) * ++inputs_count);
           }
       }

       if (is_input_correct == 0)
       {
           printf("Invalid input\n");
       }
       else
       {
           switch (user_input)
           {
           case 'n':
               load_file(&article_id, &article_title, &article_author, &article_time, inputs, total_records_count);
               break;
           case 'v':
               output(inputs, &article_id, &article_title, &article_author, &article_time, total_records_count);
               break;
           case 's':
               search(inputs, &article_id, &article_title, &article_author, &article_time, *total_records_count);
               break;
           case 'd':
               dealocate(inputs, &article_id, &article_title, &article_author, &article_time, total_records_count);
               break;
           case 'p':
               add_record(&article_id, &article_title, &article_author, &article_time, total_records_count);
               break;
           case 'z':
               delete_record(&article_id, &article_title, &article_author, &article_time, inputs, total_records_count);
               break;
           case 'w':
               print_writers(&article_author, &writers, inputs, writers_count, total_records_count);
               break;
           case 'k':
               dealocate(inputs, &article_id, &article_title, &article_author, &article_time, total_records_count);
               free(inputs);
               exit(1);
               break;
           }
           inputs[inputs_count - 1] = user_input;
       }
   }
    return 0;
}