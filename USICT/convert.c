#include <stdio.h>

void printBinary(int n) {
    if (n > 1) {
        printBinary(n >> 1); // Recursive call for the higher bits
    }
    printf("%d", n & 1); // Print the last bit
}

int main() {
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // Print the conversions
    printf("Decimal: %d\n", decimal);
    printf("Hexadecimal: %X\n", decimal); // %X for uppercase hexadecimal
    printf("Octal: %o\n", decimal);       // %o for octal

    printf("Binary: ");
    printBinary(decimal);
    printf("\n");

    return 0;
}
