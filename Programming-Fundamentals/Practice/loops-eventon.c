#include <stdio.h>

int main(void) {
    int user_number;
    printf("Enter a number: ");
    scanf("%d", &user_number);
    for (int i = 1; i <= user_number; i++) {
        if (i % 2 == 0) {
            printf("%d, ", i);
        }
    }
    return 0;
}