#include <stdio.h>
int main (void)
{
int a = 100;
int b = 2;
int c = 25;
int d = 4;
int result;
result = a - b; // subtraction
printf ("a - b = %d\n", result);
result = b * c; // multiplication
printf ("b * c = %d\n", result);
result = a / c; // division
printf ("a / c = %d\n", result);
result = a + b * c; // precedence
printf ("a + b * c = %d\n", result);
printf ("a * b + c * d = %d\n", a * b + c * d);
return 0;
}