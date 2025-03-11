#include <stdio.h>

int main(void) {
    int number;
    printf("Enter a two digit number: ");
    scanf("%3d", &number);
    // using arathematic opreaters
    int reverse = number % 10;
    number /= 10;
    int reverse2 = number % 10;
    int reverse3 = number / 10;
    printf("%d%d%d\n", reverse, reverse2, reverse3);
    // Without arathematic opreaters
    int number_1, number_2, number_3;
    printf("Enter a two digit number: ");
    scanf("%1d%1d%1d", &number_1, &number_2, &number_3);
    printf("%d%d%d", number_3, number_2, number_1);
    return 0;
}