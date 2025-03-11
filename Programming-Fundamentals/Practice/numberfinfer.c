#include <stdio.h>

int main(void) {
    int user_number;
    //Prompt user and taking input
    printf("Enter your number: ");
    scanf("%d", &user_number);
    if (user_number >= 0 && user_number <= 9) {
        printf("1 Digit");
    } else if (user_number > 9 && user_number < 100) {
        printf("2 Digits");
    } else if (user_number >= 100 && user_number < 1000) {
        printf("3 digits");
    } else {
        printf("Undefinied baheviour");
    }
    return 0;
    
}