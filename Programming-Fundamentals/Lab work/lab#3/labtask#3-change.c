#include <stdio.h>
int main(void){
    int amount, change_1000 = 0, change_500 = 0, change_100 = 0, change_50 = 0, change_20 = 0, change_10 = 0, change_5 = 0, change_1 = 0;
    printf("Enter the amount to convert into change: ");
    scanf("%d", &amount);
    int chnage_left_1000 = amount % 1000;
    change_1000 = amount / 1000;
    //change left after 1000
    int change_left_500 = chnage_left_1000 % 500;
    change_500 = chnage_left_1000 / 500;
    // Change left after 500
    int change_left_100 = change_left_500 % 100;
    change_100 = change_left_500 / 100;
    // Change left after 100
    int change_left_50 = change_left_100 % 50;
    change_50 = change_left_100 / 50;
    // Change left after 50
    int change_left_20 = change_left_50 % 20;
    change_20 = change_left_50 / 20;
    // Change left after 20
    int change_left_10 = change_left_20 % 10;
    change_10 = change_left_20 / 10;
    // Change left after 10
    int change_left_5 = change_left_10 % 5;
    change_5 = change_left_10 / 5;
    // Change left after 1
    int change_left_1 = change_left_5 % 1;
    change_1 = change_left_5 / 1;

    printf("**********Change Machine**********\n");
    printf("Your inserted amount %d\n", amount);
    printf("You will get %d Notes of 1000 Ruppes\n", change_1000);
    printf("You will get %d Notes of 500 Ruppes\n", change_500);
    printf("You will get %d Notes of 100 Ruppes\n", change_100);
    printf("You will get %d Notes of 50 Ruppes\n", change_50);
    printf("You will get %d Notes of 20 Ruppes\n", change_20);
    printf("You will get %d Notes of 10 Ruppes\n", change_10);
    printf("You will get %d coins of 5 Ruppes\n", change_5);
    printf("You will get %d coins of 1 Ruppes\n", change_1);
    return 0;
}