#include <stdio.h>
 /*
Name: Ibrahim Khan
Reg Num: SP24-BCS-160
 */
int main(void) {
    int user_choice;
    float area;

    //Prompting user
    printf("1. Calculate the Area of a Circle\n2. Calculate the Area of a Rectangle\n3. Calculate the Area of a Triangle\n4. Quit\nEnter your choice (1-4): ");
    scanf("%d", &user_choice);
    switch (user_choice) {
    case 1: {
        float radius;
        float pi = 3.14159;
        do {
            printf("Enter radius of the circle: ");
            scanf("%f", &radius);
        } while (radius < 0);
        area = pi * (radius * radius);
        printf("The area of the circle is %f", area);
        break;
    } case 2: {
        float length, width;
        do {
            printf("Enter the length of the Rectangle: ");
            scanf("%f", &length);
            printf("Enter the width of the Rectangle: ");
            scanf("%f", &width);
        } while (length < 0 || width < 0);
        area = length * width;
        printf("The area of the Rectangle is %f", area);
        break;
    } case 3: {
        float  base, height;
        do {
            printf ("Enter base of the triangle: ");
            scanf("%f", &base);
            printf("Enter the height of the triangle: ");
            scanf("%f", &height);
        } while(base < 0 || height < 0);
        area = (base * height) * .5;
        printf("The area of the triangle is %f", area);
        break;
    } case 4: {
        break;
    } default: {
        printf("Invalid Choice!");
        break;
    }
    }
    return 0;
}