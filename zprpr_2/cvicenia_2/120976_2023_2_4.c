#include <stdio.h>
#include <stdlib.h>

void vypis(float *number_one , float *number_two , float *result , char input , int *lowercase_letters , int *big_letters , int *digits , int *special_characters);
void nacitanie(float *first_number ,float *second_number );
void scitanie(float *first_number ,float *second_number , float *result);
void odcitanie(float *first_number ,float *second_number , float *result);
void nasobenie(float *first_number ,float *second_number , float *result);
void delenie(float *first_number ,float *second_number , float *result);
void praca_so_suborom(int *lowercase_letters_count , int *big_letters_count , int *digits_count , int *special_characters_count);
void zisti(char char_to_find , int *lowercase_letters_count , int *big_letters_count , int *digits_count , int *special_characters_count);

float main()
{
    char input;
    float first_number, second_number, result;
    int lowercase_letters , big_letters , digits , special_characters;
    printf("c - nacitanie cisel\ns - scitanie cisel\no- odcitanie cisel\n\
n - nasobenie cisel\nd - delenie cisel\np - praca so suborom\ne - koniec");
    printf("Input your function:\n");
    
    while (1)
    {
        lowercase_letters = 0, big_letters = 0 , digits = 0 , special_characters = 0; 
        printf("Vyberte si jednu z operacii: s , o , n , d , p , e\n");

        scanf(" %c" , &input);
        if (input == 'c' || input == 's' || input == 'o' || input == 'n' \
        || input == 'd' || input == 'p' || input == 'e')
        {
            vypis(&first_number , &second_number, &result , input , &lowercase_letters , &big_letters , &digits , &special_characters);
        }else{
            printf("Operacia nie je podporovana\n");
        }  
    }
    return 0;
}

void vypis(float *number_one , float *number_two , float *result , char input , int *lowercase_letters , int *big_letters , int *digits , int *special_characters){
     switch (input)
        {
        case 'c':
            nacitanie(number_one , number_two);
            break;
        case 's':
            scitanie(number_one , number_two , result);
            printf("%.2f + %.2f = %.2f\n" , *number_one , *number_two , *result);
            break;
        case 'o':
            odcitanie(number_one , number_two , result);
            printf("%.2f - %.2f = %.2f\n" , *number_one , *number_two , *result);
            break;
        case 'n':
            nasobenie(number_one , number_two , result);
            printf("%.2f * %.2f = %.2f\n" , *number_one , *number_two , *result);
            break;
        case 'd':
            delenie(number_one , number_two , result);
            printf("%.2f / %.2f = %.2f\n" , *number_one , *number_two , *result);
            break;
        case 'p':
            praca_so_suborom(lowercase_letters , big_letters , digits , special_characters);
            printf("Lowercase - %d\nUppercase - %d\nDigits - %d\nSpecial characters - %d\n" , *lowercase_letters , *big_letters , *digits , *special_characters);
        case 'e':
            exit(1);
        default:
            break;
        }
}

void nacitanie(float *number_one , float *number_two){
    printf("Input 2 numbers\n");
    scanf(" %f" , number_one);
    scanf(" %f" , number_two);
}

void scitanie(float *number_one , float *number_two , float *result){
    *result = *number_one + *number_two;
}

void odcitanie(float *number_one , float *number_two , float *result){
    *result = *number_one - *number_two;
}

void nasobenie(float *number_one , float *number_two , float *result){
    *result = (*number_one) * (*number_two);
}

void delenie(float *number_one , float *number_two , float *result){
    *result = (*number_one) / (*number_two);
}

void praca_so_suborom(int *lowercase_letters_count , int *big_letters_count , int *digits_count , int *special_characters_count){
    FILE *subor;
    char ch;

    subor = fopen("vstup.txt", "r");

    if (NULL == subor)
    {
        printf("Subor sa neda otvorit\n");
        exit(1);
    }

    do
    {
        ch = fgetc(subor);
        zisti(ch , lowercase_letters_count , big_letters_count , digits_count , special_characters_count);
    } while (ch != EOF);

    fclose(subor);
}

void zisti(char char_to_find , int *lowercase_letters_count , int *big_letters_count , int *digits_count , int *special_characters_count){

    if (char_to_find > 96 && char_to_find < 123)
    {
        *lowercase_letters_count += 1;
    }else if (char_to_find > 64 && char_to_find < 91)
    {
        *big_letters_count += 1;
    }else if (char_to_find > 47 && char_to_find < 58)
    {
        *digits_count += 1;
    }else if ((char_to_find == ' ') || (char_to_find == '\n') || (char_to_find == '-'))
    {
        *special_characters_count += 1;
    }
}
