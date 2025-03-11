#include <stdio.h> 
 /*
Name: Ibrahim Khan
Reg Num: SP24-BCS-160
 */
int main (void) {
    int user_choice, digits_drop, digit_last, reverse_digits = 0 , last_digit, j;
    int i = 0;
    

    //Prompt to user
    printf("Enter Your number: ");
    scanf("%d", &user_choice);

    //Check how many digits user have entered
    digits_drop = user_choice;
    do {
         digits_drop = digits_drop/10;
         i++;
    } while (digits_drop > 0);

    // Reversing order
    for (j = 1; j <= i; j++){
        digit_last = user_choice % 10;
        reverse_digits = (reverse_digits * 10) + digit_last;
        user_choice/=10;
    }

    // Geting last digit of reversed number and priting corssponding digit in english words
    for (j = 1; j <= i; j++){ 
        last_digit = reverse_digits % 10;
        reverse_digits/=10;
        switch(last_digit) {
              case 0: { 
                printf("Zero ");
                break;
            } case 1: {
                printf("One "); 
                break;
            } case 2: {
                printf("Two ");
                break;
            } case 3: {
                printf("Three ");
                break;
            } case 4: {
                printf("Four ");
                break;
            } case 5: {
                printf("Five ");
                break;
            } case 6: {
                printf("Six ");
                break;
            } case 7: {
                printf("Seven ");
                break;
            } case 8: {
                printf("Eight ");
                break;
            } case 9: {
                printf("Nine ");
                break;
            }
            default: {
                printf("Please enter integers! ");
            } 
        }
    }
    return 0;
}
    