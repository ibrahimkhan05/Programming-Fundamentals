#include <stdio.h>
 /*
Name: Ibrahim Khan
Reg Num: SP24-BCS-160
 */
int number = 0, spacce = 4;

int main(void) {
    for (int i = 1; i <= 4; i++) {
        for (int k = 1; k <= spacce; k++) {
            printf(" ");
        }
        spacce--;
        for (int j = 1; j <= i; j++) {
            number++;
            printf("%d", number);
        }
        // reprater = number;
        --i;

        for (int l = 1; l <= i; l++) {
            number = number - 1;
            if (number != 0)
            {
                printf("%d", number);
            }
        }
        // if (number != 1 ){
        //     number--;
        // } else
        printf("\n");
        i++;
    }

    return 0;
}