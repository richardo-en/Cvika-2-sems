#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct name_and_role
{
    char first_name[75];
    char last_name[75];
    char role;
} name_and_role;

typedef struct article_information
{
    char article_title[150];
    char id[12];
    char time[14];
    int count_of_names;
    name_and_role *new_name_and_role;
    struct article_information *next;
} ARTICLE_INFORMATION;

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

// Seperates first name and last name and returns them as pointer
void seperate_name(char fullname[50], char **first_name, char **last_name, int lenght)
{
    int last_name_count = lenght;
    while (fullname[last_name_count] != ' ')
    {
        last_name_count--;
    }

    *first_name = malloc((last_name_count) * sizeof(char));
    *last_name = malloc((lenght - last_name_count) * sizeof(char));
    int count = 0, current_index = 0;
    while (count != lenght)
    {
        if (count < last_name_count)
        {
            (*first_name)[current_index] = fullname[count];
        }
        else if (count > last_name_count)
        {
            (*last_name)[current_index] = fullname[count];
        }

        if (count == last_name_count)
        {
            current_index = -1;
        }

        current_index++;
        count++;
    }
    (*first_name)[last_name_count] = '\0';
    (*last_name)[lenght - last_name_count - 1] = '\0';
}

// Prints to console date in rigt format
void print_date(char article_date[])
{
    for (int i = 0; i < 12; i++)
    {
        printf("%c", article_date[i]);
        if (i == 3 || i == 5)
        {
            printf(".");
        }

        if (i == 7)
        {
            printf(" ");
        }
        else if (i == 9)
        {
            printf(":");
        }
    }
    printf("\n");
}

// Merging first name and last name from current list and comparing with name from input
// returns 0 when same name were found in list otherwise return 1
int find_in_names(ARTICLE_INFORMATION **list, char name[150])
{
    int index = 0, list_letter, input_letter;
    char list_name[150];
    for (int i = 0; i < (*list)->count_of_names; i++)
    {
        strcpy(list_name, (*list)->new_name_and_role[i].first_name);
        strcat(list_name, " ");
        strcat(list_name, (*list)->new_name_and_role[i].last_name);
        index = 0;
        while (name[index] != '\n')
        {
            list_letter = list_name[index];
            input_letter = name[index];

            if ((name[index] == list_name[index]) || (name[index] == (list_name[index] + 32)) || (name[index] == (list_name[index] - 32)))
            {
                if (name[(index + 1)] == '\n' && ((*list)->new_name_and_role[i].role == 'a' || (*list)->new_name_and_role[i].role == 'A'))
                {
                    return 0;
                }
                index++;
            }
            else if ((name[index] != list_name[index]) && (name[index] != (list_name[index] + 32)) && (name[index] != (list_name[index] - 32)))
            {
                break;
            }
        }
        list_name[0] = '\0';
    }
    return 1;
}

// It does what it is called ( ͡° ͜ʖ ͡°)
void remove_newline(ARTICLE_INFORMATION **list)
{
    int len = strlen((*list)->article_title);
    if (len > 0 && (*list)->article_title[len - 1] == '\n')
    {
        (*list)->article_title[len - 1] = '\0';
    }
}

// Reversing list so last list is now first and previous first list is now last
void reverse_list(ARTICLE_INFORMATION **list)
{
    ARTICLE_INFORMATION *prev = NULL;
    ARTICLE_INFORMATION *current = *list;
    ARTICLE_INFORMATION *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *list = prev;
}

// Returns total count of names (needed for allocation)
int get_count_of_names(char *names)
{
    int index = 0, count = 0;
    while (names[index] != '\n')
    {
        if (names[index] == '#')
        {
            index += 2;
            count++;
        }
        index++;
    }
    return count;
}

// It does what it is called ( ͡° ͜ʖ ͡°)
void deallocate_article_list(ARTICLE_INFORMATION **list)
{
    int count = 1;
    int volaco; 
    ARTICLE_INFORMATION *current = *list;
    while (current != NULL)
    {
        volaco = current->count_of_names;
        for (int i = 0; i < volaco; i++)
        {
            free(current->new_name_and_role[i].first_name);
            free(current->new_name_and_role[i].last_name);
            count++;

        }
        current->new_name_and_role = NULL; // C is best language. Firstly deallocation was working and at day of submiting assignment this function stopped working because of this line :). It's C,  just enjoy
        free(current->new_name_and_role);
        ARTICLE_INFORMATION *next_list = current->next;
        free(current);
        current = next_list;
    }
    *list = current;
}

// Allocate structure name and role and appends to it names
void append_names(ARTICLE_INFORMATION **list, char get_string[150])
{
    char full_name[50], *first_name = NULL, *last_name = NULL, role_from_string;
    int index = 0, count = 0, index_to_write = 0;
    (*list)->count_of_names = get_count_of_names(get_string);
    (*list)->new_name_and_role = (struct name_and_role *)malloc((*list)->count_of_names * sizeof(struct name_and_role));
    while (get_string[index] != '\n')
    {
        if (get_string[index] != '#')
        {
            full_name[index_to_write] = get_string[index];
            index_to_write++;
            index++;
        }
        else
        {
            seperate_name(full_name, &first_name, &last_name, index_to_write);
            index_to_write = 0;
            role_from_string = get_string[index + 1];
            strcpy((*list)->new_name_and_role[count].first_name, first_name);
            strcpy((*list)->new_name_and_role[count].last_name, last_name);
            (*list)->new_name_and_role[count].role = role_from_string;
            count++;

            free(first_name);
            free(last_name);
            index += 3;
        }
    }
}

// Basically it is function called N(nacitaj)
int load_file(ARTICLE_INFORMATION **article_list, char *inputs, int *total_records_count)
{
    int record_counter = 0, read = 0, is_end = 0;
    char get_string[300];

    // Check if deallocation is needed
    if (find_in_inputs('n', inputs) && *total_records_count != 0)
    {
        deallocate_article_list(article_list);
        *total_records_count = 0;
    }

    FILE *data;
    data = fopen("KonferencnyZoznam2.txt", "r");

    if (data == NULL)
    {
        printf("Zaznamy neboli nacitane!\n");
        return 0;
    }

    ARTICLE_INFORMATION *current_list = *article_list;

    while (fgets(get_string, sizeof(get_string), data) != NULL)
    {
        // Assign value to array based on count of lines
        if (read == 0)
        {
            current_list = (ARTICLE_INFORMATION *)malloc(sizeof(ARTICLE_INFORMATION));
            read++;
        }
        else if (read == 1)
        {
            strcpy(current_list->id, get_string);
            read++;
        }
        else if (read == 2)
        {
            strcpy(current_list->article_title, get_string);
            read++;
        }
        else if (read == 3)
        {
            append_names(&current_list, get_string);
            read++;
        }
        else if (read == 4)
        {
            strcpy(current_list->time, get_string);
            current_list->next = *article_list;
            *article_list = current_list;

            read = 0;
            *total_records_count += 1;
        }
    }
    printf("Nacitalo sa %d zaznamov\n", *total_records_count);
    fclose(data);
}

// Basically it is function called v(vypis)
void print_list(ARTICLE_INFORMATION *list)
{
    int count = 1;
    char print_time[14];
    while (list != NULL)
    {

        printf("%d.\nID Prispevku: %sNazov prispevku: %sMena autorov:\n", count, list->id, list->article_title);
        for (int i = 0; i < list->count_of_names; i++)
        {
            printf("\t%d: %s %s (%c)\n", (i + 1), list->new_name_and_role[i].first_name, list->new_name_and_role[i].last_name, list->new_name_and_role[i].role);
        }

        strcpy(print_time, list->time);
        printf("Datum a Cas: ");
        print_date(print_time);
        count++;
        list = list->next;
    }
}

// Updates information in list 
void update(ARTICLE_INFORMATION **list)
{
    char id_to_find[9], form[3], id_from_list[9], new_id[12];
    int was_edited = 0;
    ARTICLE_INFORMATION *current = *list;
    while (1)
    {
        scanf(" %s %s", id_to_find, form);
        if ((form[0] == 'P' || form[0] == 'U') && (form[1] == 'P' || form[1] == 'D') && atoi(id_to_find) % 15 == 0)
        {
            while (current != NULL)
            {
                for (int i = 0; i < 8; i++)
                {
                    id_from_list[i] = current->id[i + 2];
                }

                if (strcmp(id_from_list, id_to_find) == 0 && was_edited == 0)
                {
                    printf("Prispevok s nazvom ");
                    int index = 0;
                    while (current->article_title[index] != '\n')
                    {
                        printf("%c", current->article_title[index]);
                        index++;
                    }

                    printf(" sa bude prezentovat %s [%c%c]\n", form, current->id[0], current->id[1]);
                    new_id[0] = form[0];
                    new_id[1] = form[1];
                    for (int i = 0; i < 8; i++)
                    {
                        new_id[i + 2] = id_to_find[i];
                    }

                    strcpy(current->id, new_id);
                    current->id[10] = '\n';
                    was_edited = 1;
                }

                current = current->next;
            }
        }

        if (was_edited == 0)
        {
            printf("Zadane udaje nie su korektne, zadaj novy retazec: ");
        }
        else if (was_edited == 1)
        {
            return;
        }
    }
}

// Adds to list record basedon index
void add_to_list(ARTICLE_INFORMATION **list)
{
    char id[12], time[14], title[150], names[150];
    int was_added = 0;
    int count_of_name, input_count;
    ARTICLE_INFORMATION *current = *list;
    ARTICLE_INFORMATION *new_list = NULL;
    ARTICLE_INFORMATION *new_list_tail = NULL;
    int count = 0;
    scanf(" %d", &input_count);
    scanf(" %s", id);
    scanf(" %[^'\n']", title);
    scanf(" %[^'\n']", names);
    scanf(" %s", time);
    strcat(names, "\n");
    strcat(title, "\n");
    while (current != NULL)
    {
        ARTICLE_INFORMATION *new_node = malloc(sizeof(ARTICLE_INFORMATION));

        if (count == (input_count - 1))
        {
            strcpy(new_node->id, id);
            strcpy(new_node->article_title, title);
            append_names(&new_node, names);
            strcpy(new_node->time, time);
            new_node->id[10] = '\n';
            was_added = 1;
        }
        else
        {
            memcpy(new_node, current, sizeof(ARTICLE_INFORMATION));
            current = current->next;
        }

        if (new_list == NULL)
        {
            new_list = new_node;
            new_list_tail = new_node;
        }
        else
        {
            new_list_tail->next = new_node;
            new_list_tail = new_node;
        }
        new_node = new_node->next;
        count++;
    }

    if (was_added == 0)
    {
        ARTICLE_INFORMATION *new_node = malloc(sizeof(ARTICLE_INFORMATION));
        strcpy(new_node->id, id);
        strcpy(new_node->article_title, title);
        append_names(&new_node, names);
        strcpy(new_node->time, time);
        new_node->id[10] = '\n';
        new_node->next = NULL;
        if (new_list == NULL)
        {
            new_list = new_node;
            new_list_tail = new_node;
        }
        else
        {
            new_list_tail->next = new_node;
            new_list_tail = new_node;
        }
    }

    *list = new_list;
}

// Removes from list record based on name
void remove_from_list(ARTICLE_INFORMATION **list)
{
    char names[150];
    ARTICLE_INFORMATION *current = *list;
    ARTICLE_INFORMATION *new_list = NULL;
    ARTICLE_INFORMATION *new_list_tail = NULL;
    scanf(" %[^'\n']", names);
    strcat(names, "\n");
    ARTICLE_INFORMATION *prev = NULL;
    while (current != NULL)
    {
        if (find_in_names(&current, names))
        {
            ARTICLE_INFORMATION *new_node = malloc(sizeof(ARTICLE_INFORMATION));
            memcpy(new_node, current, sizeof(ARTICLE_INFORMATION));
            new_node->next = NULL;
            if (new_list == NULL)
            {
                new_list = new_node;
                new_list_tail = new_node;
            }
            else
            {
                new_list_tail->next = new_node;
                new_list_tail = new_node;
            }
        }
        else
        {
            char *newline_pos = strchr(current->article_title, '\n');
            if (newline_pos != NULL)
            {
                *newline_pos = '\0';
            }
            printf("Prispevok s nazvom %s bol vymazany.\n", current->article_title);
            if (prev == NULL)
            {
                *list = current->next;
                free(current);
                current = *list;
                continue;
            }
            prev->next = current->next;
            free(current);
            current = prev->next;
            continue;
        }
        prev = current;
        current = current->next;
    }
    *list = new_list;
}

// Switching between two specified records
void change_order(ARTICLE_INFORMATION **list, int *total_records_count) {
    int index1, index2, i;
    ARTICLE_INFORMATION *node1, *node2, *prev1, *prev2, *temp, *current = *list;

    // printf("Zadajte cisla zaznamu pre zamenu\n");
    scanf("%d %d", &index1, &index2);

    if (index1 < 1 || index1 > *total_records_count ||
        index2 < 1 || index2 > *total_records_count ||
        index1 == index2) {
        printf("Indexi neexistuju\n");
        return;
    }

    i = 1;
    while (current != NULL) {
        if (i == index1) {
            node1 = current;
        }
        if (i == index2) {
            node2 = current;
        }
        current = current->next;
        i++;
    }

    if (node1 == NULL || node2 == NULL) {
        printf("Indexi neexistuju\n");
        return;
    }

    current = *list;
    prev1 = NULL;
    prev2 = NULL;
    while (current != NULL) {
        if (current == node1) {
            break;
        }
        prev1 = current;
        current = current->next;
    }
    current = *list;
    while (current != NULL) {
        if (current == node2) {
            break;
        }
        prev2 = current;
        current = current->next;
    }

    if (prev1 != NULL) {
        prev1->next = node2;
    } else {
        *list = node2;
    }
    if (prev2 != NULL) {
        prev2->next = node1;
    } else {
        *list = node1;
    }
    temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;

    // printf("Zaznam %d sa prehodil so zaznamom %d.\n", index1, index2);
}

int main()
{
    char user_input;
    int is_input_correct = 0, inputs_count = 1;
    int *total_records_count = (int *)malloc(sizeof(int));
    *total_records_count = 0;
    char correct_inputs[] = {'v', 'p', 'n', 's', 'w', 'h', 'z', 'd', 'k'};
    char *inputs;

    ARTICLE_INFORMATION *article_information = NULL;

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
                load_file(&article_information, inputs, total_records_count);
                reverse_list(&article_information);
                break;
            case 'v':
                print_list(article_information);
                break;
            case 'a':
                update(&article_information);
                break;
            case 'p':
                add_to_list(&article_information);
                break;
            case 'z':
                remove_from_list(&article_information);
                break;
            case 'r':
                change_order(&article_information , total_records_count);
                break;
            case 'k':
                deallocate_article_list(&article_information);
                free(inputs);
                exit(1);
            }
            inputs[inputs_count - 1] = user_input;
        }
    }
    return 0;
}