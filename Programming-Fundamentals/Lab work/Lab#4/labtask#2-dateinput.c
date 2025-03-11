#include <stdio.h>
int main() {
    int date=0, month=0, year=0;
    printf("Enter your date in this format mm/dd/yyyy: ");
    scanf("%2d/%2d/%4d",&month,&date,&year);
    printf("You entered date: %.4d%.2d%.2d",year,month,date );
    return 0;
}