#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_QUESTION 20
#define MAX_STUDENTS 100



typedef struct
{
    char statement[1024];
    char optionA[50];
    int number_1;
    char optionB[50];
    int number_2;
    char optionC[50];
    int number_3;
    char optionD[50];
    int number_4;
    int correct_option;
} Quiz;

typedef struct
{
    char first_name[30];
    char last_name[30];
    int roll_num;
    int marks;
} students;

Quiz quiz_questions[MAX_QUESTION];
students student_data[100];
char *my_file = "QuizStatement.txt";
char *second_file = "Result.txt";

void addQuiz();
students *searchbyrollNumber(int roll_num);
void LoadData();
students *searchbyrollNumber(int roll_num)
{
    for (int i = 0; i < quiz_taken; i++)
    {
        if (student_data[i].roll_num == roll_num)
        {
            return &student_data[i];
        }
        else
        {
            return NULL;
        }
    }
}
void quizTaker()
{
    if (isQuizAdded)
    {
        int roll_num;
        int isRollNum = 0;
        if (quiz_taken > MAX_STUDENTS)
        {
            printf("Quiz already taken by all students.\n");
            return;
        }
        printf("Enter your roll num: ");
        scanf("%d", &roll_num);
        for (int i = 0; i < quiz_taken; i++)
        {
            if (student_data[i].roll_num == roll_num)
            {
                printf("You have already taken quiz with marks: %d/%d\n", student_data[i].marks, total_question);
                printf("You can' take the quiz again.\n");
                isRollNum = 1;
                break;
            }
        }

        if (!isRollNum)
        {
            printf("Enter your first name: ");
            scanf("%s", student_data[quiz_taken].first_name);
            printf("Enter your last name: ");
            scanf("%s", student_data[quiz_taken].last_name);
            int choice;
            printf("\tInstructions\nQuestions will appear on screen for 5 sec\nYou have 10 Sec to choose an option\nUse your time wisely.\n");
            Sleep(2000);
            system("cls");
            for (int i = 0; i < total_question; i++)
            {
                printf("Question no: %d\n", i + 1);
                printf("%s\n", quiz_questions[i].statement);
                printf("1) %s 2) %s 3) %s 4) %s\n", quiz_questions[i].optionA, quiz_questions[i].optionB, quiz_questions[i].optionC, quiz_questions[i].optionD);
                Sleep(7000);
                system("cls");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                if (quiz_questions[i].correct_option == choice)
                {
                    total_marks++;
                }
                system("cls");
            }

            student_data[quiz_taken].marks = total_marks;
            student_data[quiz_taken].roll_num = roll_num;

            total_marks = 0;

            FILE *fp = fopen(second_file, "w");
            if (fp == NULL)
            {
                printf("Error opening file...\n");
                exit(EXIT_FAILURE);
            }
            quiz_taken++;
            fprintf(fp, "%d\n", quiz_taken);
            for (int i = 0; i < quiz_taken; i++)
            {
                if (i == quiz_taken - 1)
                {
                    fprintf(fp, "%s %s %d %d\n", student_data[i].first_name, student_data[i].last_name, student_data[i].roll_num, student_data[i].marks);
                }
                else
                {
                    fprintf(fp, "%s %s %d %d", student_data[i].first_name, student_data[i].last_name, student_data[i].roll_num, student_data[i].marks);
                }
            }

            fclose(fp);
        }
    }
    else
    {
        printf("No quiz added yet\n");
    }
}

void LoadData()
{
    FILE *fp = fopen(my_file, "r");
    if (fp == NULL)
    {
        printf("Error Found\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%d", &total_question);
    fscanf(fp, "%d", &isQuizAdded);
    fgetc(fp);
    for (int i = 0; i < total_question; i++)
    {
        fgets(quiz_questions[i].statement, sizeof(quiz_questions[i].statement), fp);
        fgets(quiz_questions[i].optionA, sizeof(quiz_questions[i].optionA), fp);
        fgets(quiz_questions[i].optionB, sizeof(quiz_questions[i].optionB), fp);
        fgets(quiz_questions[i].optionC, sizeof(quiz_questions[i].optionC), fp);
        fgets(quiz_questions[i].optionD, sizeof(quiz_questions[i].optionD), fp);
        fscanf(fp, "%d%d%d%d%d%d", &quiz_questions[i].number_1, &quiz_questions[i].number_2, &quiz_questions[i].number_3, &quiz_questions[i].number_4, &quiz_questions[i].correct_option);
    }
    fclose(fp);

    fp = fopen(second_file, "r");
    fscanf(fp, "%d", &quiz_taken);
    for (int i = 0; i < quiz_taken; i++)
    {
        fscanf(fp, "%s%s%d%d", student_data[i].first_name, student_data[i].last_name, &student_data[i].roll_num, &student_data[i].marks);
    }
    fclose(fp);
}

void addQuiz()
{
    int temp_choice = 1;
    do
    {
        printf("Enter number of Questions (Maximum 20): ");
        scanf("%d", &total_question);
    } while (total_question > MAX_QUESTION);
    for (int i = 0; i < total_question; i++)
    {
        getchar();
        printf("Enter statement of question %d: ", i + 1);
        fgets(quiz_questions[i].statement, sizeof(quiz_questions[i].statement), stdin);

        printf("Enter option 1: ");
        fgets(quiz_questions[i].optionA, sizeof(quiz_questions[i].optionA), stdin);
        quiz_questions[i].number_1 = temp_choice++;

        printf("Enter option 2: ");
        fgets(quiz_questions[i].optionB, sizeof(quiz_questions[i].optionB), stdin);
        quiz_questions[i].number_2 = temp_choice++;

        printf("Enter option 3: ");
        fgets(quiz_questions[i].optionC, sizeof(quiz_questions[i].optionC), stdin);
        quiz_questions[i].number_3 = temp_choice++;

        printf("Enter option 4: ");
        fgets(quiz_questions[i].optionD, sizeof(quiz_questions[i].optionD), stdin);
        quiz_questions[i].number_4 = temp_choice++;

        printf("From (1-4), which is the correct option: ");
        scanf("%d", &quiz_questions[i].correct_option);
        temp_choice = 1;
    }

    isQuizAdded = 1;
    FILE *fp = fopen(my_file, "w");
    if (fp == NULL)
    {
        printf("Error opening file...\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%d\n", total_question);
    fprintf(fp, "%d\n", isQuizAdded);
    for (int i = 0; i < total_question; i++)
    {
        if (i == total_question - 1)
        {
            fprintf(fp, "%s", quiz_questions[i].statement);
            fprintf(fp, "%s", quiz_questions[i].optionA);
            fprintf(fp, "%s", quiz_questions[i].optionB);
            fprintf(fp, "%s", quiz_questions[i].optionC);
            fprintf(fp, "%s", quiz_questions[i].optionD);
            fprintf(fp, "%d %d %d %d %d\n", quiz_questions[i].number_1, quiz_questions[i].number_2, quiz_questions[i].number_3, quiz_questions[i].number_4, quiz_questions[i].correct_option);
        }
        else
        {
            fprintf(fp, "%s", quiz_questions[i].statement);
            fprintf(fp, "%s", quiz_questions[i].optionA);
            fprintf(fp, "%s", quiz_questions[i].optionB);
            fprintf(fp, "%s", quiz_questions[i].optionC);
            fprintf(fp, "%s", quiz_questions[i].optionD);
            fprintf(fp, "%d %d %d %d %d", quiz_questions[i].number_1, quiz_questions[i].number_2, quiz_questions[i].number_3, quiz_questions[i].number_4, quiz_questions[i].correct_option);
        }
    }
    fclose(fp);
}

int main()
{
    int choice;
    int teacher_choice, student_choice;
    LoadData();

    do
    {
        printf("\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("\t\tQuiz Management System\n");
        printf("\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");
        printf("Select any option from below\n");
        printf("1. I am a teacher\n2. I am a student\n3. exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        {
            do
            {
                printf("Select any option from below\n");
                printf("1. Add Quiz\n2. See results\n3. Delete Quiz\n4. See Result by Roll Num\n5. exit\n");
                scanf("%d", &teacher_choice);
                switch (teacher_choice)
                {
                case 1:
                    addQuiz();
                    break;
                case 2:
                {
                    printf("\t_+_+_+_+_+Students Results_+_+_+_+_+_+_\n");
                    printf("Quiz Taken by %d Student\n", quiz_taken);
                    for (int i = 0; i < quiz_taken; i++)
                    {
                        printf("Roll Num: %d\n", student_data[i].roll_num);
                        printf("Name: %s %s\n", student_data[i].first_name, student_data[i].last_name);
                        printf("Marks: %d/%d\n", student_data[i].marks, total_question);
                    }
                }
                case 3:
                {
                    break;
                }
                case 4:
                {
                    int roll_num;
                    printf("Enter Roll Num: \n");
                    scanf("%d", &roll_num);
                    students *result = searchbyrollNumber(roll_num);
                    if (result == NULL)
                    {
                        printf("Could not Find Student or this student have'nt taken Quiz\n");
                    }
                    else
                    {
                        printf("\t_+_+_+_+Student Record_+_+_+_+_+_+_+\n");
                        printf("Roll Number: %d\n", result->roll_num);
                        printf("Name: %s %s\n", result->first_name, result->last_name);
                        printf("Marks: %d/%d\n", result->marks, total_question);
                    }
                }

                case 5:
                    break;
                default:
                    printf("Invalid Choice\n");
                }
            } while (teacher_choice != 5);
            break;
        }
        case 2:
        {
            do { 
            printf("1. Take Quiz\n2. See result\n3. Exit\n");
            scanf("%d", &student_choice);
            switch(student_choice) {
                case 1: {
                     
            quizTaker();
            break;
                }
                case 2: {
                    int rolla_num;
                    printf("Enter your Roll Number: ");
                    scanf("%d", &rolla_num);
                    students *temp = searchbyrollNumber(rolla_num);
                    printf("Hello %s %s\n", temp->first_name, temp->last_name);
                    printf("You Got %d/%d\n", temp->marks, total_question);

                } case 3: {
                    break;
                } default: {
                    printf("Invalid Choice\n");
                    break;

                 }
            }
        } while (student_choice != 3); 
        break;
        }  case 3: {
            break;
        }
        default:{
          printf("Invalid choice.\n");
        }
            
        }

    } while (choice != 3);

    return 0;
}
