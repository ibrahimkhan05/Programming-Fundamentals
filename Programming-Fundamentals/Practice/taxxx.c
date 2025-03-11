#include <stdio.h>

int main(void) {
// Declearing varibales
    float total_income,total_tax, income_after_tax, tax_credit;
    int person_kids;

// Prompting User
    printf("Enter your Income: ");
    scanf("%f", &total_income);

// Checking Their income ranges    
    if (total_income >= 0 && total_income <= 19900) {
        total_tax = (total_income * 10) / 100;
    } else if (total_income >= 19901 && total_income <= 81050) {
        total_tax = 1990 + (0.12 * (total_income - 19900));
    } else if (total_income >= 81051 &&  total_income <= 172750) {
        total_tax = 9328 + (0.22 * (total_income - 81050 ));
    } else if (total_income >= 172751 && total_income <= 329850) {
        total_tax = 29502 + (0.24 * (total_income - 172750));
    } else if (total_income >= 392851 && total_income <= 418850) {
        total_tax = 67206 + (0.32 * (total_income - 329850 ));
    } else if (total_income >= 418851 && total_income <= 628300) {
        total_tax = 95686 + (0.35 * (total_income - 418850 ));
    } else if (total_income > 628310) {
        total_tax = 168933.50 + (0.37 *(total_income - 628300 ));
    }
// TO force to use positive values
// Asking user for number of kids
    do {
    printf("Enter your number of kids: ");
    scanf("%d", &person_kids);

// Their tax deduction according how mnay kids they have
    } while (person_kids < 0);
    if (person_kids == 0) {
        income_after_tax = total_income - total_tax;
        printf("Total income\tTax on income\tIncome after tax\n %.3f\t%.3f\t%.3f", total_income, total_tax, income_after_tax);
    } else {
        tax_credit = person_kids * 2000;
        total_tax = total_tax - tax_credit;
        if (total_tax <=0 ){
            printf("Total income\tNumber of kids\tTotal tax\tIncome after tax\n%.3f\t%d\t\t0\t\t%.3f", total_income, person_kids, total_income);
        } else {
            income_after_tax = total_income - total_tax;
            printf("Total income\tNumber of kids\tTotal tax\tIncome after tax\n%.3f\t%d\t\t%.3f\t%.3f", total_income, person_kids, total_tax, income_after_tax);
        }
    }   
    return 0;
}