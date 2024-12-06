#include <stdio.h>
int main(){
    int number;
    printf("Enter a number to covert to ocatl number: ");
    scanf("%5d", &number);
    int rem1 = number%8;
    number/=8;
    // int sum = rem1+(number*8);
    int rem2 = number%8;
    number/=8;
    int rem3 = number%8;
    number/=8;
    int rem4 = number%8;
    number/=8;
    int rem5 = number%8;
    number/=8;
    printf("%d%d%d%d%d%d", rem5,rem4,rem3,rem2,rem1);
    // printf("%d %d %d", rem1, number, sum);
    return 0;
}
