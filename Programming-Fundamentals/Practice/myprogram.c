#include <stdio.h>
int main(void) {
    int firstNumber, secondNumber;
    char charcter;
    printf("Enter your first and second number: ");
    scanf("%d%d", &firstNumber, &secondNumber);
    printf("Enter an chracter: ");
    scanf(" %c", &charcter);
    printf("You entered number %#o and %#x and chracter %c", firstNumber, secondNumber, charcter );
    return 0;
}
