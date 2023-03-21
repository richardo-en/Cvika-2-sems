#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void delete_record(char **article_id, char **article_title, char **article_author, char **article_time, char *inputs, int *total_records_count);
void dealocate(char *inputs, char ***article_id, char ***article_title, char ***article_author, char ***article_time, int records_counter);

// Control functions
void check_id(char *id_list)
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

// Prtint function
void print_name(char *article_authors)
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
            i += 2;
            if (article_authors[(i + 1)] != '\n')
            {
                printf(", ");
            }
        }
    }
}

void print_date(char *article_date)
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

int testing(char **list, int records_count)
{
    for (int i = 0; i < records_count; i++)
    {
        for (int a = 0; a < 11; a++)
        {
            printf("%c", list[i][a]);
        }
    }
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
void output(char *inputs, char **article_id, char **article_title, char **article_author, char **article_time, int records_counter)
{
    char file_input[300];
    if (find_in_inputs('v', inputs))
    {
        printf("Sme za prvou podmienkou eeeeeeeejha!\n");
        if (find_in_inputs('n', inputs) || find_in_inputs('p', inputs))
        {
            printf("Sme za DRUHOU podmienkou eeeeeeeejha!\n");
            for (int i = 0; i < records_counter; i++)
            {
                // check_id(article_id[i]);
                printf("%c", article_id[i][0]);
                // print_name(article_author[i]);
                // print_date(article_time[i]);
                // printf("%c" , article_id[i]);
                // printf("%s" , article_title[i]);
                // printf("%s" , article_author[i]);
                // printf("%s" , article_time[i]);
            }
        }
        printf("vypisalo to cez listy eeeejha!\n");
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
            // printf("%s", file_input);
        }
        printf("vypisalo to cez subor naaaaah!\n");
        fclose(data);
    }
}

void add_record(char **article_id, char **article_title, char **article_author, char **article_time, int *total_records_count)
{
    char id[12], title[81], author[81], time[14];

    *total_records_count += 1;
    article_id = (char **)realloc(article_id, *total_records_count * sizeof(char *));
    article_title = (char **)realloc(article_title, *total_records_count * sizeof(char *));
    article_author = (char **)realloc(article_author, *total_records_count * sizeof(char *));
    article_time = (char **)realloc(article_time, *total_records_count * sizeof(char *));

    article_id[*total_records_count - 1] = malloc(sizeof(char) * (11));
    article_title[*total_records_count - 1] = malloc(sizeof(char) * (80));
    article_author[*total_records_count - 1] = malloc(sizeof(char) * (80));
    article_time[*total_records_count - 1] = malloc(sizeof(char) * (13));

    scanf(" %s", article_id[*total_records_count - 1]);
    scanf(" %[^\n]", article_title[*total_records_count - 1]);
    scanf(" %[^\n]", article_author[*total_records_count - 1]);
    scanf(" %s", article_time[*total_records_count - 1]);

    // strcpy(article_id[*total_records_count - 1] , id);
    // strcpy(article_title[*total_records_count - 1] , title);
    // strcpy(article_author[*total_records_count - 1] , author);
    // strcpy(article_time[*total_records_count - 1] , time);

    for (int i = 0; i < *total_records_count; i++)
    {
        printf("%s", article_id[i]);
        printf("%s", article_title[i]);
        printf("%s", article_author[i]);
        printf("%s\n", article_time[i]);
    }
}

int load_file(char ***article_id, char ***article_title, char ***article_author, char ***article_time, char *inputs, int *total_records_count)
{
    int record_counter = 0, read = 0, is_end = 0;
    char get_string[50];

    if (find_in_inputs('n', inputs) || find_in_inputs('v', inputs))
    {
        // deallocate_array(*article_id, *total_records_count);
        // deallocate_array(*article_title, *total_records_count);
        // deallocate_array(*article_author, *total_records_count);
        // deallocate_array(*article_time, *total_records_count);

        int lines = get_lines();
        *total_records_count = lines;

        (*article_id) = malloc(sizeof(char **) * (*total_records_count));
        (*article_title) = malloc(sizeof(char **) * (*total_records_count));
        (*article_author) = malloc(sizeof(char **) * (*total_records_count));
        (*article_time) = malloc(sizeof(char **) * (*total_records_count));

        for (int i = 0; i < (*total_records_count); i++)
        {
            (*article_id)[i] = malloc(sizeof(char *) * (11));
            (*article_title)[i] = malloc(sizeof(char *) * (80));
            (*article_author)[i] = malloc(sizeof(char *) * (80));
            (*article_time)[i] = malloc(sizeof(char *) * (13));
        }
        FILE *data;
        data = fopen("KonferencnyZoznam.txt", "r");
        while(is_end == 0)
        {
            if (fgets(get_string, sizeof(get_string), data) == NULL)
            {
                is_end = 1;
                printf("Nacitane data\n");
            }else{
                switch (read)
                {
                case 0:
                    strcpy((*article_id)[record_counter], get_string);
                    read++;
                    break;
                case 1:
                    strcpy((*article_title)[record_counter], get_string);
                    read++;
                    break;
                case 2:
                    strcpy((*article_author)[record_counter], get_string);
                    read++;
                    break;
                case 3:
                    strcpy((*article_time)[record_counter], get_string);
                    read++;
                    break;
                case 4:
                    record_counter++;
                    read = 0;
                    break;
                default:
                    break;  
                }
            }

        };
        printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
        // search(inputs, article_id, article_title, article_author, article_time, *total_records_count);
        // delete_record(article_id, article_title, article_author, article_time, inputs, total_records_count);
        // for (int i = 0; i < *total_records_count; i++)
        // {
        //     printf("%s", *article_id[i]);
        //     printf("%s", *article_title[i]);
        //     printf("%s", *article_author[i]);
        //     printf("%s\n", *article_time[i]);
        // }
        fclose(data);
    }
    else if (!(find_in_inputs('v', inputs)))
    {
        printf("Neotvoreny subor\n");
    }
}

void search(char *inputs, char **article_id, char **article_title, char **article_author, char **article_time, int records_counter)
{
    char date[8], id[3];
    scanf("%s %s", date, id);
    for (int i = 0; i < records_counter; i++)
    {
        int is_true = 1;
        if (article_id[i][0] == id[0] && article_id[i][1] == id[1])
        {
            for (int a = 0; a < 8; a++)
            {
                if (!(date[a] == article_time[i][a]))
                {
                    is_true = 0;
                }
            }
            if (is_true == 1)
            {
                for (int e = 8; e < 12; e++)
                {
                    printf("%c", article_time[i][e]);
                }
                printf("  ");
                print_name(article_author[i]);
                printf("\t%s", article_title[i]);
            }
        }
    }
}

void delete_record(char **article_id, char **article_title, char **article_author, char **article_time, char *inputs, int *total_records_count)
{
    if (find_in_inputs('n', inputs))
    {
        int change_count = 0, written_indexes = 0;
        char record_to_find[80], copy_to_string[80];
        int *indexes_to_change = (int*)malloc(sizeof(int) * (*total_records_count));
        scanf(" %[^\n]", record_to_find);
        for (int i = 0; i < *total_records_count; i++)
        {
            int is_true = 1, count = 0;
            while (record_to_find[count] != '\0')
            {
                if (article_title[i][count] != record_to_find[count])
                {
                    is_true = 0;
                }
                count++; 
            }
            if (is_true == 1)
            {
                indexes_to_change[written_indexes] = i;
                written_indexes++;
            }
        }
        written_indexes = 0;
        for (int index = 0; index < *total_records_count; index++)
        {
            for (int i = 0; i < *total_records_count; i++)
            {
                if(indexes_to_change[i] == index){
                    if((index + 1) <= *total_records_count ){
                        index++;
                    }
                }
            }
        }
        
        
        for (int z = 0; z < *total_records_count; z++)
        {
            printf("%s" , article_id[z]);
            printf("%s" , article_author[z]);
            printf("%s" , article_time[z]);
            printf("%s\n" , article_title[z]);
        }
        printf("Vymazalo sa : %d zaznamov !" , change_count);
        // dealocate(inputs, article_id, article_title, article_author, article_time, *total_records_count);
    }
}

void dealocate(char *inputs, char ***article_id, char ***article_title, char ***article_author, char ***article_time, int records_counter)
{
    if (find_in_inputs('n', inputs))
    {
        deallocate_array(article_id, records_counter);
        deallocate_array(article_title, records_counter);
        deallocate_array(article_author, records_counter);
        deallocate_array(article_time, records_counter);
    }
}

int main()
{
    char user_input;
    int is_input_correct = 0, inputs_count = 1;
    int *total_records_count = (int *)malloc(sizeof(int));
    *total_records_count = 0;
    char correct_inputs[] = {'v', 'p', 'n', 's', 'w', 'h', 'z', 'd', 'k'};
    char *inputs = malloc(sizeof(char) * inputs_count);

    // Allocation of arrays
    char **article_id = NULL, **article_title = NULL , **article_author = NULL , **article_time = NULL;

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
            inputs[inputs_count -1] = user_input;
            switch (user_input)
            {
            case 'n':
                load_file(&article_id, &article_title, &article_author, &article_time, inputs, total_records_count);
                break;
            case 'v':
                output(inputs, article_id, article_title, article_author, article_time, *total_records_count);
                break;
            case 's':
                search(inputs, article_id, article_title, article_author, article_time, *total_records_count);
                break;
            case 'd':
                dealocate(inputs, &article_id, &article_title, &article_author, &article_time, *total_records_count);
                break;
            case 'k':
                // dealocate(inputs, article_id, article_title, article_author, article_time, *total_records_count);
                free(inputs);
                exit(1);
                break;
            }
        }
    }
    return 0;
}