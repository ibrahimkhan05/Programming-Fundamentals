#include <stdio.h>
int main() {
int firstNumber, secondNumber, thirdNumber, fourNumber, fiveNumber, sixNumber, sevenNumber, eightNumber, nineNumber, tenNumber, elevenNumber, checkdigit;
printf("Enter your 11 digit UPC code without check number: ");
scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &firstNumber, &secondNumber, &thirdNumber, &fourNumber, &fiveNumber, &sixNumber, &sevenNumber, &eightNumber, &nineNumber, &tenNumber, &elevenNumber ,&checkdigit);
int sumOne = firstNumber+thirdNumber+fiveNumber+sevenNumber+nineNumber+elevenNumber;
int sumTwo = secondNumber+fourNumber+sixNumber+eightNumber+tenNumber;
int totalSum = sumOne*3+sumTwo;
int subtract = totalSum-1;
int mod = subtract%10;
int final = 9-mod;//
printf("Check digit of UPC code is: %d\n", checkdigit);
printf("The check digit of your calcluted upc code is: %d", final);
return 0;
}