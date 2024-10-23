#include <stdio.h>

int main(void) {
    char user_input;
    printf("Press a single key: ");
    scanf("%c", &user_input);
    if (user_input >= '0' && user_input <= '9'  ){
        printf("Your input is integer");
    } else if (user_input >= 'A' && user_input <= 'Z' || user_input >= 'a' && user_input <= 'z'){
        if (user_input >= 'A' && user_input <= 'Z'){
            printf("The input is capital letter/Upper case\n");
            if (user_input == 'A' || user_input == 'E' || user_input == 'I' || user_input == 'O' || user_input == 'U'  ){
                printf("Your chracter is vowel"); 
                } else {
                    printf("Your chracter is not vowel");
                }
            }
        } else if (user_input >= 'a' && user_input <= 'z') {
            printf("The input is small letter/lower case");
             if (user_input == 'a' || user_input == 'e' || user_input == 'i' || user_input == 'o' || user_input == 'u'  ){
                printf("Your chracter is vowel"); 
                } else {
                    printf("Your chracter is not vowel");
                }
            }
         else {
        printf("You entered key which is not digit or letter...... So! its symbol");
    }
return 0;
}