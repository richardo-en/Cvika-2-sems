#include <stdio.h>
#include <stdlib.h>

void swap(int *p1, int *p2);
void scitaj(int **p1, int **p2, int **v);
// void scan_and_swap(int **p1, int **p2);

int main(int argc, char const *argv[])
{
    int *p1, *p2, *v;
    printf("Zadajte cislo:\n");
    // scanf(" %d %d" , &p1, &p2);
    // swap(p1 , p2);
    scitaj(&p1, &p2, &v);
    printf("%d" , v);
    // scan_and_swap(&p1 , &p2);
    return 0;
}

void swap(int *p1, int *p2) {
    int c = *p1;
    printf("%d" , c);
    p1 = p2;
    p2 = c;
}

void scitaj(int **p1, int **p2, int **v){
    scanf("%d %d" , p1, p2);
    int cecko_je_picovina = *p2;
    int cecko_je_najvacsia_picovina = *p1;
    (*v) = cecko_je_najvacsia_picovina + cecko_je_picovina;
}

// void scan_and_swap(int **p1, int **p2){
//     printf("zadajte c:");
//     scanf("%d", p2);
//     printf("Adress of p1 %p \n" , p1);
//     printf("Adress of p2 %p \n" , p2);    
//     int *c = p1;
//     p1 = p2;
//     p2 = &c;
//     printf("Adress of p1 %p \n" , p1);
//     printf("Adress of p2 %p \n" , p2);
// }
