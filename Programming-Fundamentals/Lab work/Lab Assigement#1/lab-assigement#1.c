#include <stdio.h>

int main(void) { 
    double managar_pay, hourly_wage, onepiece_worker, weekly_sales, weekly_pay_hourly_wage, weekly_pay_commsion, weekly_pay_mangar, weekly_pay_onepiece;
    int hours_worked, iteams_produced, choice, extra_hour;
    double total_mamager_pay = 0, total_hourly_pay = 0, total_commission_pay = 0, total_onepiece_pay = 0, gross_total;

    do {
        printf("\n\nEnter your Employee paycode\n1 For Manager\n2 for Hourly Worker\n3 For Commison Worker\n4 For Piece worker\n-1 to exit\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1: {
            printf("Enter your fixed weekly salary: ");
            scanf("%lf", &managar_pay);
            total_mamager_pay = total_mamager_pay + managar_pay;
            printf("Employee weekly pay is $%.2lf\n", managar_pay);
            break;
        } case 2: {
            printf("Enter your hourly wage: ");
            scanf("%lf", &hourly_wage);
            printf("Enter numbers of hours you worked: ");
            scanf("%d", &hours_worked);
            if (hours_worked > 40) {
                extra_hour = hours_worked - 40;
                weekly_pay_hourly_wage = (hourly_wage * 40) + (extra_hour * (hourly_wage * 1.5));
                total_hourly_pay = total_hourly_pay + weekly_pay_hourly_wage;
                printf("Employee weekly pay is $%.2lf\n", weekly_pay_hourly_wage);
            } else {
                weekly_pay_hourly_wage = hours_worked * hourly_wage;
                total_hourly_pay = total_hourly_pay + weekly_pay_hourly_wage;
                printf("Employee weekly pay is $%.2lf\n", weekly_pay_hourly_wage);
            }
            break;
        } case 3: {
            printf("Enter your gross weekly sales: ");
            scanf("%lf", &weekly_sales);
            weekly_pay_commsion = 250 + (weekly_sales * 0.057f);
            total_commission_pay = total_commission_pay + weekly_pay_commsion;
            printf("Employe weekly pay is $%.2lf \n", weekly_pay_commsion);
            break;
        } case 4: {
            printf("Enter number of iteams produced: ");
            scanf("%d", &iteams_produced);
            printf("Enter price per item: ");
            scanf("%lf", &onepiece_worker);
            weekly_pay_onepiece = onepiece_worker * iteams_produced;
            total_onepiece_pay = total_onepiece_pay + weekly_pay_onepiece;
            printf("Employe weekly salary $%.2lf", weekly_pay_onepiece);
       }
      }
    } while (choice != -1);
    gross_total = total_mamager_pay + total_hourly_pay + total_commission_pay + total_onepiece_pay;

    printf("\n\n***************Summary of payments***************\nTotal paid to managers $%.2lf\nTotal paid to Hourly workers $%.2lf\nTotal paid to Commission workers $%.2lf\nTotal paid to Piece workers $%.2lf\nTotal Salary paid/Gross total $%.2lf", total_mamager_pay, total_hourly_pay, total_commission_pay, total_onepiece_pay, gross_total);

    return 0;
}