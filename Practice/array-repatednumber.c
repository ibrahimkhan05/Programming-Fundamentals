#include <stdio.h>

//In this prgram we check an number and stop the prgram if we found any duplicate number with error message

int main() {
    //I will do this logic if will first number from user and then get last number
    //Then i will declare an array and intlize as zero and then incrase last number from user digits by 1 
    //If user enter 2 two times then vlaue at index 2 will become two

    int checker_duplicate[10] = {0};
    long long int digit;
    int last_digit;
    printf("Enter an number: ");
    scanf("%lld", &digit);
    
    do {
        last_digit = digit % 10;
    checker_duplicate[last_digit]++;
    // So after geeting last number and then using as index and then incresing after 1
    // IF that number index become 2 the loop will break with error message
    // So if its 3 2 3 first three is spreated then vlaue at index 3 will become 1
    // Same caswe with 2 and these vlaues will b e checked by if else if they are greater than one
    // Then when another 3 will come the vlaue at index 3 that is one will become 2 and the codtion will become true
    // So loop will break and then codition in last in cheked so now its clear that if no repated digits loop will run wile digit 
    // become zero if its not loop was breaed due to repated digits and we use condition to tell user
    if (checker_duplicate[last_digit] > 1) {
        // printf("Duplicate Found\n");
        break;
        // return 1;
    }
        digit = digit / 10;
        
        
    } while (digit > 0);
    if (digit) {
        printf("Repated digits");
    } else {
        printf("No repated digits");
    }
    return 0;



}