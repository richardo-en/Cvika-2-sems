#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// CONTROL FUNCTIONS

// Checks if id is only PD,UD, PP, UP. If not prints wrong ID
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

void check_for_last_record(char ***article_id, char ***article_title, char ***article_author, char ***article_time, int *total_records_count, char record_to_find[]){
    while (1)
    {
        if (strcmp((*article_title)[*total_records_count-1] , record_to_find) == 1)
        {
            free((*article_id)[*total_records_count -1]);
            free((*article_title)[*total_records_count -1]);
            free((*article_author)[*total_records_count -1]);
            free((*article_time)[*total_records_count -1]);
            if ((*total_records_count -1) > 0)
            {
                *total_records_count -= 1;
            }else{
                *total_records_count = 0;
                free((*article_id));
                free((*article_title));
                free((*article_author));
                free((*article_time));
            } 
        }else{
            break;
        }
        
    }
    
}

// Decides if zero needed to be printed out or no for function print_date()
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

// Returns to function delete_record(z) count of duplicative records
int find_same_records(char ***article_title, int *total_records_count, char record_to_find[])
{
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

// Returns to function print_writers if name is already in list of writers or not
//  if there is same name function print_writers wont allocate memory and add new name
int check_for_same_name(char ***writers, char name[], int index, int writes_count)
{
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

// PRINT FUNCTIONS

// Prints name but insted of using #?# it use comma(,) if there are more records
void print_name(char article_authors[], int first_name)
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
            }
            else
            {
                i += 2;
                if (article_authors[(i + 1)] != '\n')
                {
                    printf(", ");
                }
            }
        }
    }
}

// Prints date in correct format
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

// GET FUNCTIONS (RETURN SEARCHED VALUE)

// Returns to function load_file(n) count of total amount of records
//  so function nows how much is needed to allocatee
int get_lines(FILE** data)
{
    rewind(*data);
    char get_string[150];
    int lines = 0;

    if ((*data) == NULL)
    {
        printf("Chyba pri otvarani suboru\n");
        return 0;
    }

    do
    {
        lines++;
    } while (fgets(get_string, sizeof(get_string), *data) != NULL);
    while (lines % 5 != 0)
    {
        lines++;
    }

    return (lines / 5);
}

// This function is basically used in every function of our assignment.
// It is used to find if some function was called. If yes function retrns true.
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

// ADITIONAL FUNCTIONS
// Deallocates array
void deallocate_array(char ***array, int p)
{
    for (int i = 0; i < p; i++)
    {
        free((*array)[i]);
    }
    free((*array));
}

// ASSIGMENT FUNCTIONS

// Represents function - V
void output(char *inputs, char ***article_id, char ***article_title, char ***article_author, char ***article_time, int *records_counter, FILE** data)
{
    char file_input[300];
    int line = 0;
    // Check if program has to read information from arrays or file
    if ((find_in_inputs('v', inputs)) && ((find_in_inputs('n', inputs) || find_in_inputs('p', inputs))) && *records_counter != 0)
    {
        for (int i = 0; i < *records_counter; i++)
        {
            check_id((*article_id)[i]);
            printf("Nazov prispevku: %sMena Autorov: ", (*article_title)[i]);
            print_name((*article_author)[i], 0);
            printf("\n");
            print_date((*article_time)[i]);
            printf("\n");
        }
    }
    else
    {
        if (!find_in_inputs('v' , inputs))
        {
            (*data) = fopen("KonferencnyZoznam.txt", "r");
        }else{
            rewind(*data);
        }
        
        if (*data == NULL)
        {
            printf("Neotvoreny subor\n");
        }else{

        }
        while (!feof(*data))
        {
            fgets(file_input, sizeof(file_input), (*data));
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
                print_name(file_input, 0);
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
    }
}

// Represents function - P
void add_record(char ***article_id, char ***article_title, char ***article_author, char ***article_time, int *total_records_count)
{
    *total_records_count += 1;
    (*article_id) = realloc((*article_id), *total_records_count * sizeof(char **));
    (*article_title) = realloc((*article_title), *total_records_count * sizeof(char **));
    (*article_author) = realloc((*article_author), *total_records_count * sizeof(char **));
    (*article_time) = realloc((*article_time), *total_records_count * sizeof(char **));

    (*article_id)[(*total_records_count) - 1] = malloc(sizeof(char) * 11);
    (*article_title)[(*total_records_count) - 1] = malloc(sizeof(char) * 150);
    (*article_author)[(*total_records_count) - 1] = malloc(sizeof(char) * 300);
    (*article_time)[(*total_records_count) - 1] = malloc(sizeof(char) * 13);

    scanf(" %s", (*article_id)[*total_records_count - 1]);
    scanf(" %[^\n]", (*article_title)[*total_records_count - 1]);
    scanf(" %[^\n]", (*article_author)[*total_records_count - 1]);
    scanf(" %s", (*article_time)[*total_records_count - 1]);

    // Add \n to the end of string
    strcat((*article_time)[*total_records_count - 1], "\n");
    strcat((*article_title)[*total_records_count - 1], "\n");
    strcat((*article_author)[*total_records_count - 1], "\n");
    strcat((*article_time)[*total_records_count - 1], "\n");

    printf("Zaznam sa podarilo pridat\n");
}

// Represents function - N
int load_file(char ***article_id, char ***article_title, char ***article_author, char ***article_time, char *inputs, int *total_records_count, FILE** data)
{
    int record_counter = 0, read = 0, is_end = 0;
    char get_string[300];

    // Make sure programm can load values from file to arrays
    if (find_in_inputs('v', inputs))
    {
        // Check if deallocation is needed
        if (find_in_inputs('n', inputs) && *total_records_count != 0)
        {
            deallocate_array(article_id, *total_records_count);
            deallocate_array(article_title, *total_records_count);
            deallocate_array(article_author, *total_records_count);
            deallocate_array(article_time, *total_records_count);
        }
        // Get total amount of arrays for allocation
        *total_records_count = get_lines(data);

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
        rewind((*data));
        while (fgets(get_string, sizeof(get_string), *data) != NULL)
        {
            // Assign value to array based on count of lines
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
    }
    else if (!(find_in_inputs('v', inputs)))
    {
        printf("Neotvoreny subor\n");
    }
}

// Represents function - S
void search(char *inputs, char ***article_id, char ***article_title, char ***article_author, char ***article_time, int records_counter)
{
    // Make sure arrays are available
    if (find_in_inputs('n', inputs) && records_counter != 0)
    {
        char date[8], id[3];
        int count = 0;
        scanf("%s %s", date, id);
        for (int i = 0; i < records_counter; i++)
        {
            int is_true = 1;
            // Check if letters of id are equal
            if ((*article_id)[i][0] == id[0] && (*article_id)[i][1] == id[1])
            {
                // Check if date is equal
                for (int a = 0; a < 8; a++)
                {
                    if (!(date[a] == (*article_time)[i][a]))
                    {
                        is_true = 0;
                    }
                }
                // If record is equal to user input print out information
                if (is_true == 1)
                {
                    count++;
                    for (int e = 8; e < 12; e++)
                    {
                        printf("%c", (*article_time)[i][e]);
                    }
                    printf("  ");
                    // 1 in print name means function will print just first name
                    print_name((*article_author)[i], 1);
                    printf("\t%s", (*article_title)[i]);
                }
            }
        }
        if (count == 0)
        {
            printf("Pre dany vstup neexistuju zaznamy\n");
        }
    }
    else
    {
        printf("Polia nie su vytvorene\n");
    }
}

// Represents function - W
void print_writers(char ***article_author, char ***MENA, char *inputs, int *writers_count, int *total_records_count)
{
    char name[300];
    // Check if arrays are available
    if (*total_records_count == 0)
    {
        printf("Polia nie su vytvorene\n");
    }
    else
    {
        // Check if allocation is needed
        if (find_in_inputs('w', inputs) && *writers_count != 0)
        {
            deallocate_array(MENA, *writers_count);
            *writers_count = 0;
        }

        // Loop through all records
        for (int i = 0; i < *total_records_count; i++)
        {
            char ch;
            int index = 0, author_index = 0;
            // While record of names arent on th end continue
            while ((*article_author)[i][author_index] != '\n')
            {
                // If postion of character on authors name is on first #
                if ((*article_author)[i][author_index] == '#')
                {
                    if ((*article_author)[i][author_index] != '\n')
                    {
                        strupr(name);
                        // Check if in array writers isn't already same name
                        if (check_for_same_name(MENA, name, index, *writers_count))
                        {
                            // Set end of variable name
                            name[index] = '\0';
                            (*writers_count)++;
                            // If it's first allocation than malloc else reallocate array
                            if (*writers_count == 1)
                            {
                                (*MENA) = malloc(sizeof(char **) * (*writers_count));
                            }
                            else
                            {
                                (*MENA) = realloc((*MENA), sizeof(char **) * (*writers_count));
                            }
                            (*MENA)[(*writers_count) - 1] = malloc((index) * sizeof(char));
                            // Assign value to array
                            strcpy((*MENA)[(*writers_count) - 1], name);
                        }
                        // If it is last author name of this record break while else reset index count for name and increase author index count of authors names
                        if ((*article_author)[i][author_index + 3] == '\n')
                        {
                            break;
                        }
                        else
                        {
                            author_index += 3;
                            index = 0;
                        }
                        // Clear helping variable name
                        name[0] = '\0';
                    }
                    // If position of character of author isn't # than assign value from author ot variable name and move to next character
                }
                else if ((*article_author)[i][author_index] != '#')
                {
                    name[index] = (*article_author)[i][author_index];
                    index++;
                    author_index++;
                }
            }
        }
    }
}

// Represents function - Z
void delete_record(char ***article_id, char ***article_title, char ***article_author, char ***article_time, char *inputs, int *total_records_count)
{
    // Make sure array is available
    if (find_in_inputs('n', inputs) && *total_records_count != 0)
    {
        int can_break = 0, nieco = 0;
        char record_to_find[150], copy_to_string[150];
        scanf(" %[^\n]", record_to_find);
        // Get count of same records based on user input
        int count_of_same_records = find_same_records(article_title, total_records_count, record_to_find);
        //If is last record of array same as user input remove it otherwise it will make infinit loop
        check_for_last_record(article_id, article_title, article_author, article_time, total_records_count, record_to_find);
        // While loop only breaks when count of deleted records is equal to 0
        while (can_break != 1)
        {
            int deleted_records = 0;
            // Loop through all records of array
            for (int i = 0; i < *total_records_count; i++)
            {
                int is_true = 1, count = 0;
                // Check if record is same as user input
                while (record_to_find[count] != '\0')
                {
                    if ((*article_title)[i][count] != record_to_find[count])
                    {
                        is_true = 0;
                        break;
                    }
                    count++;
                }
                // If record of array that we are for-looping through is same, increase count of deleted records
                // and assign value of array[a+1] to array[a]
                if (is_true == 1)
                {
                    deleted_records++;
                    for (int a = i; a < *total_records_count - 1; a++)
                    {
                        strcpy((*article_id)[a], (*article_id)[a + 1]);
                        strcpy((*article_title)[a], (*article_title)[a + 1]);
                        strcpy((*article_author)[a], (*article_author)[a + 1]);
                        strcpy((*article_time)[a], (*article_time)[a + 1]);
                    }
                }
            }
            // If in array is same record as user input count of deleted records is always greater than 0
            // Before each iteration is count of deleted records set back to 0
            if (deleted_records == 0)
            {
                can_break = 1;
                break;
            }
        }
        // Reallocate array based on variable count_of_same_records
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

        printf("Vymazalo sa : %d zaznamov !\n", count_of_same_records);
    }
    else
    {
        printf("Polia nie su vytvorene\n");
    }
}

// Represents function - D
void dealocate(char *inputs, char ***article_id, char ***article_title, char ***article_author, char ***article_time, char ***writers, int *writers_counter, int *records_counter)
{
    // Check if there are some arrays available
    if (find_in_inputs('n', inputs) || find_in_inputs('p', inputs))
    {
        deallocate_array(article_id, *records_counter);
        deallocate_array(article_title, *records_counter);
        deallocate_array(article_author, *records_counter);
        deallocate_array(article_time, *records_counter);
        // Check if is needed to deallocate writers array too
        if ((*writers_counter) != 0)
        {
            deallocate_array(writers, *writers_counter);
            *writers_counter = 0;
        }
        *records_counter = 0;
    }
}

// Represents function - H
void histogram(char *inputs, char ***article_id, char ***article_time, int *total_records_count)
{
    // Check if arrays are available
    if (find_in_inputs('v', inputs) && *total_records_count != 0)
    {
        int time = 0, up_count = 0, ud_count = 0, pp_count = 0, pd_count = 0;
        char string_to_campare[2];
        // Print header
        printf("  hodina\tUP\tUD\tPP\tPD\n");
        // Loop through times
        for (int i = 0; i < 12; i++)
        {
            if (time < 9)
            {
                printf("0%d:00 - 0%d:59:\t", time, (time + 1));
            }
            else if (time == 9)
            {
                printf("0%d:00 - %d:59:\t", time, (time + 1));
            }
            else if (time > 9)
            {
                printf("%d:00 - %d:59:\t", time, (time + 1));
            }
            // Loop through all records and make sure if record doesnt need to be counted
            for (int a = 0; a < *total_records_count; a++)
            {
                string_to_campare[0] = (*article_time)[a][8];
                string_to_campare[1] = (*article_time)[a][9];
                int time_in_int = atoi(string_to_campare);
                // Cecks if hour of array time is equal to scope of loop-through-time
                if (time_in_int == time || time_in_int == (time + 1))
                {
                    string_to_campare[0] = (*article_id)[a][0];
                    string_to_campare[1] = (*article_id)[a][1];
                    // Checks ID so program knows which value to increase
                    if (strcmp(string_to_campare, "UP") == 1)
                    {
                        up_count++;
                    }
                    else if (strcmp(string_to_campare, "UD") == 1)
                    {
                        ud_count++;
                    }
                    else if (strcmp(string_to_campare, "PP") == 1)
                    {
                        pp_count++;
                    }
                    else if (strcmp(string_to_campare, "PD") == 1)
                    {
                        pd_count++;
                    }
                }
            }
            // Print out result, reset values and increase time
            printf("%d\t%d\t%d\t%d\n", up_count, ud_count, pp_count, pd_count);
            up_count = 0, ud_count = 0, pp_count = 0, pd_count = 0;
            time += 2;
        }
    }
    else
    {
        printf(" Polia nie su vytvorene\n");
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
    FILE* data;

    // Allocation of arrays
    char **article_id = NULL, **article_title = NULL, **article_author = NULL, **article_time = NULL, **MENA = NULL;

    while (1)
    {
        scanf(" %c", &user_input);
        // Make sure user input is correct, if yes reallocate array of inputs
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
            // Call specific function
            switch (user_input)
            {
            case 'n':
                load_file(&article_id, &article_title, &article_author, &article_time, inputs, total_records_count, &data);
                break;
            case 'v':
                output(inputs, &article_id, &article_title, &article_author, &article_time, total_records_count, &data);
                break;
            case 's':
                search(inputs, &article_id, &article_title, &article_author, &article_time, *total_records_count);
                break;
            case 'd':
                dealocate(inputs, &article_id, &article_title, &article_author, &article_time, &MENA, writers_count, total_records_count);
                break;
            case 'p':
                add_record(&article_id, &article_title, &article_author, &article_time, total_records_count);
                break;
            case 'z':
                delete_record(&article_id, &article_title, &article_author, &article_time, inputs, total_records_count);
                break;
            case 'w':
                print_writers(&article_author, &MENA, inputs, writers_count, total_records_count);
                for (int i = 0; i < *writers_count; i++)
                {
                    printf("%s\n", MENA[i]);
                }
                
                break;
            case 'h':
                histogram(inputs, &article_id, &article_time, total_records_count);
                break;
            case 'k':
                dealocate(inputs, &article_id, &article_title, &article_author, &article_time, &MENA, writers_count, total_records_count);
                free(inputs);
                fclose(data);
                exit(1);
                break;
            }
            // Assign value to inputs
            inputs[inputs_count - 1] = user_input;
        }
    }
    return 0;
}