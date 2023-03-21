#include <stdio.h>
void samohlasky(char *input_string);

int main(int argc, char const *argv[])
{
    char input[50];
    scanf("%[^\n]" , input);
    samohlasky(input);
    return 0;
}

void samohlasky(char *input_string){
    int index= 0 , count= 0;
    char vowels[6] = {'a' , 'e' , 'i' , 'o' , 'u' , 'y'};
    while (input_string[index] != '\0')
    {
        for (int i = 0; i < 6; i++)
        {
            if (vowels[i] == input_string[index])
            {   
                count++;
                break;
            }
        }
        index++;
    }
    printf("\n%d" , count);
}