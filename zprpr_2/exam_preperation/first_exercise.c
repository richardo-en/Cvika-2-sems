#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int digit_sum(int number){
    int result = 0;
    char str[20];
    sprintf(str, "%d", number);
    for (int i = 0; i < strlen(str); i++)
    {
        char tempStr[2];
        tempStr[0] = str[i];
        tempStr[1] = '\0';
        result += atoi(tempStr);
    }
    return result;
};

int main(){
    int input_number, result_number;
    scanf("%d" , &input_number);
    result_number = digit_sum(input_number);
    printf("\nDigit sum is %d" , result_number);
}


// #include <stdio.h>

// #define CONVERT_TO_UPPERCASE(c) (((c) >= 'a' && (c) <= 'z') ? ((c) - 32) : (c))

// int main() {
//     char lowercase = 'a';
//     char uppercase = CONVERT_TO_UPPERCASE(lowercase);
//     printf("Uppercase: %c\n", uppercase);
//     return 0;
// }
