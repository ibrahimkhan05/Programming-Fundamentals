#include <stdio.h>

int main(void) {
    float v, r;
    printf("Enter radius of the sphere: ");
    scanf("%f", &r);
    v = (4/3)*3.141598*(r*r*r);
    printf("The volume of sphere is %f", v);
    return 0;
}