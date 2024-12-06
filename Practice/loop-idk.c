#include <stdio.h>
int space, s =1;

int main(void) {
    space = 4;
for (int i = 1; i <=5; i++) {
    for (int j = 1; j <=space; j++){
        printf(" ");   
    }
    for  (int m = 1; m<=s; m++) {
        printf("*");
    }
    space--;
    printf("\n");
    s++;
}

    return 0;
}