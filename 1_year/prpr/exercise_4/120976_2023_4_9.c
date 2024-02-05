#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
    int count = 0;
    FILE* ptr;
    char ch;
    ptr = fopen("4_9_text.txt", "r");
    if (NULL == ptr) {
        printf("Subor sa neda otvorit\n");
    }

    do {
        ch = fgetc(ptr);
        switch (ch)
        {
        case 'x':
        case 'X':
            printf("Precital som X\n");
            break;
        case 'y':
        case 'Y':
            printf("Precital som Y\n");
            break;
        case '#':
        case '&':
        case '$':
            printf("Precital som riadiaci znak\n");
            break;
        case ' ':
            count++;
            break;
        case '*':
            printf("Koniec\nPocet precitanych medzier: %d", count);
            fclose(ptr);
            exit(1);
            break;
        default:
            break;
        }
    } while (ch != EOF);

    fclose(ptr);
    printf("Koniec\nPocet precitanych medzier: %d\n", count);
    return 0;
}