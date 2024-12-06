#include <stdio.h>

int main(void) {
    float number;
    int exponent = 0;

    printf("Enter your number: ");
    scanf("%f", &number);

    if (number >= 10) {
        // For numbers >= 10, divide until number is less than 10
        while (number >= 10) {
            number /= 10;
            exponent++;
        }
    } else if (number > 0 && number < 1) {
        // For numbers between 0 and 1, multiply until number is at least 1
        while (number < 1) {
            number *= 10;
            exponent--;
        }
    }

    printf("%f x 10^%d\n", number, exponent);

    return 0;
}
