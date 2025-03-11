#include <stdio.h>

int main (void) {
    for (int i = 200; i >= 2; i--){
        if (i % 20 == 0 && i % 2==0) {
            printf("%d", i);
            printf("\n");
        } else if (i%2==0) {
            printf("%d ", i);
        }
    }
    return 0;
}