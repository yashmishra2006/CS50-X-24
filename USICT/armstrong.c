#include <stdio.h>
#include <math.h>

int main(void) {
    int num, remainder, sum, digits;

    printf("Armstrong numbers between 1 and 500:\n");

    for (num = 1; num <= 500; num++) {
        sum = 0;
        digits = (num < 100) ? 3 : 3; // Only considering 3-digit numbers for our range

        int temp = num;
        while (temp != 0) {
            remainder = temp % 10;
            sum += pow(remainder, digits);
            temp /= 10;
        }

        if (sum == num) {
            printf("%d\n", num);
        }
    }

    return 0;
}
