#include <stdio.h>
 /*
Name: Ibrahim Khan
Reg Num: SP24-BCS-160
 */
int main(void) {
    float inital_balance, monthly_contibution, anual_return, anual_inflation, total_balance, monthly_intrest, calculated_return, total_intrest = 0;
    int years_retirment , i , months, j = 0;

    //Prompting user
    printf("Welcome to your saving account, Please enter your inital despoit: ");
    scanf("%f", &inital_balance);
    printf("Enter your montly contribution: ");
    scanf("%f", &monthly_contibution);
    printf("Enter anual rate of return: ");
    scanf("%f", &anual_return);
    printf("Enter your anual rate of inflation: ");
    scanf("%f", &anual_inflation);
    printf("Enter years until retirment: ");
    scanf("%d", &years_retirment);

    //Checking for flase input and reprompting user to again give value
    if ( inital_balance < 0 || monthly_contibution < 0) {
        if (inital_balance < 0) {
            printf("Error invalid input, You enterned inital deposit in negative or zero\n" );
            printf("Enter your inital desposit amount again: ");
            scanf("%f", &inital_balance);
        } if ( monthly_contibution < 0 ) {
            printf("Error invalid input, You enterned montly contibution in negative or zero\n" );
            printf("Enter your montly contibution  amount again: ");
            scanf("%f", &monthly_contibution);
        }       
    } 
    if ((anual_return < 0 || anual_return > 1) || (anual_inflation < 0 || anual_inflation > 1) ) {
        if ((anual_return < 0 || anual_return > 1)){
            printf("Error invalid input, anual return should be on the scale of (0, 1)\n" );
            printf("Enter your anual return amount again: ");
            scanf("%f", &anual_return);

        } if (anual_inflation < 0 || anual_inflation > 1) {
            printf("Error invalid input, anual inflation should be on the scale of (0, 1)\n" );
            printf("Enter your anual inflation amount again: ");
            scanf("%f", &anual_inflation);
        }
        
    } if (years_retirment < 0) {
            printf("Error invalid input, You enterned years until retirement in negative\n" );
            printf("Enter your years until retirement amount again: ");
            scanf("%d", &years_retirment);
        
    } else {
        months = years_retirment * 12;
    }
    printf("Months\tIntrest\tBalance\n");

    //Using loops to calculate anual intrest
    for (i = 1; i <= months; i++) {
        calculated_return = (1 + anual_return)/ (1 + anual_inflation) - 1;
        monthly_intrest = inital_balance * calculated_return / 12 ;
        inital_balance = inital_balance + monthly_intrest + monthly_contibution;
        total_intrest = total_intrest + monthly_intrest;
        j++;
        printf("%d\t$%.2f\t\t$%.2f\n", j, monthly_intrest, inital_balance);
    }
    printf("Total Intrest Earned: $%.2f\nTotal Nest Egg: $%.2f", total_intrest, inital_balance);  
    return 0;
}