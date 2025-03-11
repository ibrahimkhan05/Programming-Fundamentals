#include<stdio.h>

int main(void) {
    int user_pay, tax_percenatge;
    printf("Enter Your pay: ");
    scanf("%d",  &user_pay);
    printf("Enter the tax percenatge: ");
    scanf("%d", &tax_percenatge);
    int percetnage = (tax_percenatge * user_pay) / 100;
    user_pay = user_pay + percetnage;
    printf("Your total amount is %d $", user_pay);
    return 0;
}