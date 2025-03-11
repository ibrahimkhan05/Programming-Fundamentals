#include <stdio.h>
int main(void){
    // integers
    int a = 100;
    short int b = 2;
    long int c = 1000;
    long long int d = 10000;
    unsigned int unsigned_int = 34385743;
    //floting point integer
    float e = 3.545f;
    double f = 3.534534;
    long double g = 33.23423434;
    // chracter
    char aa = 'A';
   // Printing chracter
    printf("our chracter is: %c\n", aa);
    //Printing integer
    printf("The value of interger is: %d, its octal value is: %#o and its hexadecimal vlaue is: %#x\n", a, a, a);
    printf("The value of short interger is: %hd, its octal value is: %#ho and its hexadecimal vlaue is: %#hx\n", b, b, b);
    printf("The value of long interger is: %ld, its octal value is: %#lo and its hexadecimal vlaue is: %#lx\n", c, c, c);
    printf("The value of long long interger is: %lld, its octal value is: %#llo and its hexadecimal vlaue is: %#llx\n", d, d, d);
    printf("The value of unasigned interger is: %d, its octal value is: %#o and its hexadecimal vlaue is: %#x\n", unsigned_int, unsigned_int, unsigned_int);
    //Printing floating point value
    printf("The value of floating point integer is: %f\n",e);
    printf("The value of double integer is: %f\n", f);
    printf("The valaue of long double is: %Lg\n\n\n", g);
// reassiging value to integer varible
    a+=10;
    b+=160;
    c+=1230;
    d+=10234;
    unsigned_int-=4;
    // reassiging value to flaoting point variable
    e+=5.6;
    f+=6.564;
    g+=667.45;
    // reassiging value to chracter varibale
    aa = 'C';

    // Printing reassigned integer varibale
    printf("The value of interger is: %d, its octal value is: %#o and its hexadecimal vlaue is: %#x\n", a, a, a);
    printf("The value of short interger is: %hd, its octal value is: %#ho and its hexadecimal vlaue is: %#hx\n", b, b, b);
    printf("The value of long interger is: %ld, its octal value is: %#lo and its hexadecimal vlaue is: %#lx\n", c, c, c);
    printf("The value of long long interger is: %lld, its octal value is: %#llo and its hexadecimal vlaue is: %#llx\n", d, d, d);
    printf("The value of unasigned interger is: %d, its octal value is: %#o and its hexadecimal vlaue is: %#x\n", unsigned_int, unsigned_int, unsigned_int);
    // Printing reassigned floating point varibale
    printf("The value of floating point integer is: %f\n",e);
    printf("The value of double integer is: %f\n", f);
    printf("The valaue of long double is: %Lg\n", g);
    // Printing reassigned chracter varibale
    printf("our chracter is: %c\n", aa);

 return 0;

}