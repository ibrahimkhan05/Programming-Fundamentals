#include <stdio.h>

int main(void) {
    int user_choice;
    int spaces;

    printf("Enter a number: ");
    scanf("%d", &user_choice);

    spaces = user_choice - 1;

    // Upper part of the diamond
    for (int i = 1; i <= user_choice; i++) {
        for (int j = 1; j <= spaces; j++) {
            printf(" ");
        }
        for (int k = 1; k <= i; k++) {
            printf("*");
        }
        for (int j = 1; j <= i - 1; j++) {
            printf("*");
        }
        printf("\n");
        spaces--;
    }

    // Reset spaces for the lower part of the diamond
    spaces = 0;

    // Lower part of the diamond
    for (int i = user_choice ; i > 0; i--) {
        for (int j = 1; j <= spaces; j++) {
            printf(" ");
        }
        for (int k = 1; k <= i; k++) {
            printf("*");
        }
        for (int l = 1; l < i ; l++) {
            printf("*");
        }
        printf("\n");
        spaces++;
    }



    printf("*************************************************************\n\n\n\n\n");

spaces = 0;
    for  ( int i = user_choice; i >= 1; i--) {
        for (int k = 0; k < spaces; k++) {
          printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
         for (int l = 1; l < i ; l++) {
            printf("*");
        }
        printf("\n");
        spaces++;
    }
      spaces = user_choice - 1;

    // Upper part of the diamond
    for (int i = 1; i <= user_choice; i++) {
        for (int j = 1; j <= spaces; j++) {
            printf(" ");
        }
        for (int k = 0; k < i; k++) {
            printf("*");
        }
        for (int j = 1; j <= i - 1; j++) {
            printf("*");
        }
        printf("\n");
        spaces--;
    }
    

    return 0;
}
