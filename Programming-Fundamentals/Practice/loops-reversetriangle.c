#include <stdio.h>

int main (void) {
    int user_choice;
    int spaces;
    printf("Enter the number of rows for the diamond pattern: ");
    scanf("%d", &user_choice);
    spaces = user_choice - 1;

    // Top half of the diamond
    for (int i = 1; i <= user_choice; i++) {
        for (int l = 1; l <= spaces; l++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("*");
        }   
        for (int j = 1; j <= i - 1; j++) {
            printf("*");
        }
        printf("\n");
        spaces--;
    }

    // Reset spaces for bottom half
    
spaces = 1;
    // Bottom half of the diamond
    for (int i = 1; i <= user_choice ; i++) {
        for (int m = 1; m < spaces; m++) {
            printf(" ");
        }
        for (int k = user_choice ; k >= i; k--) {
            printf("*");
        } 
        for (int a = user_choice ; a >= i-1; a--) {
            printf("*");
        }
        printf("\n");
        spaces++;
    }

    return 0;
}
