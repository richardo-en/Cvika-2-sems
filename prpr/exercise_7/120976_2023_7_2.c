#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n, *values = NULL, write_value = 'a', line = 0, index = 0, total_count;
    scanf("%d", &n);
    total_count = n*n;
    values = malloc(sizeof(int) * (total_count));
    for (int i = 0; i < total_count+1; i++)
    {
        values[i] = write_value;
        write_value++;
        if (write_value == ('z' +1))
        {
            write_value = 'a';
        }
    }
    total_count = 0;
    while (line != n)
    {
        total_count+=n;
        if (line %2 == 0)
        {
            for (index; index < total_count; index++)
            {
                printf("%c ", values[index]);
            }
            printf("\n");
        }else{
            index += (n-1);
            for (index; index > (total_count-1-n); index--)
            {
                printf("%c ", values[index]);
            }
            printf("\n");
            index += (n+1);

        }
        line++;
    }
    

    return 0;
}