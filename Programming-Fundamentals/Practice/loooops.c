#include <stdio.h>

int main (void) {

    int i, user_choice, triangular_number;
    printf("Enter number to find its trinagular number: ");
    scanf("%d", &user_choice);
    for(i=1; i<=user_choice; i++) {
        printf("%d, ",i);
        triangular_number = triangular_number+i;
    }
    printf("\nThe triangular number of number %d is %d", user_choice, triangular_number);

    return 0;
}