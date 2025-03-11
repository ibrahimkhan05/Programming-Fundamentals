#include <stdio.h>

int main (void) {
    int month_1, date_1, year_1, month_2, date_2, year_2;
    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month_1, &date_1, &year_1);
    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month_2, &date_2, &year_2);
    if (date_1 <= 31 && date_2 <= 31 && month_1 <= 12 && month_2 <=12 ){  
    if (year_1 > year_2 ) {   
    printf("%d/%d/%d was earlier then %d/%d/%d", month_2,date_2,year_2, month_1, date_1, year_1);
    }
    else if (year_1 < year_2) {
    printf("%d/%d/%d was earlier then %d/%d/%d", month_1, date_1, year_1, month_2, date_2, year_2);
    } else if (year_1 == year_2){
        if (month_1 > month_2){
            printf("%.2d/%.2d/%.2d was earlier then %d/%d/%d", month_2,date_2,year_2, month_1, date_1, year_1);  
        } else if (month_1 < month_2){
            printf("%.2d/%.2d/%.2d was earlier then %d/%d/%d", month_1,date_1,year_1, month_2, date_2, year_2);
        } else if (month_1 = month_2) {
            if (date_1 > date_2 ) {
                 printf("%.2d/%.2d/%.2d was earlier then %d/%d/%d", month_2,date_2,year_2, month_1, date_1, year_1);
            } else if (date_1 < date_2) {
                 printf("%.2d/%.2d/%.2d was earlier then %d/%d/%d", month_1, date_1, year_1, month_2, date_2, year_2);
            }else if (date_1 == date_2) {
                printf("Both dates are equal ");
            } 
        }
    }
} else {
    printf("Enter valid date");
}
    

    return 0;
}