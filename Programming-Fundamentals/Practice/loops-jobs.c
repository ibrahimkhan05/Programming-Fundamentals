#include <stdio.h>
int salary = 1, total_salary = 0, total = 0;

int main (void) {
    printf("Month\tSalary\n");
    for (int i = 1; i<= 2*12; i++) {
        salary *= 2;
        total += salary;
        printf("%d\t%d\n", i, salary);

    }
    printf("\n\n\nOn end of 2 years you will get $%d per month and You will recive $%d in 2 years", salary, total);

    return 0;
}