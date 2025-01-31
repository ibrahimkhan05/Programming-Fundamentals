#include <stdio.h>
#include <stdlib.h>

int main() {
    char *my_file = "String.txt";
    FILE *fp = fopen(my_file, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error oprning file %s", my_file);
        
    }
    int total_students;
    char student_name[20];
    int current_semester, cgpa;
    puts("How many students are there");
    scanf("%d",&total_students);
    for(int i = 0; i < total_students; i++) {
        getchar();
        puts("Enter students name: ");
        gets(student_name);
        puts("Enter student currnet Semester: ");
        scanf("%d", &current_semester);
        puts("Enter student CGPA: ");
        scanf("%d", &cgpa);
        if (i != total_students) {
            fprintf(fp, "%s %d %d", student_name, current_semester, cgpa);
        } else {
            fprintf(fp, "%s %d %d\n", student_name, current_semester, cgpa);
        }
        
    }
    return 0;
}