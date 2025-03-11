// Program to tell how many vowels letter are in your name
#include <stdio.h>

int main (void) {

//Initilizer to set all array vlaue to zero
int counter[5] = {0};
char name;
printf("Enter your name: ");
// Here we will put our whole name on input stream so loop will run each time picking chracter from input stream and stop when it recive \n


// Do while loop which stops when name will read \n on Input stream
do {
    scanf("%c", &name);

// Loop will run reading each chracter at on time from input stream and then compare it if it found any vowel than counter will inreacse by one
    if (name == 'a' || name == 'A'){
        counter[0]++;
    } else if (name == 'e' || name == 'E'){
        counter[1]++;
    } else if (name == 'i' || name == 'I'){
        counter[2]++;
    } else if (name == 'o' || name == 'O'){
        counter[3]++;
    } else if (name == 'u' || name == 'U'){
        counter[4]++;
    } 
} while (name != '\n');

// Final printing the result of vowels latter find in names
printf("In your name\nA/a %d\nE/e %d\nI/i %d\nO/o %d\nU/u %d\n" , counter[0], counter[1], counter[2], counter[3], counter[4]);
return 0;
 }