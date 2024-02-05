#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rewrite_values(int *year, int *month, int *day, int *mins, char *string)
{
    char yearS[4], monthS[2], dayS[2], hoursS[2], minsS[2];
    for (int a = 0; a < strlen(string); a++)
    {
        if (a <= 3)
        {
            yearS[a] = string[a];
        }
        else if (a <= 5)
        {
            monthS[a - 4] = string[a];
        }
        else if (a <= 7)
        {

            dayS[a - 6] = string[a];
        }
        else if (a <= 9)
        {

            hoursS[a - 8] = string[a];
        }
        else
        {
            minsS[a - 10] = string[a];
        }
    }
    (*year) = atoi(yearS);
    (*month) = atoi(monthS);
    (*day) = atoi(dayS);
    (*mins) = atoi(minsS) + atoi(hoursS) * 60;
}

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

int main(int argc, char const *argv[])
{
    char date[3][13];
    int current_year, current_month, current_day, current_mins, last_index;
    int year, month, day, mins, ordered_indexes[3], total_count = 0;

    for (int i = 0; i < 3; i++)
    {
        ordered_indexes[i] = -1;
    }

    strcpy(date[0], "202310101055");
    strcpy(date[1], "202310081015");
    strcpy(date[2], "202310081025");

    while (total_count != 3)
    {
        for (int i = 0; i < 3; i++)
        {
            if (can_be_rewritten(ordered_indexes, i, 3))
            {
                rewrite_values(&current_year, &current_month, &current_day, &current_mins, date[i]);
                last_index = i;
            }else{
                continue;
            }
            for (int a = 0; a < 3; a++)
            {
                if (i != a && can_be_rewritten(ordered_indexes, a, 3))
                {
                    rewrite_values(&year, &month, &day, &mins, date[a]);
                    if (year < current_year && can_be_rewritten(ordered_indexes, a, 3))
                    {
                        last_index = a;
                    }
                    else if (year == current_year)
                    {
                        if (day < current_day && can_be_rewritten(ordered_indexes, a, 3))
                        {
                            last_index = a;
                        }
                        else if (day == current_day)
                        {
                            if (mins < current_mins && can_be_rewritten(ordered_indexes, a, 3))
                            {
                                last_index = a;
                            }
                            else if (mins == current_mins)
                            {
                                continue;
                            }
                        }
                    }
                    if (last_index != i)
                    {
                        current_year = year;
                        current_month = month;
                        current_day = day;
                        current_mins = mins;
                    }
                }
            }
            ordered_indexes[total_count] = last_index;
            total_count++;
            /* code */
        }
        /* code */
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", date[ordered_indexes[i]]);
    }

    return 0;
}