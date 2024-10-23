#include <stdio.h>

int main (void) {
    int guess_number;
    printf("Guess number of drink conusmed: Hint (5 to 30): ");
    scanf("%d", &guess_number);
    if (guess_number == 15) {
        printf("Woaaahh!! Great Job, you nailed it:");
    }
    else if (guess_number>15) {
        printf("Stay low you have chosen larger number:");
    }
    else {
        printf("You have chosen samller than actual number:");
    }
    return 0;
}