#include<stdio.h>

int main (void){
    int number;
    printf("Enter a number to check it's even or odd: ");
    scanf("%d", &number);
    if (number%2==0){
        printf("Your number %d is even number", number);
    } else {
        printf("Your number %d is odd number", number);
    }
    return 0;
}