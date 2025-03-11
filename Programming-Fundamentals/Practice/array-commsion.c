#include <stdio.h>

int main () {
    int total_employes;
    int user_sales;
    int total_sales;
    
    int salary_taken[5] = {0};

    printf("Enter how many number of employes for which you want to calculate salary: ");
    scanf("%d", &total_employes);
    int salary_calulated;
    for (int i = 1; i <=  total_employes; i++) {
        printf("Enter salary for employe %d: ", i);
        scanf("%d", &user_sales);
        
            total_sales = 200 + (0.09 * user_sales);
            
            if ( total_sales <= 299) {
                salary_taken[0]++;
            } else if (total_sales >= 300 && total_sales <= 399) {
                salary_taken[1]++;
                } else if (total_sales >= 400 && total_sales <= 499) {
                salary_taken[2]++;
                } else if (total_sales >= 500 && total_sales <= 599) {
                salary_taken[3]++;
                } else {
                    salary_taken[4]++;

                }

        
    }
    printf("Total number have emolyes that get paid in follwoing rnages\n200-299\t%d\n300-399\t%d\n400-499\t%d\n200-499\t%d\nAbove-500 %d",salary_taken[0], salary_taken[1], salary_taken[2], salary_taken[3],salary_taken[4] );
    return 0;
}