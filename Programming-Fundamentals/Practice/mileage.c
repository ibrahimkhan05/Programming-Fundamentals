
#include<stdio.h>
int main(void)
{
int starting_number , ending_number ;
int reimbursement, miles, total_distance , permile_rate;

printf("enter the starting number and ending number of car:\n");
scanf("%d %d",&starting_number, &ending_number);

total_distance = starting_number - ending_number;

printf("the total distance is: %d\n",total_distance);

printf("enter the amount of money you get paid per mile:\n");
scanf("%d", &permile_rate);

reimbursement = total_distance * permile_rate;
printf("the reimbursement is : %d dollars\n", reimbursement);

return 0;
}