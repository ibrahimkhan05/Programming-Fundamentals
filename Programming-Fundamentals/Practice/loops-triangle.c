#include <stdio.h>

int main (void) {
      for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 15; j++) {
            if (i != 1 && i != 5) {
                if (j == 1 || j == 15) {
                    printf("*");
                     } else {
                        printf(" ");
                     }
            } else {
                printf("*");

            }         
        }
        printf("\n");
      }
      return 0;
}