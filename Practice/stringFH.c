#include <stdio.h>
#include <stdlib.h>

int main() {
    char *my_file = "2spaces.txt";
    char my_name[30];
    char my_name_readed[30];
    char  last_name[20];
    int semester = 0;
    int semsster_read = 0;
    puts("Enter your name");
    FILE *fp = fopen(my_file, "w");
    if (fp == NULL) {
        fprintf(stderr, "Can't open file %s", my_file);
        exit(EXIT_FAILURE);
    }
    gets(my_name);
    printf("Enter your semster: ");
    scanf("%d", &semester);
    fprintf(fp, "%s %d", my_name, semester);
    fclose(fp);
    fp = fopen(my_file, "r");
   
    if (fp == NULL) {
        fprintf(stderr, "Can't open file %s", my_file);
        exit(EXIT_FAILURE);
    }
     fscanf(fp, "%s %d", my_name_readed, &semsster_read);
    if (semsster_read == 0) {
    fscanf(fp, "%s %d", last_name, &semsster_read);
    printf("%s %s %d", my_name_readed, last_name, semsster_read);
     
    }
    else
    printf("%s %d", my_name_readed, semsster_read);
    fclose(fp);
}