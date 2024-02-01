#include <stdio.h>

unsigned int invert(unsigned int x, int i, int n) {
    // Create a bitmask with 1s in the positions to be inverted
    unsigned int mask = (1u << n) - 1;

    // Shift the mask to the desired position
    mask <<= i;

    // Invert the bits using XOR
    return x ^ mask;
}

int main() {
    unsigned int x, result;
    int i, n;

    // Read input
    printf("Enter the number, position, and number of bits to invert: ");
    scanf("%u %d %d", &x, &i, &n);

    // Call the invert function
    result = invert(x, i, n);

    // Print the result
    printf("x: %u\n", x);
    printf("Inverted x: %u\n", result);

    return 0;
}
