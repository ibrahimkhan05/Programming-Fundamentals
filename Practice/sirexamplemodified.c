#include <stdio.h>
#include <stdlib.h>
#define MAX_STD 25

typedef struct
{
    int roll_num;
    char fir_nam[MAX_STD];
    char las_nam[MAX_STD];
    int sem;
    float cgpa;
} Students;

void loadDb(char *fil_nam, Students std_data[], int std_in_db, int std_to_sav);
void takeData(Students std_data[], int std_to_sav, int std_in_db);
void saveInDb(char *file_loc, Students std_data[], int std_in_db, int total_std);
void printData(Students std_data[], int std_in_db);
void fetchByRollNumber(Students std_data[], int roll_num, int std_in_db);
void fetchByRollNumber(Students std_data[], int roll_num, int std_in_db)
{
    int isFound = 0;
    for (int i = 0; i < std_in_db; i++)
    {
        if (std_data[i].roll_num == roll_num)
        {
            printf("\n__________Student Found______________\n");

            printf("Roll Number: %d\nStudent Name: %s %s\nSemester: %d\nCGPA %.2f\n\n", std_data[i].roll_num, std_data[i].fir_nam, std_data[i].las_nam, std_data[i].sem, std_data[i].cgpa);
            isFound = 1;
            break;
        }
    }
    if (!isFound)
    {
        printf("No student Found");
    }
}
void printData(Students std_data[], int std_in_db)
{
    printf("\n__________STUDENTS SAVED IN DB______________\n");
    for (int i = 0; i < std_in_db; i++)
    {
        printf("Roll Number: %d\nStudent Name: %s %s\nSemester: %d\nCGPA %.2f\n\n", std_data[i].roll_num, std_data[i].fir_nam, std_data[i].las_nam, std_data[i].sem, std_data[i].cgpa);
    }
}

void loadDb(char *fil_nam, Students std_data[], int std_in_db, int std_to_sav)
{
    FILE *fp = fopen(fil_nam, "r");
    if (fp == NULL)
    {
        printf("Error....");
        return;
    }
    fscanf(fp, "%d", &std_in_db);
    printf("Total Number of students %d \n", std_in_db);
    for (int i = 0; i < std_in_db; i++)
    {
        fscanf(fp, "%d%s%s%d%f", &std_data[i].roll_num, std_data[i].fir_nam, std_data[i].las_nam, &std_data[i].sem, &std_data[i].cgpa);
    }
    fclose(fp);
}
void takeData(Students std_data[], int std_to_sav, int std_in_db)
{
    Students curr_data[std_to_sav];
    int roll_number = std_in_db;
    for (int i = 0; i < std_to_sav; i++)
    {

        getchar();
        roll_number++;
        curr_data[i].roll_num = roll_number;
        puts("Enter the first name of student: ");
        gets(curr_data[i].fir_nam);
        puts("Enter the last name of student: ");
        gets(curr_data[i].las_nam);
        puts("Enter the semester of student: ");
        scanf("%d", &curr_data[i].sem);
        puts("Enter the cgpa of student: ");
        scanf("%f", &curr_data[i].cgpa);
        std_data[std_in_db] = curr_data[i];
        std_in_db++;
    }
    return;
}
void saveInDb(char *file_loc, Students std_data[], int std_in_db, int total_std)
{
    FILE *fp = fopen(file_loc, "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Error in opening file %s", file_loc);
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "%d\n", total_std);
    for (int i = 0; i < total_std; i++)
    {
        if (i < total_std - 1)
        {
            fprintf(fp, "%d %s %s %d %f\n", std_data[i].roll_num, std_data[i].fir_nam, std_data[i].las_nam, std_data[i].sem, std_data[i].cgpa);
        }
        else
        {
            fprintf(fp, "%d %s %s %d %f\n", std_data[i].roll_num, std_data[i].fir_nam, std_data[i].las_nam, std_data[i].sem, std_data[i].cgpa);
        }
    }
    fclose(fp);
}

int main()
{
    int std_in_db = 0, std_to_sav = 0;
    int total_std;
    char *file_name = "StudentsDatabase.txt";

    // Now we know how many students we will load in program (to prevent memory issues

    int user_choice;
    do
    {
        printf("Welcome to ABC School managment System\n\n");
        printf("1.To add students\n2. To see all Saved Students\n3.To Serach student by roll Number\n0 to exit\n");
        scanf("%d", &user_choice);
        switch (user_choice)
        {
        case 1:
        {

            FILE *fp = fopen(file_name, "r");
            if (fp == NULL)
            {
                printf("Error......");
                return 1;
            }

            
            if (fscanf(fp, "%d", &std_in_db) == 0)
            {
                printf("No students in database");
            }
            puts("Enter the number of students you want to save: ");
            scanf("%d", &std_to_sav);
            total_std = std_in_db + std_to_sav;
            Students std_data[total_std];

            loadDb(file_name, std_data, std_in_db, std_to_sav);
            takeData(std_data, std_to_sav, std_in_db);
            saveInDb(file_name, std_data, total_std, total_std);
            printf("Datasaved\n");
            fclose(fp);
            break;
        }
        case 2:
        {
            FILE *fp = fopen(file_name, "r");
            if (fp == NULL)
            {
                printf("Error......");
                return 1;
            }

            if (fscanf(fp, "%d", &std_in_db) == 0)
            {
                printf("No students in database");
            }
            Students std_data[std_in_db];
            loadDb(file_name, std_data, std_in_db, std_to_sav);
            printData(std_data, std_in_db);
            break;
            fclose(fp);
        }
        case 3:
        {
            int roll_num;
            printf("To serach student enter its roll num: \n");
            scanf("%d", &roll_num);
            FILE *fp = fopen(file_name, "r");
            if (fp == NULL)
            {
                printf("Error......");
                return 1;
            }

            if (fscanf(fp, "%d", &std_in_db) == 0)
            {
                printf("No students in database");
            }
            Students std_data[std_in_db];
            loadDb(file_name, std_data, std_in_db, std_to_sav);
            fetchByRollNumber(std_data, roll_num, std_in_db);

            break;
        }
        case 0:
        {
            user_choice = 0;
            break;
        }
        default:
        {
            printf("Incorrect choice........\n");
        }
        }
    } while (user_choice != 0);
    return 0;
}