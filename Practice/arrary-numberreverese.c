#include <stdio.h>
// In this code we will reverse the user input like if user  input 12345 we will give out put 54321

int main () {
    //First we will decalre an array

    int reverse[10];

    // Now we will run an loop that will prompt user to input number for then time 
    for (int i = 0; i < 10; i++) {
        printf("Enter the number to store in %d loction in array: ", i);
        scanf("%d", &reverse[i]);
    }
    // So now when we know the array size so we will start array size (You hard core it) -1, so in our case array size is 10 so index is 10 -1 = 9
    for (int i = 9; i >= 0; i--) {
        printf("%d ", reverse[i]);
    }

    return 0;
}