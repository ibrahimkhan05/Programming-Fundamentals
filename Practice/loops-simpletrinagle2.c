#include <stdio.h>

int main (void) {
    int user_choice, track;
    int spaces;
    printf("Enter the number of rows on which  you want to print an inverted triangle: ");
    scanf("%d", &user_choice);
    spaces = user_choice - 1;
    for (int i = 1; i <= user_choice; i++) {
        for (int l = 1; l <= spaces; l++) {
            printf(" ");
        }

        for (int j = 1; j <= i; j++) {
            printf("*");
        }   for (int j = 1; j <= i-1; j++) {
            printf("*");
        } 
        
        printf("\n");
        spaces--;
        }
        for (int i = 1; i <= user_choice; i++) {
            for (int m = 1 ; m < i; m++) {
                printf(" ");
            }
            for (int k = user_choice ; k >= i; k--) {
            printf("*");
        } for (int k = user_choice - 1; k > i-1; k--) {
            printf("*");
        }
        printf("\n");
        }

    return 0;
}