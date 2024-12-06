#include <stdio.h>

int main(void) {
    int i, j, number;
    printf("Enter a number to get its reverse: ");
    scanf("%d", number);
    i = number;
    j = 1;
    while (i>=1) {
        int reverse = number % 10;
        number = number/10;
        printf("%d", reverse );
    }
    return 0;
}

