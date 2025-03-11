#include <stdio.h> 

int main (void) {
    int user_number, i;
    printf("Enter your number: ");
    scanf("%d", &user_number);
    for (i = 2; i <= user_number; i++) {
        if ((i % i == 0)) {
            if ((i % 2 != 0 && i % 3 != 0)){
               printf("%d ", i);
            }
            }
            
        }
    

    return 0;
}