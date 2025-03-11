#include <stdio.h>

int main (void) {
    int user_number;
    printf("Enter a number: ");
    scanf("%d", &user_number);
    
    int controller = user_number / 2;
    int second_loop = controller;
    int checker = controller + 1;
    int space = 0; 
    int checker_1 = 1;

    for (int i = user_number; i >= 1; i--) {
        if (i <= checker && space != checker) {
            for (int l = 0; l < space; l++) {
                printf(" ");
            }
            
            for (int k = 1; k <= i; k++) {
                printf("*");
            }
            for (int k = 1; k <= i - 1; k++) {
                printf("*");
            }
            printf("\n");
            space++;

        } 
        // else if (i > checker && second_loop != checker_1) {
        //     for (int m = 1; m <= space; m++) {
        //         printf(" ");
        //     }
        //     for (int l = 1; l <= checker_1; l++) {
        //         printf("*");
        //     }
        //     printf("\n");
        //     space--;
        //     checker_1++;
        // }
    }

    return 0;
}
