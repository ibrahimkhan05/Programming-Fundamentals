#include <stdio.h> 

int main (void) {
    // int user_limit;
    // printf("Enter your upper limit");
    // scanf("%d", &user_limit);
    // int i;
    // for (i = 1; i < user_limit; i++) {
    //     int sqt = i * i;
    //     printf("%d%d",i ,sqt);
    // }
    int user_choice, last_digit;
    int i = 1;
    printf("Enter Your number: ");
    scanf("%d", &user_choice);
    while (0 >= last_digit) {
        last_digit = user_choice/10;
        i++;
    }
    printf("%d", i);
    return 0;
}
    