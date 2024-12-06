# include <stdio.h>

int main (void) {
    int adder = 1;
    int number = 10;
    for (int i = 1; i <= 10; i++){
        for (int j = 1; j<= 10; j++) {
            if (j == 10) {
                printf("%d ", number + adder);
            } else {
                printf("%d, ", number + adder);
            number = number+10;

            }
            

            
        }
        adder++;
        printf("\n");
        number = 10;
    }
    return 0;
}