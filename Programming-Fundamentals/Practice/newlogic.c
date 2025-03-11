#include <stdio.h>

int main() {
    int user_choice = 10; // Total rows (odd number for symmetry)
    int space = 0;       // Initial spaces

    for (int i = 1; i <= user_choice; i++) {
        // Print leading spaces
        for (int l = 1; l <= space; l++) {
            printf(" ");
        }

        // Print stars
        for (int l = 1; l <= (user_choice - 2 * space); l++) {
            printf("*");
        }

        printf("\n");

        // Adjust spaces and stars based on the row
        if (i < (user_choice) / 2) {
            // Top half: increase spaces
            space++;
        } else {
            // Bottom half: decrease spaces
            space--;
        }
    }

    return 0;
}
