// Headers files
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

// Values that will be fixed through all program
#define TOTAL_ROWS 6
#define TOTAL_COLUMNS 6
#define TOTAL_PLAYERS 2


int score_player1 = 0; //To track score of player 1
int score_player2 = 0; //To track score of player 2
int total_cards_flipped = 0; // To track how many cards are flipped, if all are flipped we will stop game and tell players scores and who won
int player_turn; // Global varibale to track player turn




// Fuctions prototype, that will be explained next in program when we will define that fuctions
// Since i have all prototype i will do defination of fuction below main so code is easily readile
void playerChooser();
void characterPlacerInBoard(char array_to_populated[TOTAL_ROWS][TOTAL_COLUMNS]);
int columnMapper(char column);
void hashPrinter(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS]);
void firstTurn(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS], char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int row_1, int column_1, char first_card);
void boardChecker(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS], char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int row_1, int column_1, char player_card_1, int row_2, int column_2, char player_card_2);
void revealedBoard(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS], char user_card, int selected_row, int selected_column);
 

 void playerChooser() {
    int player_turn = rand() % TOTAL_PLAYERS;
}

void characterPlacerInBoard(char array_to_populated[TOTAL_ROWS][TOTAL_COLUMNS]) {
    int row, columns;
    int isJokerPlaced = 0;
    int chracter_placed = 0;
    int isLowerCasePlaced = 0;
    int upercase_to_placed = 'A';
    int lowercase_to_placed = 'a';
    int total_chracter_to_place = TOTAL_ROWS * TOTAL_COLUMNS - 2;
    int is_already_populated[TOTAL_ROWS][TOTAL_COLUMNS] = {0};

    while (chracter_placed < total_chracter_to_place) {
        isLowerCasePlaced = 0;
        row = rand() % TOTAL_ROWS;
        columns = rand() % TOTAL_COLUMNS;
        if (is_already_populated[row][columns] == 0) {
            array_to_populated[row][columns] = upercase_to_placed;
            upercase_to_placed++;
            chracter_placed++;
            is_already_populated[row][columns]++;
            do {
                row = rand() % TOTAL_ROWS;
                columns = rand() % TOTAL_COLUMNS;

                if (is_already_populated[row][columns] == 0) {
                    array_to_populated[row][columns] = lowercase_to_placed;
                    lowercase_to_placed++;
                    chracter_placed++;
                    is_already_populated[row][columns]++;
                    isLowerCasePlaced = 1;
                }
            } while (!isLowerCasePlaced);
        }
    }

    while (isJokerPlaced < 2){
        row = rand() % TOTAL_ROWS;
        columns = rand() % TOTAL_COLUMNS;
        if (is_already_populated[row][columns] == 0) {
            array_to_populated[row][columns] = '*';
            is_already_populated[row][columns]++;
            isJokerPlaced++;
        }
    }
    return;
}

void hashPrinter(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS]) {
    printf("Player 1 Score: %d\n", score_player1);
    printf("Player 2 Score: %d\n\n", score_player2);
    printf("   A   B   C   D   E   F  \n");
    printf(" +---+---+---+---+---+---+\n");
    for (int i = 0; i < TOTAL_ROWS; i++) {
        printf("%d|", i);
        for (int j = 0; j < TOTAL_COLUMNS; j++) {
            printf(" %c |", hash_array[i][j]);
        }
        printf("\n +---+---+---+---+---+---+\n");
    }
}

int columnMapper(char column) {
    switch (column) {
    case 'A':
        return 0;
    case 'B':
        return 1;
    case 'C':
        return 2;
    case 'D':
        return 3;
    case 'E':
        return 4;
    case 'F':
        return 5;
    case 'a':
        return 0;
    case 'b':
        return 1;
    case 'c':
        return 2;
    case 'd':
        return 3;
    case 'e':
        return 4;
    case 'f':
        return 5;
    default:
        return -1;
    }
}

void revealedBoard(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS], char user_card, int selected_row, int selected_column){
    hash_array[selected_row][selected_column] = user_card;
}


void firstTurn(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS], char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int row_1, int column_1, char first_card) {
    if (first_card == '*') {
        int random_row, random_column;
        do { 
            random_row = rand() % TOTAL_ROWS;
           random_column = rand() % TOTAL_COLUMNS;
        } while (hash_array[random_row][random_column] == ' ');
        char first_card_selected = main_array[random_row][random_column];
        hashPrinter(hash_array);
        char second_card;
        if (first_card_selected >= 'A' && first_card_selected <= 'Q') {
            do {
                int row;
                int columns;
                do { 
            row = rand() % TOTAL_ROWS;
            columns = rand() % TOTAL_COLUMNS;
        } while (hash_array[row][columns] == ' ');
                second_card = main_array[row][columns];
                if (first_card_selected == (second_card - 32)) {
                    if (player_turn == 0) {
                        score_player1 += 2;
                        total_cards_flipped = total_cards_flipped + 3;
                       hashPrinter(hash_array);
                        Sleep(2000);
                        hash_array[row_1][column_1] = ' ';
                        hash_array[random_row][random_column] = ' ';
                        hash_array[row][columns] = ' ';
                        system("cls");
                    } else if (player_turn == 1) {
                        score_player2 += 2;
                        total_cards_flipped = total_cards_flipped + 3;
                        hashPrinter(hash_array);
                        Sleep(2000);
                        hash_array[row_1][column_1] = ' ';
                        hash_array[random_row][random_column] = ' ';
                        hash_array[row][columns] = ' ';
                        system("cls");;
                    } 
                } 
            } while (first_card_selected != (second_card - 32));
        } if (first_card_selected >= 'a' && first_card_selected <= 'q') {
            do {
             int row;
             int columns;
                do { 
                row = rand() % TOTAL_ROWS;
                columns = rand() % TOTAL_COLUMNS;
         }  while (hash_array[row][columns] == ' ');
                second_card = main_array[row][columns];
                if (first_card_selected == (second_card + 32)) {
                     if (player_turn == 0) {
                        score_player1 += 2;
                        total_cards_flipped = total_cards_flipped + 3;
                        hashPrinter(hash_array);
                        Sleep(2000);
                        hash_array[row_1][column_1] = ' ';
                        hash_array[random_row][random_column] = ' ';
                        hash_array[row][columns] = ' ';
                        system("cls");
                    } else if (player_turn == 1) {
                        score_player2 += 2;
                        total_cards_flipped = total_cards_flipped + 3;
                        hashPrinter(hash_array);
                        Sleep(2000);
                        hash_array[row_1][column_1] = ' ';
                        hash_array[random_row][random_column] = ' ';
                        hash_array[row][columns] = ' ';
                        system("cls");
                    }
                }
            } while (first_card_selected != (second_card + 32));
        }
    }
}

void boardChecker(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS], char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int row_1, int column_1, char player_card_1, int row_2, int column_2, char player_card_2) {
    if (player_card_1 >= 'A' && player_card_1 <= 'Q') {
        if (player_card_1 == (player_card_2 - 32)) {
            if (player_turn == 0) {
                score_player1++;
                total_cards_flipped = total_cards_flipped + 2;
                hash_array[row_1][column_1] = ' ';
                hash_array[row_2][column_2] = ' ';
                hashPrinter(hash_array);
                Sleep(2000);
                system("cls");
            } else if (player_turn == 1) {
                score_player2++;
                total_cards_flipped = total_cards_flipped + 2;
                hash_array[row_1][column_1] = ' ';
                hash_array[row_2][column_2] = ' ';
                hashPrinter(hash_array);
                Sleep(2000);
                system("cls");
            }
        } else if (player_card_2 != player_card_1 - 32)  {
            hashPrinter(hash_array);
            Sleep(2000);
            system("cls");
            hash_array[row_1][column_1] = '#';
            hash_array[row_2][column_2] = '#';
            player_turn = (player_turn + 1) % TOTAL_PLAYERS;
        }
    } else if (player_card_1 >= 'a' && player_card_1 <= 'q') {
        if (player_card_1 == (player_card_2 + 32)) {
            if (player_turn == 0) {
                score_player1++;
                total_cards_flipped = total_cards_flipped + 2;
                hash_array[row_1][column_1] = ' ';
                hash_array[row_2][column_2] = ' ';
                hashPrinter(hash_array);
                Sleep(2000);
                system("cls");
            } else if (player_turn == 1) {
                score_player2++;
                total_cards_flipped = total_cards_flipped + 2;
                hash_array[row_1][column_1] = ' ';
                hash_array[row_2][column_2] = ' ';
                hashPrinter(hash_array);
                Sleep(2000);
                system("cls");
            }
        } else if (player_card_2 != player_card_1 + 32)
         if (player_turn == 0) {
            hashPrinter(hash_array);
            Sleep(2000);
            system("cls");
            hashPrinter(hash_array);
            hash_array[row_1][column_1] = '#';
            hash_array[row_2][column_2] = '#';
            player_turn = (player_turn + 1) % TOTAL_PLAYERS;
            } else if (player_turn == 1) { 
            hashPrinter(hash_array);
            Sleep(2000);
            system("cls");
            hashPrinter(hash_array);
            hash_array[row_1][column_1] = '#';
            hash_array[row_2][column_2] = '#';
            player_turn = (player_turn + 1) % TOTAL_PLAYERS;
            }
    } else if (player_card_2 == '*') {
        int row, column;
        if (player_card_1 >= 'A' && player_card_1 <= 'Q') {
            do {
                do { 
                     row = rand() % TOTAL_ROWS;
                     column = rand() % TOTAL_COLUMNS;
                 } while (hash_array[row][column] == ' ');
                char selected_card = main_array[row][column];
                if (selected_card == (player_card_1 - 32)) {
                    if (player_turn == 0) {
                        score_player1 += 2;
                        total_cards_flipped = total_cards_flipped + 3;
                        hashPrinter(hash_array);
                        Sleep(2000);
                        hash_array[row_1][column_1] = ' ';
                        hash_array[row_2][column_2] = ' ';
                        hash_array[row][column] = ' ';
                        system("cls");
                    } else if (player_turn == 1) {
                        score_player2 += 2;
                        total_cards_flipped = total_cards_flipped + 3;
                        hashPrinter(hash_array);
                        Sleep(2000);
                        hash_array[row_1][column_1] = ' ';
                        hash_array[row_2][column_2] = ' ';
                        hash_array[row][column] = ' ';
                        system("cls");
                    }
                } 
            } while (main_array[row][column] != (player_card_1 - 32));
        } else if (player_card_1 >= 'a' && player_card_1 <= 'q') {
             do {
                row = rand() % TOTAL_ROWS;
                column = rand() % TOTAL_COLUMNS;
                int selected_card = main_array[row][column];
                if (selected_card == (player_card_1 + 32)) {
                     if (player_turn == 0) {
                        score_player1 += 2;
                        total_cards_flipped = total_cards_flipped + 3;
                        hashPrinter(hash_array);
                        Sleep(2000);
                        hash_array[row_1][column_1] = ' ';
                        hash_array[row_2][column_2] = ' ';
                        hash_array[row][column] = ' ';
                        system("cls");
                    }  else if (player_turn == 1) {
                        score_player2 += 2;
                        total_cards_flipped = total_cards_flipped + 3;
                        hashPrinter(hash_array);
                        Sleep(2000);
                        hash_array[row_1][column_1] = ' ';
                        hash_array[row_2][column_2] = ' ';
                        hash_array[row][column] = ' ';
                        system("cls");
                    } 
                }
            } while (main_array[row][column] != (player_card_1 + 32));
        }
    }
}

//MAIN fuction (execution point)
int main(void) {
    char user_choice;
    do {  
    // All varibles that will be used in program
    char board_contents[TOTAL_ROWS][TOTAL_COLUMNS] = {0};
    char hash_array[TOTAL_ROWS][TOTAL_COLUMNS];
    int selected_row_1;
    char selected_column_1;
    int mapped_column_1;
    int selected_row_2;
    char selected_column_2;
    int mapped_column_2;
    char first_card, second_card;
    

    for (int i = 0; i < TOTAL_ROWS; i++)  {
        for (int j = 0; j < TOTAL_ROWS; j++) {
            hash_array[i][j] = '#';
        }
    }
    srand(time(NULL));
    playerChooser();
    characterPlacerInBoard(board_contents);
    do {
        int turn = 0;
        if (player_turn == 0) {
            do {
                do {
                    hashPrinter(hash_array);
                    printf("Player %d: Enter a coordinate (e.g. B4 )\n", player_turn + 1);
                    scanf(" %c%d", &selected_column_1, &selected_row_1);
                    mapped_column_1 = columnMapper(selected_column_1);
                    if (hash_array[selected_row_1][mapped_column_1] == ' ') {
                        printf("Card on selcted coordinate have been revelead before\nChoose another coordinate:\n");
                    } else if ((selected_row_1 >= 0 && selected_row_1 <= 5) && (mapped_column_1 >= 0 && mapped_column_1 <= 5)) {
                        first_card = board_contents[selected_row_1][mapped_column_1];
                        revealedBoard(hash_array, first_card, selected_row_1, mapped_column_1);
                        firstTurn(hash_array, board_contents, selected_row_1, mapped_column_1, first_card);
                        turn++;
                    } else if ((selected_row_1 < 0 || selected_row_1 > 5) || (mapped_column_1 < 0 || mapped_column_1 > 5))
                    { if ((selected_row_1 < 0 || selected_row_1 > 5)) {
                            printf("You entered wrong row from board\n");
                    } else if ((mapped_column_1 < 0 || mapped_column_1 > 5)) {
                            printf("You entered wrong column from board\n");
                     }
                    } 
                } while ((selected_row_1 < 0 || selected_row_1 > 5) || (mapped_column_1 < 0 || mapped_column_1 > 5) || (hash_array[selected_row_1][mapped_column_1] == ' '));
                do {
                    hashPrinter(hash_array);
                    printf("Player %d: Enter a coordinate (e.g. B4 )\n", player_turn + 1);
                    scanf(" %c%d", &selected_column_2, &selected_row_2);
                    mapped_column_2 = columnMapper(selected_column_2);
                    if (hash_array[selected_row_2][mapped_column_2] == ' ') {
                        printf("Card on selcted coordinate have been revelead before\nChoose another coordinate:\n");
                    } else if ((selected_row_2 >= 0 && selected_row_2 <= 5) && (mapped_column_2 >= 0 && mapped_column_2 <= 5)) {
                        second_card = board_contents[selected_row_2][mapped_column_2];
                        revealedBoard(hash_array, second_card, selected_row_2, mapped_column_2);
                        boardChecker(hash_array, board_contents, selected_row_1, mapped_column_1, first_card, selected_row_2, mapped_column_2, second_card);
                        turn++;
                    } else if ((selected_row_2 < 0 || selected_row_2 > 5) || (mapped_column_2 < 0 || mapped_column_2 > 5))
                    {
                        if ((selected_row_2 < 0 || selected_row_2 > 5))  {
                            printf("You entered wrong row from board\n");
                        }  else if ((mapped_column_2 < 0 || mapped_column_2 > 5))  {
                            printf("You entered wrong column from board\n");
                        }
                    }
                } while ((selected_row_2 < 0 || selected_row_2 > 5) || (mapped_column_2 < 0 || mapped_column_2 > 5) || (hash_array[selected_row_2][mapped_column_2] == ' ') );
            } while (turn != 2);
        } else if (player_turn == 1) {
             do {
                do {
                    hashPrinter(hash_array);
                    printf("Player %d: Enter a coordinate (e.g. B4 )\n", player_turn + 1);
                    scanf(" %c%d", &selected_column_1, &selected_row_1);
                    mapped_column_1 = columnMapper(selected_column_1);
                    if (hash_array[selected_row_1][mapped_column_1] == ' ') {
                        printf("Card on selcted coordinate have been revelead before\nChoose another coordinate:\n");
                    } else if ((selected_row_1 >= 0 && selected_row_1 <= 5) && (mapped_column_1 >= 0 && mapped_column_1 <= 5)) {
                        first_card = board_contents[selected_row_1][mapped_column_1];
                        revealedBoard(hash_array, first_card, selected_row_1, mapped_column_1);
                        firstTurn(hash_array, board_contents, selected_row_1, mapped_column_1, first_card);
                        turn++;
                    } else if ((selected_row_1 < 0 || selected_row_1 > 5) || (mapped_column_1 < 0 || mapped_column_1 > 5))
                    { if ((selected_row_1 < 0 || selected_row_1 > 5)) {
                            printf("You entered wrong row from board\n");
                    } else if ((mapped_column_1 < 0 || mapped_column_1 > 5)) {
                            printf("You entered wrong column from board\n");
                     }
                    } 
                } while ((selected_row_1 < 0 || selected_row_1 > 5) || (mapped_column_1 < 0 || mapped_column_1 > 5) || (hash_array[selected_row_1][mapped_column_1] == ' '));
                do {
                    hashPrinter(hash_array);
                    printf("Player %d: Enter a coordinate (e.g. B4 )\n", player_turn + 1);
                    scanf(" %c%d", &selected_column_2, &selected_row_2);
                    mapped_column_2 = columnMapper(selected_column_2);
                    if (hash_array[selected_row_2][mapped_column_2] == ' ') {
                        printf("Card on selcted coordinate have been revelead before\nChoose another coordinate:\n");
                    } else if ((selected_row_2 >= 0 && selected_row_2 <= 5) && (mapped_column_2 >= 0 && mapped_column_2 <= 5)) {
                        second_card = board_contents[selected_row_2][mapped_column_2];
                        revealedBoard(hash_array, second_card, selected_row_2, mapped_column_2);
                        boardChecker(hash_array, board_contents, selected_row_1, mapped_column_1, first_card, selected_row_2, mapped_column_2, second_card);
                        turn++;
                    } else if ((selected_row_2 < 0 || selected_row_2 > 5) || (mapped_column_2 < 0 || mapped_column_2 > 5))
                    {
                        if ((selected_row_2 < 0 || selected_row_2 > 5))  {
                            printf("You entered wrong row from board\n");
                        }  else if ((mapped_column_2 < 0 || mapped_column_2 > 5))  {
                            printf("You entered wrong column from board\n");
                        }
                    }
                } while ((selected_row_2 < 0 || selected_row_2 > 5) || (mapped_column_2 < 0 || mapped_column_2 > 5) || (hash_array[selected_row_2][mapped_column_2] == ' ') );
            } while (turn != 2);
        }
    } while (total_cards_flipped != (TOTAL_ROWS * TOTAL_COLUMNS));\

    if (score_player1 > score_player2) {
        printf("Congrulations Player 1 !!! You won this game, Your score is: %d and your oppoent score is: %d\nYour have strong GUT feelings", score_player1, score_player2);
    } else if (score_player2 > score_player1) {
        printf("Congrulations Player 2 !!! You won this game, Your score is: %d and your oppoent score is: %d\nYour have strong GUT feelings", score_player2, score_player1);
    } else if (score_player1 == score_player2) {
        printf("Wow!!! What a game, You both played well, We have a TIE\n");
    } 
     
      printf("Hmmmm!!!!Do you want another game? (Y/N Defult N)");
      scanf(" %c", &user_choice);
  

    } while (user_choice != 'y' || user_choice != 'Y'  );
    return 0;
}


