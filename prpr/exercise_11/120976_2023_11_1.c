#include <stdio.h>
#include <stdlib.h>

// Debug modes
#define LADENIE_ZAKLADNE 0
#define LADENIE_PODROBNE 1

void check_sum(const char *filename, int debug_mode) {
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        perror("Otvorenie suboru");
        exit(1);
    }

    if (debug_mode == LADENIE_ZAKLADNE || debug_mode == LADENIE_PODROBNE) {
        printf("Otvorenie suboru\n");
    }

    double sum = 0.0;
    double value;

    while (fscanf(file, "%lf", &value) == 1) {
        if (debug_mode == LADENIE_PODROBNE) {
            printf("Sucet: %.2f ", sum);
        }

        sum += value;

        if (debug_mode == LADENIE_PODROBNE) {
            printf("po pridani %.2f\n", value);
        }
    }

    if (debug_mode == LADENIE_ZAKLADNE || debug_mode == LADENIE_PODROBNE) {
        printf("Suma je %s\n", (sum == value) ? "spravna" : "nespravna");
    }

    fclose(file);

    if (debug_mode == LADENIE_PODROBNE) {
        printf("Suma skontrolovana\n");
    }

    if (debug_mode == LADENIE_ZAKLADNE || debug_mode == LADENIE_PODROBNE) {
        printf("Zatvaranie suboru\n");
    }
}

int main() {
    const char *filename = "suma.txt";
    
    check_sum(filename, LADENIE_ZAKLADNE);

    printf("\n");

    check_sum(filename, LADENIE_PODROBNE);

    return 0;
}
