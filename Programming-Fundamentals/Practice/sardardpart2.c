#include <stdio.h>
#include <stdlib.h>
struct studentData{
    char student_name[50];
    int student_semester;
    char student_grade;
    float student_cgpa;
};
void studentDataSaver(struct studentData all_students[], int total_student);
void printDataSaver(struct studentData all_students[], int total_student);
void printDataFromFile();
void studentDataSaver(struct studentData all_students[], int total_student) {
      char *file_name = "studentsrecords.txt";
     FILE *fp = fopen(file_name, "w");
     if (fp ==NULL) {
        fprintf(stderr, "Could'nt Open file %s", file_name);
        exit(EXIT_FAILURE);
     }
     fprintf(fp, "Total Students: %d\n\n", total_student);
     for (int i = 0; i < total_student; i++) {
        getchar();
        printf("Enter name of student %d: ", i+1);
        gets(all_students[i].student_name);
        printf("Enter current semster of student %d: ", i+1);
        scanf("%d", &all_students[i].student_semester);
        printf("Enter CGPA of student %d: ", i+1);
        scanf("%f", &all_students[i]. student_cgpa);
        printf("Enter grade of student %d: ", i+1);
        scanf(" %c", &all_students[i].student_grade);

        //Saving Data in file: 
        fprintf(fp, "Student no: %d\n", i+1);
        fprintf(fp, "Student Name: %s\n", all_students[i].student_name);
        if (i < total_student - 1) {
         fprintf(fp, "Student Semester: %d\nStudent CGPA: %.2f\nStudent Grade %c\n\n", all_students[i].student_semester, all_students[i].student_cgpa, all_students[i].student_grade);
     }  else {
         fprintf(fp, "Student Semester: %d\nStudent CGPA: %.2f\nStudent Grade: %c", all_students[i].student_semester, all_students[i].student_cgpa, all_students[i].student_grade);
     }
     } 
    
     fclose(fp);
}
void printDataSaver(struct studentData all_students[], int total_student) {
    printf("=*=*=*=*=*=*=*=*=*=*=*=*STUDENT DATA=*=*=*=*=*=*=*=*=*=*=*=*\n");
     for(int i = 0; i < total_student; i++) {
        printf("Record of Student %d\n\n", i+1);
        printf("Student Name: ");
        puts(all_students[i].student_name);
        printf("Current Semester: %d\n", all_students[i].student_semester);
        printf("CGPA: %.2f\n", all_students[i]. student_cgpa);
        printf("GRADE: %c\n\n", all_students[i].student_grade);
     }
}
void printDataFromFile() {
     char *file_name = "studentsrecords.txt";
     FILE *fp = fopen(file_name, "r");
     if (fp == NULL) {
        fprintf(stderr, "Could'nt open file %s", file_name);
        exit(EXIT_FAILURE);
     }
     char data_read[50];
     while(fp != EOF) {
     fgets(data_read, sizeof(data_read), fp);
     puts(data_read);
     }
     
     
}
int main(void) {
    int total_students;
    printf("For how many students you want to save data? ");
    scanf("%d", &total_students);
    struct studentData all_students[total_students];
    studentDataSaver(all_students, total_students);
    printDataSaver(all_students, total_students);
    printDataFromFile();
    return 0;
}
