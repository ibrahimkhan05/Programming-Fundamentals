#include <stdio.h>

//This code is for calling a function in a function 
// Our function for sum
int sumFunction(int a, int b);.

//Our function for sqaure root
int sqrtSum(int res, int res_1);

//Sum function defination
int sumFunction(int a, int b) {
  int temp = a + b;
    return temp;
}

//Calling sum function in this square function 
int sqrtSum(int res, int res_1) {
    int sum_res = sumFunction(res, res_1);
    int sqrt = sum_res * sum_res;
    return sqrt;
}

int main(void) {
    int num_1, num_2;
    printf("Enter two numbers: ");
    scanf("%d%d", &num_1, &num_2);
    int res = sqrtSum(num_1, num_2);

    // int result = sumFunction(4,3);
    printf("Result: %d", res);
    return 0;
}