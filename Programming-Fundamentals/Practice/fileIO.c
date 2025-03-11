#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char name[] = {'I', 'b', 'r', 'a', 'h', 'i', 'm'};
    char *file_name = "kc.txt";
    FILE *fp = fopen(file_name, "w");
    
    if (fp == NULL) {
        fprintf(stderr, "Could not open file\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 7; i++) {  
        putc(name[i], fp);       
    }
    fclose(fp);  
 fp = fopen(file_name, "r");    // Now we will just get content from our file and print it
 char letter_read;
     while((letter_read = getc(fp)) != EOF) {
        printf("%c", letter_read);
        
     }
     fclose(fp);



    return 0;
}
