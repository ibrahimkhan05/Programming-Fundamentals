#include <stdio.h>
/* SP24-BCS-160
   IBRAHIM Khan
*/
int main(void) {
    int initial_popualtion, arithematic_rate, arithematic_model, average = 0;
    float gometric_rate, gometric_model;
    int year = 0;

    //Prompt to user
    printf("Enter initial population: ");
    scanf("%d", &initial_popualtion);
    printf("Enter Gometric rate: ");
    scanf("%f", &gometric_rate);
    printf("Enter arithematic rate: ");
    scanf("%d", &arithematic_rate);

    //For tracking values
    gometric_model = initial_popualtion;
    arithematic_model = initial_popualtion;

    //Main header for table
    printf("Initial Population: %d\n", initial_popualtion);
    printf("Year\tGeometric\tArithematic\tAverage\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    //Little bit of optmization to corretcly calculate rate %
    if (gometric_rate > 1) {
        gometric_rate = gometric_rate / 100;
        }

    //Will run until average is greater than double of initial population
    do  {
        gometric_model = gometric_model + (gometric_model * gometric_rate);
        arithematic_model = arithematic_model + arithematic_rate;
        average = (gometric_model + arithematic_model) /2; 
        //Tracking year
        year++;
        //Prinmting tbale
        printf("%d\t%.0f\t\t%d\t\t%d\n",year, gometric_model, arithematic_model, average);

        } while (initial_popualtion * 2 > average);

    return 0;
}
