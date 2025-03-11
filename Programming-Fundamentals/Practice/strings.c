#include <stdio.h>
#include <string.h>
int main() {
    char name[30];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Your name is %s \n", name);
    if (strcmp(name, "Ibrahim") == 0){
        printf("Macthed\n");
    }
    printf("%d\n", strcmp(name, "Ibrahim"));
    printf("%d\n", strlen(name));
    char s1[30];
    strcpy(s1, "Ibrahim");
    printf("%s\n", s1);
    strcat(s1, " Khan");
    puts(s1);
    return 0;
}