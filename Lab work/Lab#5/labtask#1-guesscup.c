#include <stdio.h>

int main (void) {
    int guess_number;
    int hidden_number = 15;
    printf("Guess number of cups of tea consumed: Hint (5 to 30): ");
    scanf("%d", &guess_number);
    if (guess_number == hidden_number) {
        printf("Woaaahh!! Great Job, you guessed it:");
    }
    else if (guess_number>hidden_number) {
        printf("Stay low you have guessed larger number:");
    }
    else {
        printf("You have guessed samller than actual number:");
    }
    return 0;
}