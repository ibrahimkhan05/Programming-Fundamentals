#include <stdio.h>

int main(void) {
    int rows_1, cols_1, rows_2, cols_2 ;
    printf("Enter Number of rows and columns in matrix 1: ");
    scanf("%d %d", &rows_1, &cols_1);
    printf("Enter Number of rows and columns in matrix 2: ");
    scanf("%d %d", &rows_2, &cols_2);
    int matrix_1[rows_1][cols_1];
    int matrix_2[rows_2][cols_2];
    int resulting_matrix[rows_1][cols_2];
    
if (cols_1 == rows_2) {   
    for(int i = 0; i < rows_1; i++) {
        for(int j = 0; j < cols_1; j++){
            printf("Enter an number to be stored in rows %d and column %d of matrix 1: ", rows_1, cols_1);
            scanf("%d", &matrix_1[i][j]);
        }
    }
    
    for(int i = 0; i < rows_2; i++) {
        for(int j = 0; j < cols_2; j++){
            printf("Enter an number to be stored in rows %d and column %d of matrix 2: ", rows_2, cols_2);
            scanf("%d", &matrix_2[i][j]);
        }
    }
     for (int i = 0; i < rows_1; i++) {
        for (int j = 0; j < cols_2; j++) {
            resulting_matrix[i][j] = 0;
        }
    }
    for(int i = 0; i < rows_1; i++) {
        for(int j = 0; j < cols_2; j++) {
            for(int k = 0; k < cols_1; k++) {
             resulting_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
            }
        }
    }
    for(int i = 0; i < rows_1; i++) {
        for(int j = 0; j < cols_2; j++){
            printf("%d ", resulting_matrix[i][j]);
            
        }
        printf("\n");
    }
} else {
    printf("Number of columns in first row is not equal to number of rows in first columns: ");
}



    return 0;
}