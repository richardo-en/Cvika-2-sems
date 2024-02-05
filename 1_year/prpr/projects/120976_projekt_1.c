#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Rewrites date to Int
void rewrite_values(int *year, int *month, int *day, int *mins, char *date, char *time)
{
    char yearS[4], monthS[2], dayS[2], hoursS[2], minsS[2];
    for (int a = 0; a < 8; a++)
    {
        if (a <= 3)
        {
            yearS[a] = date[a];
        }
        else if (a <= 5)
        {
            monthS[a - 4] = date[a];
        }
        else if (a <= 7)
        {

            dayS[a - 6] = date[a];
        }
    }
    for (int i = 0; i < strlen(time) - 1; i++)
    {
        if (i <= 2)
        {

            hoursS[i] = time[i];
        }
        else
        {
            minsS[i - 3] = time[i];
        }
    }
    (*year) = atoi(yearS);
    (*month) = atoi(monthS);
    (*day) = atoi(dayS);
    (*mins) = atoi(minsS) + atoi(hoursS) * 60;
}

//Check if is index in array
int can_be_rewritten(int *array, int a, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == a)
        {
            return 0;
        }
    }
    return 1;
}

//Dealocates array
void dealocate(int *total_counts, char ***id, char ***pos, char ***type, char ***val, char ***time, char ***date)
{
    for (int i = 0; i < (*total_counts); i++)
    {
        free((*id)[i]);
        free((*pos)[i]);
        free((*type)[i]);
        free((*val)[i]);
        free((*time)[i]);
        free((*date)[i]);
    }
    free((*id));
    free((*pos));
    free((*type));
    free((*val));
    free((*time));
    free((*date));
    (*total_counts) = 0;
}

void v(int *total_counts, char ***id, char ***pos, char ***type, char ***val, char ***time, char ***date, FILE **file)
{
    int count = 0;
    if (*total_counts == -1)
    {
        char str[50];
        (*total_counts)++;
        (*file) = fopen("dataloger.txt", "r");
        if ((*file) == NULL)
        {
            printf("Neotvoreny subor.\n");
        }

        while (fgets(str, 50, *file) != NULL)
        {
            switch (count)
            {
            case 0:
                printf("ID.  mer.  modulu: %s", str);
                break;
            case 1:
                printf("Pozícia modulu: : %s", str);
                break;
            case 2:
                printf("Typ mer. veliciny: %s", str);
                break;
            case 3:
                printf("Hodnota: %s", str);
                break;
            case 4:
                printf("Cas merania: %s", str);
                break;
            case 5:
                printf("Datum merania: %s\n", str);
                break;
            case 6:
                count = -1;
                break;
            }
            count++;
        }
    }
    else if ((*total_counts) == 0)
    {
        printf("Polia nie su vytvorene.\n");
    }
    else
    {
        for (int i = 0; i < (*total_counts); i++)
        {
            printf("ID.  mer.  modulu: %s\n", (*id)[i]);
            printf("Pozícia modulu: : %s\n", (*pos)[i]);
            printf("Typ mer. veliciny: %s\n", (*type)[i]);
            printf("Hodnota: %s\n", (*val)[i]);
            printf("Cas merania: %s\n", (*time)[i]);
            printf("Datum merania: %s\n\n", (*date)[i]);
        }
    }
}

void n(int *total_counts, char ***id, char ***pos, char ***type, char ***val, char ***time, char ***date, FILE **file)
{

    if (*total_counts == -1)
    {
        printf("Neotvoreny subor\n");
    }
    else
    {
        if ((*total_counts) != 0)
        {
            dealocate(total_counts, id, pos, type, val, time, date);
        }
        int line_count = 0, steps = 0, index = 0;
        char str[50];
        fseek(*file, 0, SEEK_SET);
        while (steps != 4)
        {
            if (steps == 0)
            {
                while (fgets(str, 50, (*file)) != NULL)
                {
                    line_count++;
                }
                line_count++;
                steps++;
            }
            else if (steps == 1)
            {

                line_count /= 7;
                (*total_counts) = line_count;
                (*id) = malloc(sizeof(char **) * line_count);
                (*pos) = malloc(sizeof(char **) * line_count);
                (*type) = malloc(sizeof(char **) * line_count);
                (*val) = malloc(sizeof(char **) * line_count);
                (*time) = malloc(sizeof(char **) * line_count);
                (*date) = malloc(sizeof(char **) * line_count);
                for (int a = 0; a < line_count; a++)
                {
                    (*id)[a] = malloc(sizeof(char *) * 6);
                    (*pos)[a] = malloc(sizeof(char *) * 15);
                    (*type)[a] = malloc(sizeof(char *) * 3);
                    (*val)[a] = malloc(sizeof(char *) * 7);
                    (*time)[a] = malloc(sizeof(char *) * 5);
                    (*date)[a] = malloc(sizeof(char *) * 9);
                }
                steps++;
                line_count = 0;
            }
            else if (steps == 2)
            {
                fseek((*file), 0, SEEK_SET);
                while (fgets(str, 50, (*file)) != NULL)
                {
                    str[strcspn(str, "\r\n")] = '\0';
                    switch (line_count)
                    {
                    case 0:
                        strcpy((*id)[index], str);
                        break;
                    case 1:
                        strcpy((*pos)[index], str);
                        break;
                    case 2:
                        strcpy((*type)[index], str);
                        break;
                    case 3:
                        strcpy((*val)[index], str);
                        break;
                    case 4:
                        strcpy((*time)[index], str);
                        break;
                    case 5:
                        strcpy((*date)[index], str);
                        break;
                    case 6:
                        line_count = -1;
                        index++;
                        break;
                    }
                    line_count++;
                }
                steps++;
            }
            else
            {
                steps++;
            }
        }
    }
}

void c(int *total_counts, char ***id, char ***date)
{
    int d = 0, index = 0, lines = 0, count = 0, ciach_month = 0, ciach_year = 0, year = 0, month = 0, month_count = 0, found_record = -1, wm_index = 0;
    char s[50], record_month[3], ciach_id[6], record_year[5], **was_mentioned = NULL;
    if ((*total_counts) == -1)
    {
        printf("Neotvoreny subor.\n");
    }
    else if ((*total_counts) == 0)
    {
        printf("Polia nie su vytvorene.\n");
    }
    else
    {

        while (d <= 0)
        {
            scanf(" %d", &d);
        }

        FILE *fr = fopen("ciachovanie.txt", "r");
        if (fr == NULL)
        {
            printf("Nepodarilo sa otvorit subor ciachovanie.text.\n");
        }
        while (fgets(s, 50, fr) != NULL)
        {
            s[strcspn(s, "\r\n")] = 0;
            switch (lines)
            {
            // Loads id from file
            case 0:
                ++count;
                if (count == 0)
                {
                    was_mentioned = malloc(sizeof(char *) * count);
                    was_mentioned[count-1] = malloc(sizeof(char) * 6);
                }
                else
                {
                    was_mentioned = realloc(was_mentioned, sizeof(char *) * count);
                    was_mentioned[count-1] = malloc(sizeof(char) * 6);
                }
                strcpy(was_mentioned[count-1], s);
                strcpy(ciach_id, s);
                break;
            // Changes year and month from file to int
            case 1:
                for (int b = 0; b < 6; b++)
                {
                    if (b <= 3)
                    {
                        record_year[b] = s[b];
                    }else{
                        record_month[b-4] = s[b];
                    }
                    
                }
                record_month[2] = '\0';
                record_year[4] = '\0';
                ciach_year = atoi(record_year);
                ciach_month = atoi(record_month);
                break;
            // Case 2 counts difference between months
            case 2:
                for (int i = 0; i < (*total_counts); i++)
                {
                    if (strcmp(ciach_id, (*id)[i]) == 0)
                    {
                        found_record = i;
                        for (int c = 0; c < 6; c++)
                        {
                            if (c <= 3)
                            {
                                record_year[c] = (*date)[i][c];
                            }
                            else
                            {
                                record_month[c - 4] = (*date)[i][c];
                            }
                        }
                        record_month[2] = '\0';
                        record_year[4] = '\0';
                        year = atoi(record_year);
                        month = atoi(record_month);
                        //Counts number of months
                        if (year != ciach_year || month != ciach_month)
                        {
                            if (year < ciach_year)
                            {
                                month_count = 12 - month;
                                year++;
                                month = 1;
                            }
                            else if (year > ciach_year)
                            {
                                month_count = 12 - ciach_month;
                                ciach_year++;
                                ciach_month = 1;
                            }
                            while (ciach_year != year)
                            {
                                month_count += 12;
                                year < ciach_year ? year++ : ciach_year++;
                            }
                            int mid_calculation = ciach_month - month;
                            if (mid_calculation < 0)
                            {
                                month_count -= mid_calculation;
                            }
                            else
                            {
                                month_count += mid_calculation;
                            }
                            break;
                        }
                    }
                }

                if (month_count >= d)
                {
                    printf("ID. mer. modulu [%s] má %d mesiacov po ciachovani.\n", (*id)[found_record], (month_count - d));
                }
                found_record = -1;
                month_count = 0;
                lines = -1;
                index++;
                break;
            }
            lines++;
        }

        int found = 0;
        for (int i = 0; i < (*total_counts); i++)
        {
            for (int a = 0; a < count; a++)
            {
                if ( strcmp((*id)[i], was_mentioned[a]) == 0 ){
                    found = 1;
                    break;
                }
            }
            if (found == 0)
            {
                printf("ID. mer. modulu [%s] nie je ciachovany.\n", (*id)[i]);
            }
            found = 0;
        }
        for (int i = 0; i < count; i++)
        {
            free(was_mentioned[i]);
        }
        free(was_mentioned);
        fclose(fr);
    }
}

void s(int *total_counts, char ***id, char ***pos, char ***type, char ***val, char ***time, char ***date)
{
    int current_year, current_month, current_day, current_mins, last_index, rewrite = 0;
    int year, month, day, mins, c;
    double latitude_one, latitude_two;
    char latitude_string[10];

    if ((*total_counts) == 0)
    {
        printf("Polia nie su vytvorene.\n");
    }
    else
    {

        int *selection_ids = malloc(sizeof(int) * (*total_counts));
        for (int a = 0; a < (*total_counts); a++)
        {
            selection_ids[a] = -1;
        }
        int write_index = 0, new_records_count, written_records = 0, smallest_index;
        float value = 0;
        char input_id[6], input_type[3];
        scanf(" %5s %2s", input_id, input_type);

        for (int i = 0; i < (*total_counts); i++)
        {
            if (strcmp(input_id, (*id)[i]) == 0 && strcmp(input_type, (*type)[i]) == 0)
            {
                selection_ids[write_index] = i;
                write_index++;
            }
        }
        if (write_index != 0)
        {

            new_records_count = (write_index + 1);
            write_index = 0;
            int *ordered_indexes = malloc(sizeof(int) * new_records_count);
            for (int i = 0; i < new_records_count; i++)
            {
                ordered_indexes[i] = -1;
            }

            while ((write_index + 1) != new_records_count)
            {
                for (int i = 0; i < new_records_count; i++)
                {
                    if (can_be_rewritten(ordered_indexes, selection_ids[i], new_records_count))
                    {
                        if (selection_ids[i] != -1)
                        {
                            c = selection_ids[i];
                            rewrite_values(&current_year, &current_month, &current_day, &current_mins, (*date)[c], (*time)[c]);
                            last_index = c;

                            for (int a = 0; a < new_records_count; a++)
                            {
                                if (i != a && can_be_rewritten(ordered_indexes, selection_ids[a], new_records_count))
                                {
                                    if (selection_ids[a] != -1)
                                    {
                                        c = selection_ids[a];
                                        rewrite_values(&year, &month, &day, &mins, (*date)[c], (*time)[c]);
                                        if (year < current_year && can_be_rewritten(ordered_indexes, selection_ids[a], new_records_count))
                                        {
                                            last_index = c;
                                            rewrite = 1;
                                        }
                                        else if (year == current_year)
                                        {
                                            if (day < current_day && can_be_rewritten(ordered_indexes, selection_ids[a], new_records_count))
                                            {
                                                last_index = c;
                                                rewrite = 1;
                                            }
                                            else if (day == current_day)
                                            {
                                                if (mins < current_mins && can_be_rewritten(ordered_indexes, selection_ids[a], new_records_count))
                                                {
                                                    last_index = c;
                                                    rewrite = 1;
                                                }
                                            }
                                        }
                                        if (rewrite == 1)
                                        {
                                            current_year = year;
                                            current_month = month;
                                            current_day = day;
                                            current_mins = mins;
                                            rewrite = 0;
                                        }
                                    }
                                }
                            }
                            ordered_indexes[write_index] = last_index;
                            write_index++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
            }
            FILE *output = fopen("vystup_S.txt", "w+");

            if (output == NULL)
            {
                printf("Pre dany vstup nie je vytvoreny txt subor.\n");
            }
            else
            {
                for (int i = 0; i < new_records_count; i++)
                {
                    if (ordered_indexes[i] == -1)
                    {
                        break;
                    }
                    c = ordered_indexes[i];
                    fprintf(output, "%s%s\t%.5f\t", (*date)[c], (*time)[c], atof((*val)[c]));
                    for (int a = 1; a < 7; a++)
                    {
                        latitude_string[a-1] = (*pos)[c][a];
                    }
                            latitude_string[6] = '\0';
                            latitude_one = atof(latitude_string);
                    for (int a = 7; a < 14; a++)
                    {
                        latitude_string[a-7] = (*pos)[c][a];
                    }
                        latitude_string[7] = '\0';
                        latitude_two = atof(latitude_string);
                    fprintf(output, "\t%c%.4lf\t%c%.4lf\n",(*pos)[c][0], (latitude_one/10000),(*pos)[c][7], (latitude_two/10000));
                }
                fclose(output);
                printf("Pre dany vstup je vytvoreny txt subor.\n");
                free(selection_ids);
                free(ordered_indexes);
            }
        }
        else
        {
            printf("Pre dany vstup neexistuju zaznamy.\n");
        }
    }
}

void h(int *total_counts, char ***type, char ***val)
{
    if ((*total_counts) == 0)
    {
        printf("Polia nie su vytvorene.\n");
    }
    else
    {
        char hist_type[6][3] = {"RM", "RD", "RO", "PI", "PE", "PA"};
        #define MAIN_NUM (sizeof(hist_type) / (sizeof(char) * 2))
        int count[MAIN_NUM] = {0};
        float min[MAIN_NUM] = {0}, max[MAIN_NUM] = {0};
        for (int i = 0; i < (*total_counts); i++)
        {
            float arr_val = atof((*val)[i]);
            for (int a = 0; a < MAIN_NUM; a++)
            {
                if (hist_type[a][0] == (*type)[i][0] && hist_type[a][1] == (*type)[i][1])
                {
                    count[a] += 1;
                    if (min[a] == 0 || arr_val < min[a])
                    {
                        min[a] = arr_val;
                    }
                    if (max[a] == 0 || max[a] < arr_val)
                    {
                        max[a] = arr_val;
                    }
                    break;
                }
            }
        }
        printf("Typ mer. vel.\tPocetnost\tMinimum\tMaximum\n");
        for (int i = 0; i < MAIN_NUM; i++)
        {
            if (count[i] != 0)
            {
                printf("    %s\t\t    %d\t\t %.2f\t %.2f\n", hist_type[i], count[i], min[i], max[i]);
            }
        }
    }
}

void z(int *total_counts, char ***id, char ***pos, char ***type, char ***val, char ***time, char ***date)
{
    int count = 0;
    char input[5], **new_id = NULL, **new_pos = NULL, **new_type = NULL, **new_val = NULL, **new_time = NULL, **new_date = NULL;
    if ((*total_counts) == -1)
    {
        printf("Neotvoreny subor.\n");
    }
    else
    {
        scanf(" %s", input);
        for (int i = 0; i < (*total_counts); i++)
        {
            if (strcmp(input, (*id)[i]) != 0)
            {
                //Allocate and realocate
                if (count == 0)
                {
                    new_id = malloc(sizeof(char *) * (count + 1));
                    new_pos = malloc(sizeof(char *) * (count + 1));
                    new_type = malloc(sizeof(char *) * (count + 1));
                    new_val = malloc(sizeof(char *) * (count + 1));
                    new_time = malloc(sizeof(char *) * (count + 1));
                    new_date = malloc(sizeof(char *) * (count + 1));
                }
                else
                {
                    new_id = realloc(new_id, sizeof(char *) * (count + 1));
                    new_pos = realloc(new_pos, sizeof(char *) * (count + 1));
                    new_type = realloc(new_type, sizeof(char *) * (count + 1));
                    new_val = realloc(new_val, sizeof(char *) * (count + 1));
                    new_time = realloc(new_time, sizeof(char *) * (count + 1));
                    new_date = realloc(new_date, sizeof(char *) * (count + 1));
                }
                new_id[count] = malloc(sizeof(char) * 5);
                new_pos[count] = malloc(sizeof(char) * 14);
                new_type[count] = malloc(sizeof(char) * 2);
                new_val[count] = malloc(sizeof(char) * 6);
                new_time[count] = malloc(sizeof(char) * 4);
                new_date[count] = malloc(sizeof(char) * 8);
                strcpy(new_id[count], (*id)[i]);
                strcpy(new_pos[count], (*pos)[i]);
                strcpy(new_type[count], (*type)[i]);
                strcpy(new_val[count], (*val)[i]);
                strcpy(new_time[count], (*time)[i]);
                strcpy(new_date[count], (*date)[i]);
                count++;
            }
        }
        printf("Vymazalo sa : %d zaznamov !\n", (*total_counts) - count);

        dealocate(total_counts, id, pos, type, val, time, date);
        memcpy(*id, new_id, sizeof(char **) * count);
        memcpy(*pos, new_pos, sizeof(char **) * count);
        memcpy(*type, new_type, sizeof(char **) * count);
        memcpy(*val, new_val, sizeof(char **) * count);
        memcpy(*time, new_time, sizeof(char **) * count);
        memcpy(*date, new_date, sizeof(char **) * count);
        (*total_counts) = count;
    }
}

void k(int *total_counts, char ***id, char ***pos, char ***type, char ***val, char ***time, char ***date, FILE **file)
{
    if ((*total_counts) != -1)
    {
        dealocate(total_counts, id, pos, type, val, time, date);
        fclose(*file);
    }
    exit(1);
}

int main(int argc, char const *argv[])
{
    char input, **id = NULL, **position = NULL, **type = NULL, **value = NULL, **time = NULL, **date = NULL;
    int opened = 0, total_counts = -1;
    FILE *file;

    while (1)
    {
        scanf(" %c", &input);
        switch (input)
        {
        case 'v':
            v(&total_counts, &id, &position, &type, &value, &time, &date, &file);
            break;
        case 'n':
            n(&total_counts, &id, &position, &type, &value, &time, &date, &file);
            break;
        case 'c':
            c(&total_counts, &id, &date);
            break;
        case 'h':
            h(&total_counts, &type, &value);
            break;
        case 'z':
            z(&total_counts, &id, &position, &type, &value, &time, &date);
            break;
        case 's':
            s(&total_counts, &id, &position, &type, &value, &time, &date);
            break;
        case 'k':
            k(&total_counts, &id, &position, &type, &value, &time, &date, &file);
            break;
        default:
            continue;
        }
    }

    return 0;
}