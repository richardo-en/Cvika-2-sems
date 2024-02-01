#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int spaces = 0;
    FILE *subor;
    char ch, special_characters[7] = {'$', '#', '&', 'x', 'X', 'y', 'Y'};

    subor = fopen("text.txt", "r");

    if (NULL == subor)
    {
        printf("File cant be open\n");
        return 0;
    }

    do
    {
        ch = fgetc(subor);
        for (int i = 0; i < 7; i++)
        {
            if ((ch == special_characters[i]) && (i <= 2))
            {
                printf("Precital som riadiaci znak\n");
            }
            else if ((ch == special_characters[i]) && (i == 3 || i == 4))
            {
                printf("Precital som X\n");
            }
            else if ((ch == special_characters[i]) && (i == 5 || i == 6))
            {
                printf("Precital som Y\n");
            }
            else if (ch == 32)
            {
                ++spaces;
            }
            else if (ch == '*')
            {
                printf("Koniec\nPocet precitanych medzier: %d", spaces);
                return 0;
            }
            else
            {
                continue;
            }
            break;
        }

    } while (ch != EOF);

    fclose(subor);
    return 0;
}
