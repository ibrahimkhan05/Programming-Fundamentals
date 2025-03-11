//PreProcessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//Constants
#define MAX_QUESTION 20
#define MAX_STUDENTS 100

//Global Varibale (Will be used in Program)
int isQuizAdded = 0;
int total_marks = 0;
int total_question = 0;
int quiz_taken = 0;
int passing_marks = 0;
int overall_marks = 0;
int passed_students = 0;
int failed_students= 0;
char secreact_code[30];

//Structures

//To store quiz related content
typedef struct {
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

//To store Student Deatails
typedef struct {
    char first_name[30];
    char last_name[30];
    int roll_num;
    int marks;
} students;

//To store Data
Quiz quiz_questions[MAX_QUESTION];
students student_data[MAX_STUDENTS];

//Files in Which Data will be dumped
char *my_file = "QuizStatement.txt";
char *second_file = "Result.txt";

//Function ProtoTypes
void savetofile();
void addQuiz(int *stunts_allowed);
students *searchbyrollNumber(int roll_num);
void LoadData(int *stunts_allowed);
void quizTaker(int *stunts_allowed);
void resultChecker();
void savetofile(int *stunts_allowed);
//Functions Definations
void savetofile(int *stunts_allowed) {
    FILE *fp = fopen(second_file, "w");
            if (fp == NULL) {
                printf("Error opening file...\n");
                exit(EXIT_FAILURE);
            }
            
            fprintf(fp, "%d\n", quiz_taken);
            fprintf(fp, "%d\n", overall_marks);
            fprintf(fp, "%d\n", passing_marks);
            fprintf(fp, "%d\n", *stunts_allowed);
            fprintf(fp, "%d\n", passed_students);
            fprintf(fp, "%d\n", failed_students);
            for (int i = 0; i < quiz_taken; i++) {
                if (i < quiz_taken - 1) {
                    fprintf(fp, "%s %s %d %d\n", student_data[i].first_name, student_data[i].last_name, student_data[i].roll_num, student_data[i].marks);
                } else {
                    fprintf(fp, "%s %s %d %d", student_data[i].first_name, student_data[i].last_name, student_data[i].roll_num, student_data[i].marks);
                }
            }

            fclose(fp);
            fp = fopen(my_file, "w");
       if (fp == NULL) {
        printf("Error opening file...\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%d\n", total_question);
    fprintf(fp, "%d\n", isQuizAdded);
    fprintf(fp, "%s", secreact_code);
    for (int i = 0; i < total_question; i++) {
        if (i < total_question - 1) {
            fprintf(fp, "%s", quiz_questions[i].statement);
            fprintf(fp, "%s", quiz_questions[i].optionA);
            fprintf(fp, "%s", quiz_questions[i].optionB);
            fprintf(fp, "%s", quiz_questions[i].optionC);
            fprintf(fp, "%s", quiz_questions[i].optionD);
            fprintf(fp, "%d %d %d %d %d\n", quiz_questions[i].number_1, quiz_questions[i].number_2, quiz_questions[i].number_3, quiz_questions[i].number_4, quiz_questions[i].correct_option);
        } else {
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
void resultChecker(int roll_nome) {
    students *temp = searchbyrollNumber(roll_nome);
    if (temp != NULL) {
        if (temp->marks >= passing_marks) {
        printf("Pass\n");
    } else { 
        printf("Fail\n");
    }
    } else {
        return;
    }
    
    
}
//To serach student By roll number
students *searchbyrollNumber(int roll_num) {
    for (int i = 0; i < quiz_taken; i++) {
        if (student_data[i].roll_num == roll_num) {
            return &student_data[i];
        } 
    }
     return NULL;
}

//Function That will take Quiz from Student and store Result in Files..
void quizTaker(int *stunts_allowed) {
    if (isQuizAdded) {
        int roll_num;
        int isRollNum = 0;
        char secreat_word[50];
        if (quiz_taken > *stunts_allowed) {
            printf("Quiz already taken by all students.\n");
            return;
        }

        printf("Enter your roll num: ");
        scanf("%d", &roll_num);

        for (int i = 0; i < quiz_taken; i++) {
            if (student_data[i].roll_num == roll_num) {
                printf("You have already taken quiz with marks: %d/%d\n", student_data[i].marks, total_question);
                printf("You can't take the quiz again.\n");
                isRollNum = 1;
                break;
            }
        }

        if (!isRollNum) {
            getchar();
            printf("Enter the code which was given by your Teacher/School\n");
            fgets(secreat_word, sizeof(secreat_word), stdin);

            if (strcmp(secreat_word, secreact_code) != 0) {
                printf("Wrong Code... Maybe you are an imposter\n");
                exit(EXIT_FAILURE);
            } else {

            printf("Enter your first name: ");
            scanf("%s", student_data[quiz_taken].first_name);

            printf("Enter your last name: ");
            scanf("%s", student_data[quiz_taken].last_name);

            int choice;
            printf("Hello %s %s\nQuiz Marks: %d\nPassing Marks: %d\nQuestions will appear on screen for 10 sec\nYou have 10 Sec to choose an option\nUse your time wisely.\n", student_data[quiz_taken].first_name, student_data[quiz_taken].last_name, overall_marks, passing_marks);
            Sleep(4000);
            system("cls");
            for (int i = 0; i < total_question; i++) {

                printf("Question no: %d\n", i + 1);
                printf("%s\n", quiz_questions[i].statement);
                printf("1) %s2) %s3) %s4)%s\n", quiz_questions[i].optionA, quiz_questions[i].optionB, quiz_questions[i].optionC, quiz_questions[i].optionD);
                Sleep(7000);
                system("cls");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                if (quiz_questions[i].correct_option == choice) {
                    total_marks++;
                }
                system("cls");
            }
            
             if (total_marks >= passing_marks) {
                passed_students++;
             } else {
                failed_students++;
             }
            student_data[quiz_taken].marks = total_marks;
            student_data[quiz_taken].roll_num = roll_num;
            total_marks = 0;
            quiz_taken++;
        }

            }
            
    } else {
        printf("No quiz added yet\n");
    }
}

//Function to load Data from File 
void LoadData(int *stunts_allowed) {
    FILE *fp = fopen(my_file, "r");
    if (fp == NULL) {
        printf("Error Found\n");
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%d", &total_question);
    fscanf(fp, "%d", &isQuizAdded);
    fgetc(fp);
    fgets(secreact_code, sizeof(secreact_code), fp);
    for (int i = 0; i < total_question; i++) {
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
    fscanf(fp, "%d", &overall_marks);
    fscanf(fp, "%d", &passing_marks);
    fscanf(fp, "%d", stunts_allowed);
    fscanf(fp, "%d", &passed_students);
    fscanf(fp, "%d", &failed_students);
    for (int i = 0; i < quiz_taken; i++) {
        fscanf(fp, "%s%s%d%d", student_data[i].first_name, student_data[i].last_name, &student_data[i].roll_num, &student_data[i].marks);
    }
    fclose(fp);
}

//Function That will intrqct with Teacher to Add Questions..
void addQuiz(int *stunts_allowed) {
    int temp_choice = 1;
    do {
        printf("Enter number of Questions (Maximum 20): ");
        scanf("%d", &total_question);
    } while (total_question > MAX_QUESTION);

    printf("Enter Total Marks: ");
    scanf("%d", &overall_marks);

    printf("Enter Passing marks: ");
    scanf("%d", &passing_marks);

    getchar();
    printf("Enter an secret code which will be use to identify your Students: ");
    fgets(secreact_code, sizeof(secreact_code), stdin);
    do {
        printf("How many students will take quiz(Maximum %d):", MAX_STUDENTS);
        scanf("%d", stunts_allowed);
    } while (*stunts_allowed > MAX_STUDENTS);
    for (int i = 0; i < total_question; i++) {
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
   
}

//Main function where program will be executed
int main() {
    int choice;
    int teacher_choice, student_choice;
    int students_allowed;
    LoadData(&students_allowed);
    do {
        printf("\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
        printf("\t\tQuiz Management System\n");
        printf("\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");
        printf("Select any option from below\n");
        printf("1. I am a teacher\n2. I am a student\n3. exit\n");
        scanf("%d", &choice);
        system("cls");
        //Main menu
        switch (choice) {
        case 1: {
            //Teacher Menu
            do {
                printf("Select any option from below\n");
                printf("1. Add Quiz\n2. See all results\n3. See Result by Roll Num\n4. Delete Quiz\n5. Delete Students Result\n6. exit\n");
                scanf("%d", &teacher_choice);
                system("cls");
                switch (teacher_choice) {
                    //To add Quiz
                case 1: {
                    addQuiz(&students_allowed);
                    savetofile(&students_allowed);
                    break;
                } case 2: {
                    //To see quiz Result
                    printf("\t_+_+_+_+_+Students Results_+_+_+_+_+_+_\n");
                    printf("Quiz Taken by %d Students\n", quiz_taken);
                    printf("\tPassed: %d\tFailed: %d\n", passed_students, failed_students);
                    for (int i = 0; i < quiz_taken; i++) {
                        printf("Roll Num: %d\n", student_data[i].roll_num);
                        printf("Name: %s %s\n", student_data[i].first_name, student_data[i].last_name);
                        printf("Marks: %d/%d\n", student_data[i].marks, overall_marks);
                        if(student_data[i].marks >= passing_marks ) {
                            printf("Pass\n");
                        } else {
                            printf("Fail\n");
                        }
                    }
                     Sleep(5000);
                     system("cls");
                    break;
                } case 3: {
                    //Serach student Result by Roll Num
                    int roll_num;
                    printf("Enter Roll Num: \n");
                    scanf("%d", &roll_num);
                    students *result = searchbyrollNumber(roll_num);
                    if (result == NULL) {
                        printf("Could not Find Student or this student have'nt taken Quiz\n");
                        Sleep(2000);
                        system("cls");
                    } else {
                        printf("\t_+_+_+_+Student Record_+_+_+_+_+_+_+\n");
                        printf("Roll Number: %d\n", result->roll_num);
                        printf("Name: %s %s\n", result->first_name, result->last_name);
                        printf("Marks: %d/%d\n", result->marks, overall_marks);
                        resultChecker(roll_num);
                        printf("+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_\n");
                        Sleep(5000);
                        system("cls");
                    }
                    break;
                    
                } case 4: {
                    //Clear Quiz Question from Memory and File
                    for(int i = 0; i < MAX_QUESTION; i++) {
                        strcpy(quiz_questions[i].statement, "");
                        strcpy(quiz_questions[i].optionA, "");
                        strcpy(quiz_questions[i].optionB, "");
                        strcpy(quiz_questions[i].optionC, "");
                        strcpy(quiz_questions[i].optionD, "");
                        quiz_questions[i].number_1 = 0;
                        quiz_questions[i].number_2 = 0;
                        quiz_questions[i].number_3 = 0;
                        quiz_questions[i].number_3 = 0;
                        quiz_questions[i].number_4 = 0;
                        quiz_questions[i].correct_option = 0;
                    }
                    isQuizAdded = 0;
                    total_marks = 0;
                    total_question = 0;
                    strcpy(secreact_code, "");
                    FILE *fp = fopen(my_file, "w");
                    if(fp == NULL) {
                        printf("Error.....\n");
                    } 
                    putc('\0', fp);
                    printf("Quiz cleared sucesfully.....\n");
                    Sleep(1000);
                    system("cls");
                    break;
                    
                    } case 5: {
                        //Delete Student Reocrd from mepry and File
                    for (int i = 0; i < MAX_STUDENTS; i++) {
                        strcpy(student_data[i].first_name, "");
                        strcpy(student_data[i].last_name, "");
                        student_data[i].marks = 0;
                        student_data[i].marks = 0;
                        students_allowed = 0;
                        quiz_taken = 0;
                        passing_marks = 0;
                        overall_marks = 0;
                        passed_students = 0;
                        failed_students = 0;

                    }
                    printf("Student Result cleared sucessfully.....\n");
                    Sleep(1000);
                     FILE *fp = fopen(second_file, "w");
                    if(fp == NULL) {
                        printf("Error.....\n");
                    } 
                    putc('\0', fp);
                    system("cls");
                    break;
                } case 6: {
                        break;
                }
                   
                default: {
                    printf("Invalid Choice\n");
                    Sleep(1000);
                    system("cls");
                    
                }
           }
            } while (teacher_choice != 6);
            break;
        }
        case 2:
        {
            //Student Menu
            do { 
            printf("1. Take Quiz\n2. See result\n3. Exit\n");
            scanf("%d", &student_choice);
            system("cls");
            switch(student_choice) {
                case 1: {
                    //Take Quiz
                 quizTaker(&students_allowed);
                 savetofile(&students_allowed);
                 break;
                } case 2: {
                    //serach by roll Num
                    int rolla_num;
                    printf("Enter your Roll Number: ");
                    scanf("%d", &rolla_num);
                    students *temp = searchbyrollNumber(rolla_num);
                    if(temp == NULL) {
                        printf("You have not taken quiz\n");
                        Sleep(1000);
                        system("cls");
                    } else {
                        printf("Hello %s %s\n", temp->first_name, temp->last_name);
                    printf("You Got %d/%d\n", temp->marks, overall_marks);
                    resultChecker(rolla_num);
                    Sleep(5000);
                    system("cls");
                    }     

                } case 3: {
                    //To exit main menu
                    break;
                } default: {
                    printf("Invalid Choice\n");\
                    Sleep(1000);
                    system("cls");
                }
            }
        } while (student_choice != 3);
        break;
         } case 3: {
            break;
         }
        
        default:
            printf("Invalid choice.\n");
             break;
        }

    } while (choice != 3);

    return 0;
}
