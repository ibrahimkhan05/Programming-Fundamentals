#include <stdio.h>

int main (void) {
    int user_choice, count = 0;
    for (int i = 10; i <= 100; i++){
       if (i % 3 == 0) {
        printf("%d " , i);
        count++;
       }
    }
printf("\nTotal digits that are divisible between 10 and 100 are %d", count);

    return 0;
}