#include <stdio.h>
int main(){
    int number, result;
    printf("Enter 5 digit number to convert into octal number: ");
    scanf("%d", &number);
    int rem1 = number%8;
    number/=8;
    int rem2 = number%8;
    number/=8;
    int rem3 = number%8;
    number/=8;
    int rem4 = number%8;
    number/=8;
    int rem5 = number%8;
    number/=8;
    printf("%d%d%d%d%d", rem5,rem4,rem3,rem2,rem1);
return 0;
}