#include <stdio.h>

int main (void) {
    int user_choice;
    int spaces;
    printf("Enter the number of times you want to print an triangle: ");
    scanf("%d", &user_choice);
    spaces = user_choice - 1;
    for (int i = 1; i <= user_choice; i++) {
        for (int j = 1; j <= spaces; j++) {
            printf(" ");
            
        } 
        for (int k = 1; k <= i; k++) {
            printf("*");
        }
        for (int l = 1; l <= i-1; l++) {
            printf("*");
        }
        printf("\n");
        spaces--;
    }

    return 0;
}