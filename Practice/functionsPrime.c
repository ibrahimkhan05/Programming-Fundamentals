#include <stdio.h>

int isEvenNum(int number);
int isEvenNum(int number) {
    int even = 0;
    if (number % 2 == 0) { 
        even = 1;
        
    }
    return even;
}
int main (void) {
    int number;
    printf("Enter a number to check wether it's even or odd: ");
    scanf("%d", &number);
    int isEven = isEvenNum(number);
    if (isEven) {
        printf("Your number %d is even number", number);
    } else {
        printf("Your number %d is not an even number", number);

    }
    return 0;
}