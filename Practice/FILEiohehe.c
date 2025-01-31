#include <stdio.h>
void writeData();
void writeData() {
    char *file_name = "test.txt";
    int total_students;
    printf("How much students data you want to save: ");
    scanf("%d", &total_students);
    char student_name[20];
    int student_semester;
    float student_cgpa;
    FILE *fp = fopen(file_name, "w");
    if (fp == NULL) {
        fprintf(stderr, "An error occured while opening file %s", file_name);
        return;
    }
    for (int i = 0; i < total_students; i++) {
        getchar();
        puts("Enter student name: ");
        gets(student_name);
        puts("Enter student current semester: ");
        scanf("%d", &student_semester);
        puts("Enter student CGPA: ");
        scanf("%f", &student_cgpa);
        if (i != total_students - 1) {
            fprintf(fp, "%s %d %.2f\n", student_name, student_semester, student_cgpa);
        } else {
            fprintf(fp, "%s %d %.2f", student_name, student_semester, student_cgpa);
        }
    }
    fclose(fp);
}
void readFile() {
    char first_name[20];
    char
}
int main () {
    writeData();
    return 0;
}