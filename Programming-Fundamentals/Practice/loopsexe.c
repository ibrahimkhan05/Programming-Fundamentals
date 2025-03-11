#include <stdio.h>

int main (void) {
    int user_number;
    int i;
    printf("Enter to the number to which you want to find all even numbers: ");
    scanf("%d",  &user_number);
    for(i = 0; i <= user_number; i++) {
        if(i % 2 == 0) {
            printf("%d, ", i);
        }
    }

    return 0;
}