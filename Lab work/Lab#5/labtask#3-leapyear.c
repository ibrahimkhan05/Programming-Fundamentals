#include <stdio.h>

int main (void) {
    int year;
    printf("Enter a year to check wether it's leap year or not: ");
    scanf("%4d", &year);
    if (year % 4 == 0 && year % 100 != 0) {
        printf("Year %d is a leap year", year);
    }
    else if (year % 4 == 0 && year % 400 == 0 ){
       printf("Year %d is a leap year", year);
    }
    else {
        printf("Year %d is not a leap year", year);
    }
    return 0;
}