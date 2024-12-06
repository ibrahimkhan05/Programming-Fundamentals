#include <stdio.h>


int main (void) {
    long long int power = 1 ;
    for (int i = 1;i <= 30; i++) {
        power = power * 2;
        printf("%lld ", power);
        
    }
    return 0;
}