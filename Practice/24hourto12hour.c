#include <stdio.h>

int main(void) {
    int user_time_hour, user_time_min, time_12hour;
    printf("Enter your 24 hour time ( 23:11 ): ");
    scanf("%2d:%2d", &user_time_hour, &user_time_min);
    if (user_time_hour > 12 && user_time_hour < 24 ) {
        user_time_hour = user_time_hour % 12;
        printf("12 hour format: %.2d:%.2d PM", user_time_hour, user_time_min);
    } else if (user_time_hour < 12 && user_time_hour != 0){
        printf("12 hour format: %.2d:%.2d AM", user_time_hour, user_time_min);
    } else if (user_time_hour == 12) {
        printf("12 hour format: %.2d:%.2d PM", user_time_hour, user_time_min);
    } else if (user_time_hour == 00) {
        printf("12 hour format: 12:%.2d AM", user_time_hour, user_time_min);
        } else {
        printf("Invaild value");
    }

    return 0;
}