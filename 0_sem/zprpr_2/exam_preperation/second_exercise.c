#include <stdio.h>
#include <stdlib.h>

char* last_point(char* s, char c) {
    char* last_pos = NULL;

    while (*s != '\0') {
        if (*s == c)
            last_pos = s;
        s++;
    }

    return last_pos;
}

int main() {
    char sentence[100];
    char ch;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    printf("Enter a character to search: ");
    scanf(" %c", &ch);

    char* result = last_point(sentence, ch);

    if (result != NULL)
        printf("Last position of '%c' in '%s' is %ld\n", ch, sentence, result - sentence);
    else
        printf("Character '%c' not found in '%s'\n", ch, sentence);

    return 0;
}
