#include <stdio.h>
#include<stdlib.h>

int main (void) {
    int a = 0;
    
    for (int i = 1; i <= 6; i++) {
        a = rand() % 6;
        printf("%d ",a);

    }
    return 0;
}