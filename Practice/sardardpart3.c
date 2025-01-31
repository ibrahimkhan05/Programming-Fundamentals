#include <stdio.h>
#include <stdlib.h>
int main () {
     char *file_name = "studentsrecords.txt";
     FILE *fp = fopen(file_name, "r");
     if (fp == NULL) {
        fprintf(stderr, "Could'nt open file %s", file_name);
        exit(EXIT_FAILURE);
     }
     char data_read[50];
     while (fgets(data_read, sizeof(data_read), fp) != NULL) {
     fgets(data_read, sizeof(data_read), fp);
     puts(data_read);
     }
     return 0;
}