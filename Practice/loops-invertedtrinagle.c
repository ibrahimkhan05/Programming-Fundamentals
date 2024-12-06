#include <stdio.h>

int main (void) {
    int user_choice, track;
    int spaces;
    printf("Enter the number of rows on which  you want to print an inverted triangle: ");
    scanf("%d", &user_choice);
    for (int i = 1; i <= user_choice; i++) {
       
        for (int k = 1; k <= i; k++) {
            printf("*");
            track = k;
        }
       printf("\n");
        }
        
       
    
    for (int i = 1; i <= user_choice; i++) {
        for(int j = user_choice; j >= i; j--){
            printf("*");
        }
        
        printf("\n");
    }
    

    return 0;
}