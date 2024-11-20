/*
Name: Ibrahim khan
Reg number : sp24-bcs-160
*/



#include <stdio.h>
#include <math.h>

int main(void) {
float x_a, x_b, x_c, y_a, y_b,y_c;
printf("Enter the first points: ");
scanf("%f%f", &x_a, &y_a);
printf("Enter the second points: ");
scanf("%f%f", &x_b, &y_b);
printf("Enter the second points: ");
scanf("%f%f", &x_c, &y_c);

float distance_point_ab = sqrt(((x_b - x_a)*(x_b - x_a))+((y_b - y_a)*(y_b - y_a)));
float distance_point_bc = sqrt(((x_c - x_b)*(x_c - x_b))+((y_c - y_b)*(y_c - y_b)));
float distance_point_ac = sqrt(((x_a - x_c)*(x_a - x_c))+((y_a - y_c)*(y_a - y_c)));
// printf("%f, %f, %f", distance_point_ab, distance_point_bc, distance_point_ac);
printf("Distance ab %f\nDistance ac %f\nDistance bc %f\n", distance_point_ab, distance_point_ac, distance_point_bc);

if (distance_point_ab < distance_point_bc && distance_point_ab < distance_point_ac) {
    printf("ab %f is the shortest distance between two points", distance_point_ab);
} else if (distance_point_bc < distance_point_ab && distance_point_bc < distance_point_ac) {
      printf("bc %f is the shortest distance between two points", distance_point_bc); 
} else if ((distance_point_ac < distance_point_ab && distance_point_ac < distance_point_bc)) {
    printf(" ac %f is the shortest distance between two points", distance_point_ac);

}


    

    return 0;
}