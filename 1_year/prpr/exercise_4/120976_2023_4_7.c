#include <stdio.h>
#include <stdlib.h>
int main() {
    float num = 0;
    char str[50];
    FILE * f = fopen("cisla.txt", "r");

    if (NULL == f) {
        printf("Neexistuje subor: cisla.txt.\n");
    }

    while (fgets(str, 50, f) != NULL) {
        num += atof(str);
        printf("%s", str);
    }    
    fclose(f);
    printf("Sucet cisel je: %.2f.\n", num);
    return 0;
}