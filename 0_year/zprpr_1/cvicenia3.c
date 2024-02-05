#include <stdio.h>
#include <math.h>
int main() {
    char prve_pismeno;
    char druhe_pismeno;
    printf("dve male pismena\n");
    scanf("%c %c" , &prve_pismeno, &druhe_pismeno);
    prve_pismeno -= 32;
    druhe_pismeno -= 32;
    printf("%c %d \n%c %d" , prve_pismeno , prve_pismeno, druhe_pismeno , druhe_pismeno);


    char first_ch;
    char sec_ch;
    char thrd_ch;
    printf("Zadajte lubovolne pismena");
    scanf("%c %c %c" , &first_ch, &sec_ch , &thrd_ch);
    int list[3] = {first_ch, sec_ch ,thrd_ch};
    int i,a,b,c;
    int output_list[3] = {a, b ,c};
    for(i=0 ; i<3 ; i++)
    {
        if (list[i] > 64 && list[i] < 91 ){
            list[i] +=32;
        }
    	if (i == 0) {
    	    a =  list[i];
    	    c =  list[i];
        } 
        if (list[i] > c){
            c = list[i];
        } else if (list[i] < a){
            a = list[i];
        }
        else{
            b = list[i];
        }
    }
    printf("%c %c %c \n" , a , b , c);

    int cislo , i, druhe_cislo;
    druhe_cislo = cislo;
    int output_num = 1;
    printf("Zadajte cislo");
    scanf("%d" , &cislo);
    for(i=0 ; i<cislo ; i++)
    {
        printf("%d \n" , (cislo -i));
        output_num = output_num *(cislo-i);
    }
    printf("tvoje cislo je %d" , output_num);

    float number;
    printf("zadajte cislo: \n");
    scanf("%f" , number);
    printf("obycajne pretypovanie: %f matematicke pretypovanie", number);
    return 0;
}