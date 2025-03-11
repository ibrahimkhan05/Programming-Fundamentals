#include <stdio.h>
#include <stdlib.h>

int main () {
    char name_array[] = {'I', 'b', 'r', 'a', 'h', 'i', 'm'};
    char *file_name = "kuc.txt";
    FILE *fp = fopen(file_name, "w");
    if (fp == NULL) {
        fprintf(stderr, "Could'nt open file %s", file_name);
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < 7; i++) {
        putc(name_array[i], fp);
    }
    fclose(fp);
fp = fopen(file_name, "r");
 if (fp == NULL) {
        fprintf(stderr, "Could'nt open file %s", file_name);
        exit(EXIT_FAILURE);
    }
    char chrater_read;
    while((chrater_read = getc(fp)) != EOF) {
        printf("%c", chrater_read);
    }

    return 0;


}