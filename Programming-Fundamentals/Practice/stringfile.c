#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *my_file = "Strings.txt";
    FILE *fp = fopen(my_file, "w");
    char my_name[20];
    char my_name_read[20];
    puts("Enter your name");
    gets(my_name);
    fputs(my_name, fp);
    fclose(fp);
    fp = fopen(my_file, "r");
    fgets(my_name_read, 20, fp);
    printf("Your name is: ");
    puts(my_name_read);
    fclose(fp);
    return 0;
    
}