#include<stdio.h>
int main(){
    int sum=2;
    sum+2;
    printf("%d\n", sum);
    int number = 5;
    number++;
    printf("%d\n", number);
    number=5;
    ++number;
    printf("%d\n", number);
    int i=1 ,j = 1 ,k =1;
    i+=j +=k;
    printf("%d %d %d", i,j, k);
    return 0;
}