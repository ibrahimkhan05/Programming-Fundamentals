#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


typedef struct {
    char fir_name[50];
    char last_name[50];
    char user_name[20];
    char password[20];
    long int account_num;
    float balance;
    int account_sel;
    char acc_type[20];
    int isCardHolder;
    long int card_num;
    long int acc_limit;
} Custumer;

char *database = "BankRecord.txt";

void createAccount();

int main(void) {
    printf("\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
    printf("\t\tMars Bank Limited\n");
    printf("\t-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\n");
    printf("Welcome to Mars Bank Limited.\n");
    printf("Dear Custumer Please Login in to your Account.\n");
    Sleep(2000);
    system("cls");
    printf("Enter your username: \n");
    printf("Enter your Account Password: ");

    int custumersInDb = 0;
    FILE *fp = fopen(database, "r");
    fscanf(fp, "%d", &custumersInDb);
    Custumer custumer[custumersInDb];

    

}