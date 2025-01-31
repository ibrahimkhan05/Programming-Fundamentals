#include <stdio.h>
#include <stdlib.h>
struct studentData
{
    char student_name[50];
    int student_semester;
    char student_grade;
    float student_cgpa;
};
void studentDataSaver(struct studentData all_students[], int total_student);
// void printDataSaver(struct studentData all_students[], int total_student);
struct StudentData *readDataFromFile();
void studentDataSaver(struct studentData all_students[], int total_student)
{
    char *file_name = "studentsrecords1.txt";
    FILE *fp = fopen(file_name, "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Could'nt Open file %s", file_name);
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "%d\n\n", total_student);
    for (int i = 0; i < total_student; i++)
    {
        getchar();
        printf("Enter name of student %d: ", i + 1);
        gets(all_students[i].student_name);
        printf("Enter current semster of student %d: ", i + 1);
        scanf("%d", &all_students[i].student_semester);
        printf("Enter CGPA of student %d: ", i + 1);
        scanf("%f", &all_students[i].student_cgpa);
        printf("Enter grade of student %d: ", i + 1);
        scanf(" %c", &all_students[i].student_grade);

        // Saving Data in file:
        fprintf(fp, "%d\n", i + 1);
        fprintf(fp, "%s\n", all_students[i].student_name);
        if (i < total_student - 1)
        {
            fprintf(fp, "%d\n%.2f\n%c\n\n", all_students[i].student_semester, all_students[i].student_cgpa, all_students[i].student_grade);
        }
        else
        {
            fprintf(fp, "%d\n%.2f\n%c", all_students[i].student_semester, all_students[i].student_cgpa, all_students[i].student_grade);
        }
    }

    fclose(fp);
}

struct StudentData *readDataFromFile()
{
    char *file_name = "studentsrecords1.txt";
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Could'nt Open file %s", file_name);
        exit(EXIT_FAILURE);
    }
    int total_students;
    fscanf(fp, "%d", &total_students);
    struct studentData *student_data = (struct studentData *)calloc(total_students, sizeof(struct studentData));
    printf("Total Number of students %d: ", total_students);
    return student_data;
}

int main(void)
{
    int total_students;
    printf("For how many students you want to save data? ");
    scanf("%d", &total_students);
    struct studentData all_students[total_students];
    studentDataSaver(all_students, total_students);
    struct studentData *address = readDataFromFile();
    free(address);
    return 0;
}
