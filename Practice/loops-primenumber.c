#include <stdio.h>

int main (void) {
    int isPrime = 1;
    int total;
    int user_number;
    printf("Enter an number: ");
    scanf("%d", &user_number);
    for (int i = 2; i < user_number; i++) {
        total = user_number % i;
        if (total == 0) {
            isPrime = 0;
        } else if (total){
            isPrime = 1;
        }


    }
    if (isPrime) {
        printf("Number is prime");
    } else { 
        printf("Numver is not prime");
    }
    
    return 0;
}