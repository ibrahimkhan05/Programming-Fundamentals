#include <stdio.h>
#define SIZE 10
#define SIZE_TABLE 3
int main () {
    double fraction[SIZE] = {0};
    printf("Fourth value: %f\n", fraction[3]);
    fraction[8] = 1.667;
    fraction[6] = 3.333;
    printf("%.2f, %.2f\n", fraction[8], fraction[5]);
    for (int x = 0; x < 10; x++) {
        printf("%f\n", fraction[x]);
        
    }

    //  2D Array
    printf("\n*****************2D ARRAY***************************");

    int array_2d[SIZE_TABLE][SIZE_TABLE];
    printf("\nThe total number of element in 2D-Array is %d\n", SIZE_TABLE*SIZE_TABLE);
    // Priting sums of subscript

    for (int x = 0; x < SIZE_TABLE; x++) {
        for (int y = 0; y < SIZE_TABLE; y++) {  
        int sum = x + y;
        array_2d[x][y] = sum;
        printf("The sum of subscript is %d\n", x + y);
        }
        
    }

    printf("\nElements in array\n");
    for(int j = 0; j < SIZE_TABLE; j++) {
        for (int y = 0; y < SIZE_TABLE; y++) {
            printf("The digit stroed in sub array %d and location %d is: %d
            \n" , j, y, array_2d[j][y]);
         }

    }
    return 0;

    

} 