#include <stdio.h>

int isPrime (int number);
int isPrime (int number) {
    int checker = 1;
    for(int i = 2; i < number; i++) {
        if (number % i == 0) {
            checker = 0;
        }
    } 
    return checker;
}
int main (void) {
    int user_number;
    printf("Enter a number to check weather it's prime or not: ");
    scanf("%d", &user_number);
    int is_prime = isPrime(user_number);
    if(is_prime) {
        printf("Your number %d is a prime number", user_number);
    } else {
        printf("Your number %d is not a prime number", user_number);
    }
    return 0;
}