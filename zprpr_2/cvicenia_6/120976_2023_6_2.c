#include <stdio.h>
void dlzka(char *input_string);

int main(int argc, char const *argv[])
{
    char input[50];
    scanf("%[^\n]" , input);
    dlzka(input);
    return 0;
}

void dlzka(char *input_string){
    int count = 0, index = 0, max_count = 0;
    while (1)
    {
        if (input_string[index] == '\0')
        {
            printf("%d\n" , count);
            if (count > max_count)
            {
                max_count = count;
            }    
            break;
        }else if (input_string[index] != ' ')
        {
            count++;
        }else{
            printf("%d " , count);
            if (count > max_count)
            {
                max_count = count;
            }
            count=0;
        }
        index++;
    }
    printf("Najdlhsie slovo ma %d znakov" , max_count);   
}