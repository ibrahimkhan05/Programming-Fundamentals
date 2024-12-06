#include <stdio.h>

int main(void) {
    double number = -0.0000000000001;
    long long int test = 21312231123213123123;
    if (number) {
        printf("Yes i am correct \n");
        printf("%-100.100lld", test);
    } else {
        printf("Moye Moye");
    }
    return 0;
} 