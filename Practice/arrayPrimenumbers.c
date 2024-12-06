#include <stdio.h>
#include <math.h>
// We will make an Program that will ask user to give an number and then will gnreate that number of primes Number
// So we will use an function 

// Function prototype
void PrimeNumbers(int n, int prime_number[]);

// Function defination
void PrimeNumbers(int n, int prime_number[]) {

// So we will put first prime number in an array by typing it 
    prime_number[0] = 2;

// To keep track that how many prime number in the array we have 
    int total_primes = 1;

// So we have Enter two which is prime number so we will use next number and that will clauate number of primes ahead next
    int number = 3;

// While loop when number for prime we found quaula to user number we will stop the loop
    while (total_primes < n) {

 //Flag to keep if we found prime number used later in updation
        int isPrime = 1;

 // According to given situation we have to find first number sqaure root and then divide number (number of which we have taken sqaure root) with prime number that is less then that sqrt
        int square_root = sqrt(number);
 
 //So this is main part in this part we will run an foor loop so we will run an loop according to numbers of index filled in an araay
        for (int i = 0; i < total_primes; i++) {
            
// upon an itreation if we found no number less than square root the loop will break
            if (prime_number[i] > square_root) {
                break;

// IF number is divded by any prime numnber less than Square root of that number loop will break by setting flag to zero (false)
            } if (number % prime_number[i] == 0) {
                isPrime = 0;
                break;
            }
// If no prime number less that square root of that number dvodes that number its mean that falg is not set to zero so its prime
        } if (isPrime) {
 
//Then it will store that number in total prime index mwaing we have one prime so its is stored in one index
            prime_number[total_primes] = number;

// This will incarse prime number so we will know how many ptime numbers we have and how many times we can loop in index next time
            total_primes++;
        }
        number++;
    }
}


//Main fuction 
int main() {

//Declareatiom
    int user_number;
    printf("Enter an number to which you want to genreate prime numbers: ");
    scanf("%d", &user_number);
    int primes[user_number];

//function call 
    PrimeNumbers(user_number, primes);

// So weith array when we will give array to fention acutally we are giving array adress to fuction so fucrion will updated real array
// This loop will run that number of times that user want to gnreate prime numbers 
for (int i = 1; i < user_number; i++) {
        printf("%d, ", primes[i]);
    }

    return 0;
}
