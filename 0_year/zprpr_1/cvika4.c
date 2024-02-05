#include <stdio.h>
#include <math.h>

int main(){
    first_exercise();
    second_exercise();
    thrd_exercise();
    fourth_exercise();
    fifth_exercise();
}

void first_exercise(){
    int cislo,i,x;
    float medzivypocet;
    printf("zadajte neparne cislo\n");
    scanf("%d" , &cislo);
    if((cislo%2) == 0){
        return first_exercise();
    }
    medzivypocet = (cislo/2.0);
    for(i=0 ; i<cislo ; i++){
        if (i == ((int)medzivypocet)){
            for(x=0 ; x<cislo ; x++){
                printf("*");
            }
            printf("\n");
        }else{
            for(x=0 ; x<cislo ; x++){
                if (x == ((int)medzivypocet)){
                    printf("*");
                }
                else{
                    printf(" ");
                }
            }
            printf("\n");
        };
    };
}

void second_exercise(){
    int vyska,sirka,i,x,velke_p = 65;
    float medzivypocet;
    printf("zadajte neparne cislo sirky a rozne cislo vysky\n");
    scanf("%d %d" , &sirka ,&vyska);
    if((sirka%2) == 0){
        while ((sirka%2) == 0)
        {
            printf("Zadajte nove cislo sirky. Cislo musi byt neparne\n");
            scanf("%d" , &sirka);
        }
    }
    if(vyska <0){
        vyska *= -1;
    }
    medzivypocet = (sirka/2.0);
    for(i = 1; i < vyska+1; i++){
        int nejake_cislo , z;
        if (i==1){
            for(x=0; x<sirka ; x++){
                    if (x == ((int)medzivypocet)){
                        printf("%d" , i);
                    }
                    else{
                        printf("*");
                    }
            }
            nejake_cislo = 3;
        }else if(i < 10){
            int controll_num = ((sirka - (nejake_cislo +2)) /2);
            for(x=0; x<sirka ; x++){
                if ((sirka - nejake_cislo) +2 >= 0){
                    if (x <= ((sirka - (nejake_cislo +2)) /2)){
                        printf("*");

                    }else if(x >= (controll_num+ nejake_cislo + 1)){
                        printf("*");
                    }
                    else{
                        printf("%d" , i);
                    }
                }
            } 
        }else if(i > 9){
            for (x=0; x<sirka; x++){
                printf("%c" , velke_p);
            }

            velke_p++;
        }
        if(i != 1){
            nejake_cislo += 2;
        }
        printf("\n");
    }
}

void thrd_exercise(){
    FILE* text;
    text = fopen("vstup.txt", "r");
    char ch;
    int a = 0 , e = 0 , i = 0 , o = 0 , u = 0;

    do {
        ch = fgetc(text);
        if(ch == 'a'){
            a++;
        }else if(ch == 'e'){
            e++;
        }else if(ch == 'i'){
            i++;
        }else if(ch == 'o'){
            o++;
        }else if(ch == 'u'){
            u++;
        }
    } while (ch != EOF);
    fclose(text);
    printf("a - %d krat\n e - %d krat\n i - %d krat\n o - %d krat\n u - %d krat" , a , e , i , o , u);
    return 0;
}

void fourth_exercise(){
    FILE* text;
    FILE* vystup;
    text = fopen("vstup.txt", "r");
    vystup = fopen("vystup.txt" , "w+");
    int num = 1;
    char line[256];
    if(text != NULL){
        while (!feof(text))
        {
            if((num%2) == 0){
                fgets(line, 256 ,text);
                fprintf(vystup , line);
            }
            else{
                fgets(line, 256 ,text);
            }
            num++;
        }
    }else{
        printf("subor vstup.txt neexistuje");
    }    
}

void fifth_exercise(){
    
}