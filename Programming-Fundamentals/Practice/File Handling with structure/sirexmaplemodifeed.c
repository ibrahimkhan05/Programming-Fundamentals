#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 30

typedef struct {
    char first_name[MAX_NAME];
    char second_name[MAX_NAME];
    char last_name[MAX_NAME];
    int semester;
    float cgpa;
} Student;

void studentDataSaver(int total_students_saved, int student_data_to_save, Student student_data[]);
void studentDataInFile(char *location, int total_students_in_file, Student student_data[]);
void studentDataLoader(char *location, Student student_data[], int total_students_saved);
void printStudentData(char *location, int total_students_saved, Student student_data[]);

void studentDataSaver(int total_students_saved, int student_data_to_save, Student student_data[]) {
    for (int i = 0; i < student_data_to_save; i++)
    total_students_saved++;
    puts("Enter the first name of the student: ");
    scanf("%s", &student_data[total_students_saved].first_name);
    getchar();
    puts("Enter the second name of the student (Press Enter if not present)");
    scanf("%s", &student_data[total_students_saved].second_name);
    getchar;
    puts("Enter the last name of the : ");
    scanf("%s", &student_data[total_students_saved].last_name);
    getchar();
    puts("Enter the Semester of the student: ");
    scanf("%d", &student_data[total_students_saved].semester);
    puts("Enter the CGPA of the semester: ");
    scanf("%f ", &student_data[total_students_saved].cgpa);
    getchar();
}
void studentDataInFile(char *location, int total_students_in_file, Student student_data[]){

 FILE *fp = fopen(location, "w");
    if(fp == NULL) {
        fprintf(stderr, "Could not open file %s", location);
    }
    fprintf(fp, "%d", total_students_in_file);
    
    for(int i = 0; i < total_students_in_file; i++) {
        if (student_data[i].second_name[1] == '\n' && student_data[i].last_name[1] == '\n' ) {
           fprintf(fp , "%s %d %f\n", student_data[i].first_name, student_data[i].semester, student_data[i].cgpa);
        } else if (student_data[i].second_name[1] == '\n' && student_data[i].last_name[1] != '\n' ) {
            fprintf(fp , "%s %s %d %f\n", student_data[i].first_name, student_data[i].last_name, student_data[i].semester, student_data[i].cgpa);
        } else if (student_data[i].second_name[1] != '\n' && student_data[i].last_name[1] == '\n' ) {
            fprintf(fp , "%s %s %d %f\n", student_data[i].first_name, student_data[i].second_name, student_data[i].semester, student_data[i].cgpa);
        }
    }
    fclose(fp);
}
void studentDataLoader(char *location, Student student_data[], int total_students_saved) {
    FILE *fp = fopen(location, "r");
    if (fp == NULL) {
        fprintf(stderr, "Could'nt Open file %s\n", location);
    }
    for (int i = 0; i < total_students_saved; i++) {
         fscanf(fp, "%s %s %s %d %f", student_data[i].first_name, student_data[i].second_name, student_data[i].last_name, &student_data[i].semester, &student_data[i].cgpa);
         if (student_data[i].second_name[1] == '\n' &&  student_data[i].last_name[1] == '\n' ) {
        fscanf(fp, "%s %d %f", &student_data[i].first_name, &student_data[i].semester, &student_data[i].cgpa); 
         } else if (student_data[i].second_name[1] == '\n' &&  student_data[i].last_name[1] != '\n' ) {
         fscanf(fp, "%s %s %d %f", student_data[i].first_name, student_data[i].last_name, &student_data[i].semester, &student_data[i].cgpa);
         } else if (student_data[i].second_name[1] != '\n' &&  student_data[i].last_name[1] == '\n' ) {
            fscanf(fp, "%s %s %d %f", student_data[i].first_name, student_data[i].second_name, &student_data[i].semester, &student_data[i].cgpa);
         } else {
         fscanf(fp, "%s %s %s %d %f", student_data[i].first_name, student_data[i].second_name, student_data[i].last_name, &student_data[i].semester, &student_data[i].cgpa);
         } 
         }
         return;
         
    }
void printStudentData(char *location, int total_students_saved, Student student_data[]) {
    printf("Total Number; of students in Database: %d \n", total_students_saved);
    for (int i = 0; i < total_students_saved; i++) {
        for(int i = 0; i < total_students_saved; i++) {
        if (student_data[i].second_name[1] == '\n' && student_data[i].last_name[1] == '\n' ) {
           printf("%s %d %f\n", student_data[i].first_name, student_data[i].semester, student_data[i].cgpa);
        } else if (student_data[i].second_name[1] == '\n' && student_data[i].last_name[1] != '\n' ) {
            printf("%s %s %d %f\n", student_data[i].first_name, student_data[i].last_name, student_data[i].semester, student_data[i].cgpa);
        } else if (student_data[i].second_name[1] != '\n' && student_data[i].last_name[1] == '\n' ) {
           printf("%s %s %d %f\n", student_data[i].first_name, student_data[i].second_name, student_data[i].semester, student_data[i].cgpa);
        }
    }
    }
} 
int main() {
    int total_students_in_file = 0, student_data_to_save;
    char *my_file = "StudentsDatabase.txt";
    printf("%s\n", my_file);
    printf("Enter total Number of students you want to save: ");
    scanf("%d", &student_data_to_save);
    FILE *fp = fopen(my_file, "r");
    if (fp == NULL) {
        printf("Could'nt open file %s\n", my_file);
    }
    fscanf(fp, "%d", &total_students_in_file);
    if (total_students_in_file == 0) {
        printf("Welcome to Student Managment System\n\n");

    }
    int total_students = total_students_in_file + student_data_to_save;
    Student student_data[total_students];
    studentDataLoader(my_file,  student_data, total_students);
    studentDataSaver(total_students_in_file, student_data_to_save,student_data);
    studentDataInFile(my_file, total_students, student_data);
    printStudentData(my_file, total_students, student_data);
    return 0;
    

    
}