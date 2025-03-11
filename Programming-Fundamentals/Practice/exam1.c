#include <stdio.h> 

void messageFilter(char message[]);
void occuranceChecker(int number);
void occuranceChecker(int number) {
     int ouccrenace_array[10] = {0};
     int current_digit;
     while (number != 0) {
        current_digit = number % 10;
        ouccrenace_array[current_digit]++;
        number = number / 10;
     }
    printf("0: %d\n1: %d\n2: %d\n3: %d\n4: %d\n5: %d\n6: %d\n7: %d\n8: %d\n9: %d\n", ouccrenace_array[0],ouccrenace_array[1],ouccrenace_array[2],ouccrenace_array[3],ouccrenace_array[4],ouccrenace_array[5],ouccrenace_array[6],ouccrenace_array[7],ouccrenace_array[8],ouccrenace_array[9]);
}

void messageFilter(char message[]) {
    int index = 0;
    int isFound = 1;
    char current_letter;
    while (message[index] != '\0') {
        
        current_letter = message[index];
        if (current_letter == 'A' ||current_letter == 'a') {
            current_letter = '4';
            printf("%c", current_letter);
        } else if (current_letter == 'B' ||current_letter == 'b') {
            current_letter = '8';
            printf("%c", current_letter);
        } else if (current_letter == 'E' ||current_letter == 'e') {
            current_letter = '3';
            printf("%c", current_letter);
        } else if (current_letter == 'I' ||current_letter == 'i') {
            current_letter = '1';
            printf("%c", current_letter);
        } else if (current_letter == 'O' ||current_letter == 'O') {
            current_letter = '0';
            printf("%c", current_letter);
        } else if (current_letter == 'S' ||current_letter == 'S') {
            current_letter = '5';
            printf("%c", current_letter);
        } else if (current_letter >= 'a' && current_letter <= 'z') {
            current_letter = current_letter - 32;
            printf("%c", current_letter);
        } else {
            printf("%c", current_letter);
        }
        index++;
        isFound = 0;
        
    }
    if (!isFound) {
        for(int i = 0; i < 10; i++){
            printf("!");
        }
    }

}
int main() {
    // char message[50];
    // puts("Enter your message: ");
    // gets(message);
    // messageFilter(message);
    // int number;
    // printf("Enter a number: \n");
    // scanf("%d", &number);
    // occuranceChecker(number);
    
    
    
}