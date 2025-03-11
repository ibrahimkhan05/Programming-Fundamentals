#include <stdio.h>
void addationUsingPointers(int *number_1, int *number_2, int *result);
void arrayContentAdditationUsingPointers(int *arr, int size, int *result);
void arrayContentAdditationUsingPointers(int *arr, int size, int *result) {
    for (int i = 0; i < size; i++) {
       *result +=  *(arr++);
    }
}
void addationUsingPointers(int *number_1, int *number_2, int *result) {
    *result = *number_1 + *number_2;
}

int main(void) {

    int value_1, value_2;
    puts("Enter two number for addation");
    scanf("%d%d",&value_1, &value_2);
    int result;
    addationUsingPointers(&value_1, &value_2, &result);
    printf("The result of your addation is : %d\n", result);
    int integer_array[] = {1, 2, 3, 4, 5};
    result = 0;
    arrayContentAdditationUsingPointers(integer_array, 5, &result); 
    printf("The result of your addation is : %d", result);
    return 0;

}