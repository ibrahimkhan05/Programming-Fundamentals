#include <stdio.h>

int main(void) {
    float monthly_payment, intrest_rate, total_amount;
    float monthly_intrest_amount, monthly_intrest_rate;
    printf("Enter total loan amount: ");
    scanf("%f", &total_amount);
    printf("Enter intrest rate: ");
    scanf("%f", &intrest_rate);
    printf("Enter montly payment: ");
    scanf("%f", &monthly_payment);

    //Calculate monthly intrest rate
    monthly_intrest_rate = (intrest_rate / 100) / 12;

    //First month 
    monthly_intrest_amount = total_amount * monthly_intrest_rate;
    total_amount = total_amount + monthly_intrest_amount;
    total_amount = total_amount - monthly_payment;
    printf("After first payment %f\n", total_amount);

    //Second month
    monthly_intrest_amount = monthly_intrest_rate * total_amount;
    total_amount = total_amount + monthly_intrest_amount;
    total_amount = total_amount - monthly_payment ;
    printf("After second payment %f\n", total_amount);

    //Third month
    monthly_intrest_amount = monthly_intrest_rate * total_amount;
    total_amount = total_amount + monthly_intrest_amount;
    total_amount = total_amount - monthly_payment ;
    printf("After second payment %f\n", total_amount);
    return 0;
}