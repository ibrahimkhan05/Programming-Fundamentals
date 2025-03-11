// Headers files
/*

Group Members:

Ibrahim Khan
SP24-BCS-160

Zuneera Tariq 
SP24-BCS-133
*/
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
char hash_array[TOTAL_ROWS][TOTAL_COLUMNS]; // our aray use to hide chracters
int isJokerPlaced = 0; // To keep track is joker revel (for some optmization)


/* Fuctions prototype, function to handle each siatuation, */
void playerChooser();
void characterPlacerInBoard(char array_to_populated[TOTAL_ROWS][TOTAL_COLUMNS]);
int columnMapper(char column);
void hashPrinter(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS]);
void firstTurn(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS], char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int row_1, int column_1, char first_card);
void boardChecker(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS], char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int row_1, int column_1, char player_card_1, int row_2, int column_2, char player_card_2, int cards_flipped);
void revealedBoard(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS], char user_card, int selected_row, int selected_column);
void iFCardsAreNotMtached(int user_row_1, int user_column_1, int user_row_2, int user_column_2);
void scoreSecondCardIsJoker(char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int user_row_1, int user_column_1, int user_row_2, int user_column_2, int genreater_row_1, int genreater_column_1, char genreater_card);
void scoreSecondCardIsMatched(char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int user_row_1, int user_column_1, int user_row_2, int user_column_2);
void scoreFirstCardIsJoker(char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int user_row_1, int user_column_1, int genreater_row_1, int genreater_column_1, int genreater_row_2, int genreater_column_2);
void scoreSelectedCardIsAlsoJoker(char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int user_row_1, int user_column_1, int genreater_row_1, int genreater_column_1, int genreater_row_2, int genreater_column_2, int genreater_row_3, int genreater_column_3, int genreater_row_4, int genreater_column_4, int genreater_row_5, int genreater_column_5);
void scoreSecondCardIsJoker(char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int user_row_1, int user_column_1, int user_row_2, int user_column_2, int genreater_row_1, int genreater_column_1, char genreater_card) {


//If all chracters are reveled and user joker are not reveled
void scoreLastTwoCardsAreJoker(char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int user_row_0, int user_column_0, int user_row_1, int user_column_1, int genreater_row_1, int genreater_column_1, int genreater_row_2, int genreater_column_2);
 if (player_turn == 0) { // give score base on turn
            score_player1 += 2; // give score to player
            total_cards_flipped = total_cards_flipped + 3; // reveled cards how many have you did upon scusfuk exe of this fiction
            hash_array[genreater_row_1][genreater_column_1] = genreater_card;
            hashPrinter(hash_array); // print hash array (updted)
            printf("You got two points\n"); // prompt user
            Sleep(2000); //pause execuation

            // Flip cards and remove that cards for game too
            hash_array[genreater_row_1][genreater_column_1] = ' '; 
            hash_array[user_row_1][user_column_1] = ' ';
            hash_array[user_row_2][user_column_2] = ' ';
            main_array[genreater_row_1][genreater_column_1] = ' ';
            main_array[user_row_1][user_column_1] = ' ';
            main_array[user_row_2][user_column_2] = ' ';
            system("cls");
        } else if (player_turn == 1) {
            score_player1 += 2;
            total_cards_flipped = total_cards_flipped + 3;
            hash_array[genreater_row_1][genreater_column_1] = genreater_card;
            hashPrinter(hash_array);
            printf("You got two points\n");
            Sleep(2000);
            hash_array[genreater_row_1][genreater_column_1] = ' ';
            hash_array[user_row_1][user_column_1] = ' ';
            hash_array[user_row_2][user_column_2] = ' ';
            main_array[genreater_row_1][genreater_column_1] = ' ';
            main_array[user_row_1][user_column_1] = ' ';
            main_array[user_row_2][user_column_2] = ' ';
            system("cls");
        }
}

//if User picked cards are equal 
void scoreSecondCardIsMatched(char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int user_row_1, int user_column_1, int user_row_2, int user_column_2) {  
 if (player_turn == 0) {
                score_player1++;
                total_cards_flipped = total_cards_flipped + 2;
                hashPrinter(hash_array);
                printf("You got one point\n");
                Sleep(2000);
                system("cls");
                hash_array[user_row_1][user_column_1] = ' ';
                hash_array[user_row_2][user_column_2] = ' ';
                main_array[user_row_1][user_column_1] = ' ';
                main_array[user_row_2][user_column_2] = ' ';
            } else if (player_turn == 1) {
                score_player2++;
                total_cards_flipped = total_cards_flipped + 2;
                hashPrinter(hash_array);
                printf("You got one point\n");
                Sleep(2000);
                system("cls");
                hash_array[user_row_1][user_column_1] = ' ';
                hash_array[user_row_2][user_column_2] = ' ';
                main_array[user_row_1][user_column_1] = ' ';
                main_array[user_row_2][user_column_2] = ' ';
                
            }

}

// If cards are not matched
void iFCardsAreNotMtached(int user_row_1, int user_column_1, int user_row_2, int user_column_2) {
    hashPrinter(hash_array);
    printf("Your Card did't matched\n");
            Sleep(2000);
            system("cls");
            hash_array[user_row_1][user_column_1] = '#';
            hash_array[user_row_2][user_column_2] = '#';
            player_turn = (player_turn + 1) % TOTAL_PLAYERS;


}

//If first card is joker 
void scoreFirstCardIsJoker(char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int user_row_1, int user_column_1, int genreater_row_1, int genreater_column_1, int genreater_row_2, int genreater_column_2) {
    if (player_turn == 0) { 
                        score_player1 += 2;
                        total_cards_flipped = total_cards_flipped + 3; 
                        hashPrinter(hash_array); 
                        printf("You got two points\n");
                        Sleep(2000); 
                        hash_array[user_row_1][user_column_1] = ' '; 
                        hash_array[genreater_row_1][genreater_column_1] = ' ';
                        hash_array[genreater_row_2][genreater_column_2] = ' ';
                        main_array[user_row_1][user_column_1] = ' ';
                        main_array[genreater_row_1][genreater_column_1] = ' ';
                        main_array[genreater_row_2][genreater_column_2] = ' ';
                        system("cls");
                    } else if (player_turn == 1) { 
                        score_player2 += 2;
                        total_cards_flipped = total_cards_flipped + 3;
                        hashPrinter(hash_array); 
                        printf("You got two points\n");
                        Sleep(2000); 
                        hash_array[user_row_1][user_column_1] = ' '; 
                        hash_array[genreater_row_1][genreater_column_1] = ' ';
                        hash_array[genreater_row_2][genreater_column_2] = ' ';
                        main_array[user_row_1][user_column_1] = ' '; 
                        main_array[genreater_row_1][genreater_column_1] = ' ';
                        main_array[genreater_row_2][genreater_column_2] = ' ';
                        system("cls");
                }
}

// Fuction to hadnle is second card that is selcted and first card is joker
void scoreSelectedCardIsAlsoJoker(char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int user_row_1, int user_column_1, int genreater_row_1, int genreater_column_1, int genreater_row_2, int genreater_column_2, int genreater_row_3, int genreater_column_3, int genreater_row_4, int genreater_column_4, int genreater_row_5, int genreater_column_5) {
if (player_turn == 0) {
                        score_player1 += 4;
                        total_cards_flipped = total_cards_flipped + 6;
                        hashPrinter(hash_array);
                        printf("You got four points\n");
                        Sleep(2000);
                        hash_array[user_row_1][user_column_1] = ' ';
                        hash_array[genreater_row_1][genreater_column_1] = ' ';
                        hash_array[genreater_row_2][genreater_column_2] = ' ';
                        hash_array[genreater_row_3][genreater_column_3] = ' ';
                        hash_array[genreater_row_4][genreater_column_4] = ' ';
                        hash_array[genreater_row_5][genreater_column_5] = ' ';
                        main_array[user_row_1][user_column_1] = ' ';
                        main_array[genreater_row_1][genreater_column_1] = ' ';
                        main_array[genreater_row_2][genreater_column_2] = ' ';
                        main_array[genreater_row_3][genreater_column_3] = ' ';
                        main_array[genreater_row_4][genreater_column_4] = ' ';
                        main_array[genreater_row_5][genreater_column_5] = ' ';
                        system("cls");
                    } else if (player_turn == 1) {
                        score_player2 += 4;
                        total_cards_flipped = total_cards_flipped + 6;
                        hashPrinter(hash_array);
                        printf("You got four points\n");
                        Sleep(2000);
                         hash_array[user_row_1][user_column_1] = ' ';
                        hash_array[genreater_row_1][genreater_column_1] = ' ';
                        hash_array[genreater_row_2][genreater_column_2] = ' ';
                        hash_array[genreater_row_3][genreater_column_3] = ' ';
                        hash_array[genreater_row_4][genreater_column_4] = ' ';
                        hash_array[genreater_row_5][genreater_column_5] = ' ';
                         main_array[user_row_1][user_column_1] = ' ';
                        main_array[genreater_row_1][genreater_column_1] = ' ';
                        main_array[genreater_row_2][genreater_column_2] = ' ';
                        main_array[genreater_row_3][genreater_column_3] = ' ';
                        main_array[genreater_row_4][genreater_column_4] = ' ';
                        main_array[genreater_row_5][genreater_column_5] = ' ';
                        system("cls");
                    }
}

//If all chracters are reveled and user joker are not reveled
void scoreLastTwoCardsAreJoker(char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int user_row_0, int user_column_0, int user_row_1, int user_column_1, int genreater_row_1, int genreater_column_1, int genreater_row_2, int genreater_column_2) {
    if (player_turn == 0) { 
                        score_player1 += 3;
                        total_cards_flipped = total_cards_flipped + 4; 
                        hashPrinter(hash_array); 
                        printf("You got Three points\n");
                        Sleep(2000); 
                        hash_array[user_row_1][user_column_1] = ' '; 
                        hash_array[user_column_1][user_column_1] = ' ';
                        hash_array[genreater_row_1][genreater_column_1] = ' ';
                        hash_array[genreater_row_2][genreater_column_2] = ' ';
                        main_array[user_row_1][user_column_1] = ' ';
                        main_array[user_column_1][user_column_1] = ' ';
                        main_array[genreater_row_1][genreater_column_1] = ' ';
                        main_array[genreater_row_2][genreater_column_2] = ' ';
                        system("cls");
                    } else if (player_turn == 1) { 
                        score_player2 += 3;
                        total_cards_flipped = total_cards_flipped + 4;
                        hashPrinter(hash_array); 
                        printf("You got Three points\n");
                        Sleep(2000); 
                        hash_array[user_row_1][user_column_1] = ' '; 
                        hash_array[user_column_1][user_column_1] = ' ';
                        hash_array[genreater_row_1][genreater_column_1] = ' ';
                        hash_array[genreater_row_2][genreater_column_2] = ' ';
                        main_array[user_row_1][user_column_1] = ' '; 
                        main_array[user_column_1][user_column_1] = ' ';
                        main_array[genreater_row_1][genreater_column_1] = ' ';
                        main_array[genreater_row_2][genreater_column_2] = ' ';
                        system("cls"); 
                }
}
// Fucnction to choose random player
 void playerChooser() {
    int player_turn = rand() % TOTAL_PLAYERS;
}

//THIS fuction will store Chracter and 2 joker at radom place in array and ensure that both uppercase and loer case are genreated and storng at new index
//This will ensure each and everything
void characterPlacerInBoard(char array_to_populated[TOTAL_ROWS][TOTAL_COLUMNS]) {
    int row, columns;
    int isJokerPlaced = 0; // to keep track of gnretaed joker
    int chracter_placed = 0; // loop controler to check how many chracter we have grneate and stored in array
    int isLowerCasePlaced = 0; //flag to ensure that lower case of pervoluly placed uppercase is stored
    int upercase_to_placed = 'A'; // uperlimit for chracter genretatiom
    int lowercase_to_placed = 'a';// lower for chracter genretatiom
    int total_chracter_to_place = TOTAL_ROWS * TOTAL_COLUMNS - 2; // to tell who much time we have to run loop
    int is_already_populated[TOTAL_ROWS][TOTAL_COLUMNS] = {0}; // To track where we have stored chrcter

    while (chracter_placed < total_chracter_to_place) { // this will run untill we will pace 34 chracter
        isLowerCasePlaced = 0; // track/flag
        row = rand() % TOTAL_ROWS; // random row gnreater
        columns = rand() % TOTAL_COLUMNS; // random colunn gnreaer
        if (is_already_populated[row][columns] == 0) { // this will check if its populated
            array_to_populated[row][columns] = upercase_to_placed; // if not an chrater will be placed
            upercase_to_placed++; // uper limit will be inmcrased
            chracter_placed++; // this will tell we have p;laced one chracter
            is_already_populated[row][columns]++; // and will ivreate in location where chracter is stored i,e sperqare array for traking
            do {
                row = rand() % TOTAL_ROWS;
                columns = rand() % TOTAL_COLUMNS; // same fuction

                if (is_already_populated[row][columns] == 0) { // same work
                    array_to_populated[row][columns] = lowercase_to_placed; // will pace lower case
                    lowercase_to_placed++; // will incrase lower limit
                    chracter_placed++; // will keep reaord for how many chracter we have stored in array
                    is_already_populated[row][columns]++; // for tracking so we dont place one chjracter in same place
                    isLowerCasePlaced = 1; // flag to ensure lowre case is placed once
                }
            } while (!isLowerCasePlaced); // when it 0 it says that we have stored loeer case for gnreatering lower case
        }
    }

    while (isJokerPlaced < 2){ // saving two joker
        row = rand() % TOTAL_ROWS; // samw work
        columns = rand() % TOTAL_COLUMNS;
        if (is_already_populated[row][columns] == 0) { // will check if nothing is there
            array_to_populated[row][columns] = '*'; // will store 2 joker at emapty place in array
            is_already_populated[row][columns]++; //will keep track
            isJokerPlaced++; //will tell we have placed two jokers
        }
    }
    return;
}
 /* 
 The below array is for priting board to user
 */
void hashPrinter(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS]) {

    printf("Total Number Of Cards Revelead %d\n", total_cards_flipped );
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

//The below fuction will map colum,n sinace we tale column as alphabat from user
int columnMapper(char column) {
    switch (column) {
    case 'A': return 0;
    case 'B': return 1;
    case 'C': return 2;
    case 'D': return 3;
    case 'E': return 4;
    case 'F': return 5;
    case 'a': return 0;
    case 'b': return 1;
    case 'c': return 2;
    case 'd': return 3;
    case 'e': return 4;
    case 'f': return 5;
    default:  return -1;
    }
}

// will stored user card in hash array i e flip it
void revealedBoard(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS], char user_card, int selected_row, int selected_column){
    hash_array[selected_row][selected_column] = user_card;
}

 /*I have wirttrn this fuction to check eery possibilty that i can find*/
void firstTurn(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS], char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int row_1, int column_1, char first_card) {
    if (first_card == '*' && isJokerPlaced == 0 && total_cards_flipped == 34) { // if 2 jokers are not reveled and secomd input is joker
         printf("What a Luck!! You watch and chill\n");
    int isFound = 0;
    int i, j;
    
    for (i = 0; i < TOTAL_ROWS; i++) {
            for (j = 0; j < TOTAL_COLUMNS; j++) {
                if (main_array[i][j] == first_card ) {
                    hash_array[i][j] = main_array[i][j];
                    isFound = 1;
                    break;
                }
            }
            if (isFound) {
                break;
            }
           
        }
        if (isFound) {
         if (player_turn == 0) {
                score_player1+=2;
                total_cards_flipped = total_cards_flipped + 2;
                hashPrinter(hash_array);
                printf("You got two point\n");
                Sleep(2000);
                system("cls");
                hash_array[row_1][column_1] = ' ';
                hash_array[i][j] = ' ';
                main_array[row_1][column_1] = ' ';
                main_array[i][j] = ' ';
            } else if (player_turn == 1) {
               score_player1+=2;
                total_cards_flipped = total_cards_flipped + 2;
                hashPrinter(hash_array);
                printf("You got two point\n");
                Sleep(2000);
                system("cls");
                hash_array[row_1][column_1] = ' ';
                hash_array[i][j] = ' ';
                main_array[row_1][column_1] = ' ';
                main_array[i][j] = ' ';
                
            } 
            }

    } else if (isJokerPlaced == 1 && total_cards_flipped == 35 && first_card == '*' ) { // if one card is remaing and that is joker
        isJokerPlaced++;
        printf("Finally!!!!");
         if (player_turn == 0) {
                score_player1+=1;
                total_cards_flipped = total_cards_flipped + 1;
                hash_array[row_1][column_1] = ' ';
                main_array[row_1][column_1] = ' ';
                hashPrinter(hash_array);
                printf("You got one point\n");
                Sleep(2000);
                system("cls");
               
               
            } else if (player_turn == 1) {
               if (player_turn == 0) {
                score_player1+=1;
                total_cards_flipped = total_cards_flipped + 1;
                hash_array[row_1][column_1] = ' ';
                main_array[row_1][column_1] = ' ';
                hashPrinter(hash_array);
                printf("You got one point\n");
                Sleep(2000);
                system("cls");
                
            }
        }

    }
    else if (first_card == '*') { // if first card is joker
    printf("Joker Found!! We will find next pair for you\n");
    isJokerPlaced++;
        int random_row, random_column; // 2 temp variables

        do {
            random_row = rand() % TOTAL_ROWS;
            random_column = rand() % TOTAL_COLUMNS;
        } while (hash_array[random_row][random_column] == ' '); // ensure the selected card is not flipped before

        char first_card_selected = main_array[random_row][random_column]; // if not, then it's stored in a variable
        hash_array[random_row][random_column] = first_card_selected; // and printed to user

        int isFound = 0;
        int row, columns;

        if (first_card_selected >= 'A' && first_card_selected <= 'Q') { // if first card selected automatically when we get joker
            for (row = 0; row < TOTAL_ROWS; row++) {
                for (columns = 0; columns < TOTAL_COLUMNS; columns++) {
                    if (main_array[row][columns] - 32 == first_card_selected) {
                        hash_array[row][columns] = main_array[row][columns];
                        isFound = 1;
                        break;
                    }
                }
                if (isFound) {
                    break;
                }
            }
            if (isFound) { // if found
                scoreFirstCardIsJoker(hash_array, row_1, column_1, random_row, random_column, row, columns);
            }
        } else if (first_card_selected >= 'a' && first_card_selected <= 'q') {
            for (row = 0; row < TOTAL_ROWS; row++) {
                for (columns = 0; columns < TOTAL_COLUMNS; columns++) {
                    if (main_array[row][columns] + 32 == first_card_selected) {
                        hash_array[row][columns] = main_array[row][columns];
                        isFound = 1;
                        break;
                    }
                }
                if (isFound) {
                    break;
                }
            }
            if (isFound) { // if found
                scoreFirstCardIsJoker(hash_array, row_1, column_1, random_row, random_column, row, columns);
            }
        } else if (first_card_selected == '*') { // if slected card is also joker
            isJokerPlaced++;
            printf("2 joker!! What a luck now we will Find two Pairs for you\n");
            int row_0, column_0, row_2, column_2, row_3, column_3, row_4, column_4;
            char first_card_selected, second_card_selected, third_card_selected, fourth_card_selected;

            do {
                row_0 = rand() % TOTAL_ROWS;
                column_0 = rand() % TOTAL_COLUMNS;
                row_3 = rand() % TOTAL_ROWS;
                column_3 = rand() % TOTAL_COLUMNS;
            } while (hash_array[row_0][column_0] != ' ' && hash_array[row_3][column_3] != ' ');

            first_card_selected = main_array[row_0][column_0];
            third_card_selected = main_array[row_3][column_3];
            hash_array[row_0][column_0] = first_card_selected;
            hash_array[row_3][column_3] = third_card_selected;

            int isFirstFound = 0, isSecondFound = 0;

            if ((first_card_selected >= 'A' && first_card_selected <= 'Q') && (third_card_selected >= 'A' && third_card_selected <= 'Q')) {
                for (row_2 = 0; row_2 < TOTAL_ROWS; row_2++) {
                    for (column_2 = 0; column_2 < TOTAL_COLUMNS; column_2++) {
                        if (main_array[row_2][column_2] - 32 == first_card_selected) {
                            hash_array[row_2][column_2] = main_array[row_2][column_2];
                            isFirstFound = 1;
                            break;
                        }
                    }
                    if (isFirstFound) {
                        break;
                    }
                }

                for (row_4 = 0; row_4 < TOTAL_ROWS; row_4++) {
                    for (column_4 = 0; column_4 < TOTAL_COLUMNS; column_4++) {
                        if (main_array[row_4][column_4] - 32 == third_card_selected) {
                            hash_array[row_4][column_4] = main_array[row_4][column_4];
                            isSecondFound = 1;
                            break;
                        }
                    }
                    if (isSecondFound) {
                        break;
                    }
                }

                if (isFirstFound && isSecondFound) {
                    scoreSelectedCardIsAlsoJoker(main_array , row_1, column_1, random_row, random_column, row_0, column_0, row_2, column_2, row_3, column_3, row_4, column_4);                  
                }
            } else if ((first_card_selected >= 'a' && first_card_selected <= 'q') && (third_card_selected >= 'a' && third_card_selected <= 'q')) {
                for (row_2 = 0; row_2 < TOTAL_ROWS; row_2++) {
                    for (column_2 = 0; column_2 < TOTAL_COLUMNS; column_2++) {
                        if (main_array[row_2][column_2] + 32 == first_card_selected) {
                            hash_array[row_2][column_2] = main_array[row_2][column_2];
                            isFirstFound = 1;
                            break;
                        }
                    }
                    if (isFirstFound) {
                        break;
                    }
                }

                for (row_4 = 0; row_4 < TOTAL_ROWS; row_4++) {
                    for (column_4 = 0; column_4 < TOTAL_COLUMNS; column_4++) {
                        if (main_array[row_4][column_4] + 32 == third_card_selected) {
                            hash_array[row_4][column_4] = main_array[row_4][column_4];
                            isSecondFound = 1;
                            break;
                        }
                    }
                    if (isSecondFound) {
                        break;
                    }
                }

               if (isFirstFound && isSecondFound) {
                    scoreSelectedCardIsAlsoJoker(main_array , row_1, column_1, random_row, random_column, row_0, column_0, row_2, column_2, row_3, column_3, row_4, column_4);                  
                }
                 }
                   }
                    }
                    }

// fuction to handle second input
void boardChecker(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS], char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int row_1, int column_1, char player_card_1, int row_2, int column_2, char player_card_2, int cards_flipped) {
   if (total_cards_flipped == 32 && player_card_2 == '*' && isJokerPlaced == 0) {
    printf("What a Luck!! You watch and chill\n"); // if 2 cards are jokers and 2 are chracters user slected chrater as first input and joker as secod
    int isFound = 0, alsoFound = 0;
    int i, j, k, l;
    isJokerPlaced++;
    isJokerPlaced++;
    for (i = 0; i < TOTAL_ROWS; i++) {
            for (j = 0; j < TOTAL_COLUMNS; j++) {
                if (main_array[i][j] == player_card_2 ) {
                    hash_array[i][j] = main_array[i][j];
                    isFound = 1;
                    break;
                }
            }
            if (isFound) {
                break;
            }
        }
        if (isFound) {
       if (player_card_1 >= 'A' && player_card_1 <= 'Q') {      
    for (l = 0; l < TOTAL_ROWS; l++) {
            for (k = 0; k < TOTAL_COLUMNS; k++) {
                if (main_array[l][k] - 32 == player_card_1) {
                    hash_array[l][k] = main_array[i][j];
                    alsoFound = 1;
                    break;
                }
            }
            if (alsoFound) {
                break;
            }
        }  
        if(alsoFound) {
            scoreLastTwoCardsAreJoker(main_array, row_1, column_1, row_2, column_2, i, j, k, l);
        }
        } else if (player_card_1 >= 'a' && player_card_1 <= 'q') {
             for (l = 0; l < TOTAL_ROWS; l++) {
            for (k = 0; k < TOTAL_COLUMNS; k++) {
                if (main_array[l][k] + 32 == player_card_1) {
                    hash_array[l][k] = main_array[i][j];
                    alsoFound = 1;
                    break;
                }
            }
            if (alsoFound) {
                break;
            }
        }  
if(alsoFound) {
            scoreLastTwoCardsAreJoker(main_array, row_1, column_1, row_2, column_2, i, j, k, l);
        }
        }
        }
   }
   /*This will check is user secon card is joker tehn it will match first card and give user 2 points it will ehck both upper case and loer case*/
      else if (player_card_2 == '*') {
    isJokerPlaced++;
    int isFound = 0;
    int i, j;
    char genreater_card;
    printf("You landed on joker!! Great we will find second card for you\n");

    if (player_card_1 >= 'A' && player_card_1 <= 'Q') {
        for (i = 0; i < TOTAL_ROWS; i++) {
            for (j = 0; j < TOTAL_COLUMNS; j++) {
                if (main_array[i][j] - 32 == player_card_1) {
                    hash_array[i][j] = ' ';
                    genreater_card = main_array[i][j];
                    isFound = 1;
                    break;
                }
            }
            if (isFound) {
                break;
            }
        }
    } else if (player_card_1 >= 'a' && player_card_1 <= 'q') {
        for (i = 0; i < TOTAL_ROWS; i++) {
            for (j = 0; j < TOTAL_COLUMNS; j++) {
                if (main_array[i][j] + 32 == player_card_1) {
                    hash_array[i][j] = ' ';
                    genreater_card = main_array[i][j];
                    isFound = 1;
                    break;
                }
            }
            if (isFound) {
                break;
            }
        }
    }
if (isFound) {
        scoreSecondCardIsJoker(main_array, row_1, column_1, row_2, column_2, i, j, genreater_card);
       
    }
    
}
        /*This will check if user s=first car is upper case then will check subartcting 32 to cehck if they match nad rest is same i have explaied upper*/
         else if (player_card_1 >= 'A' && player_card_1 <= 'Q') {
        if (player_card_1 == (player_card_2 - 32)) {
           scoreSecondCardIsMatched(main_array, row_1, column_1, row_2, column_2);
        } else if (player_card_2 != player_card_1 - 32)  {
            iFCardsAreNotMtached(row_1, column_1, row_2, column_2);
            
        }
         /*This will check if user s=first car is loer case then will check addimg 32 to cehck if they match nad rest is same i have explaied upper*/
    } else if (player_card_1 >= 'a' && player_card_1 <= 'q') {
        if (player_card_1 == (player_card_2 + 32)) {
           scoreSecondCardIsMatched(main_array, row_1, column_1, row_2, column_2);
        } else if (player_card_2 != player_card_1 + 32)
            iFCardsAreNotMtached(row_1, column_1, row_2, column_2);
            
    } 
}

//MAIN fuction (execution point)
int main(void) {
    char user_choice = 'N';
    // this loop is to ask user if they want to play again
    do {  
    // All varibles that will be used in program
    char board_contents[TOTAL_ROWS][TOTAL_COLUMNS];
    
    // store user user input on first and second tuen
    int selected_row_1;
    char selected_column_1;
    int mapped_column_1;
    int selected_row_2;
    char selected_column_2;
    int mapped_column_2;

    // to store user cards on 2 turns
    char first_card, second_card;

    
// poplated has array with hash
    for (int i = 0; i < TOTAL_ROWS; i++)  {
        for (int j = 0; j < TOTAL_ROWS; j++) {
            hash_array[i][j] = '#';
        }
    }
    //set random valuw that  is os current time set for rand() fuction
    srand(time(NULL));
    //will choose random  player
    playerChooser();
    // will store chracter and jokers at ramdom loation in array will check if chreacter is placed that loation before or not
    // This will ensure that both upper case and lower case are placed
    characterPlacerInBoard(board_contents);
    
    // for testing if you want to see main baord decomment it
    // hashPrinter(board_contents);
   int turn = 0;

   // This loop will run until all cards are macthed and jokers are reveld
   while (total_cards_flipped < TOTAL_ROWS * TOTAL_COLUMNS) {  
        turn = 0;
             while (turn < 2) {
                do {
                    hashPrinter(hash_array); // will print board
                    printf("Player %d: Enter a coordinate (e.g. B4 )\n", player_turn + 1);
                    scanf(" %c%d", &selected_column_1, &selected_row_1);
                    mapped_column_1 = columnMapper(selected_column_1); // will map colum,n
                    if (hash_array[selected_row_1][mapped_column_1] == ' ') { // if user coorindate is reveld and flipped it will tell that
                        printf("Card on selcted coordinate have been revelead before\nChoose another coordinate:\n");
                    } else if ((selected_row_1 >= 0 && selected_row_1 <= 5) && (mapped_column_1 >= 0 && mapped_column_1 <= 5)) { // if not then will take input and will flip and heck if its joker or not
                        first_card = board_contents[selected_row_1][mapped_column_1];
                        revealedBoard(hash_array, first_card, selected_row_1, mapped_column_1);
                        srand(time(NULL));
                        firstTurn(hash_array, board_contents, selected_row_1, mapped_column_1, first_card);
                        turn++; // the will update tun
                     // to stop bug if firdt s card is joker break loop
                         if (first_card == '*') {
                        system("cls");
                        turn++;
                        break;
                      }
                       
                    } else if ((selected_row_1 < 0 || selected_row_1 > 5) || (mapped_column_1 < 0 || mapped_column_1 > 5))
                    { if ((selected_row_1 < 0 || selected_row_1 > 5)) { // tis will tell user what wring they have enretd
                            printf("You entered wrong row from board\n");
                    } else if ((mapped_column_1 < 0 || mapped_column_1 > 5)) {
                            printf("You entered wrong column from board\n");
                     }
                    } 
                } while ((selected_row_1 < 0 || selected_row_1 > 5) || (mapped_column_1 < 0 || mapped_column_1 > 5) || (hash_array[selected_row_1][mapped_column_1] == ' ')); // this will ensure user dont gacve inavcalid input
                // to stop bug if firdt s card is joker break loop
                do {
                     if (first_card == '*') {
                        system("cls");
                        break;
                      }
                    hashPrinter(hash_array);// same
                    printf("Player %d: Enter a coordinate (e.g. B4 )\n", player_turn + 1);
                    scanf(" %c%d", &selected_column_2, &selected_row_2);
                    mapped_column_2 = columnMapper(selected_column_2); // will map clolun index

                    // will check if user box is reveld before or same box did he choosed on first input
                    if (hash_array[selected_row_2][mapped_column_2] == ' ' || hash_array[selected_row_2][mapped_column_2] == first_card) {
                      if (hash_array[selected_row_2][mapped_column_2] == ' ') { 
                        printf("Card on selected coordinate have been revelead before\nChoose another coordinate:\n");
                      } else if ( hash_array[selected_row_2][mapped_column_2] == first_card) {
                        printf("You have selected same card, Please select another card\n");
                      }               
                    } else if ((selected_row_2 >= 0 && selected_row_2 <= 5) && (mapped_column_2 >= 0 && mapped_column_2 <= 5)) {
                        second_card = board_contents[selected_row_2][mapped_column_2];
                        revealedBoard(hash_array, second_card, selected_row_2, mapped_column_2);
                        srand(time(NULL));
                        boardChecker(hash_array, board_contents, selected_row_1, mapped_column_1, first_card, selected_row_2, mapped_column_2, second_card, total_cards_flipped);
                        turn++;
                        // to stop bug if seconf card is joker or have been mactched break loop
                         if (second_card == '*') {
                        system("cls");
                        break;
                      }
                       else if (second_card == first_card + 32 || second_card == first_card - 32 ) {
                        system("cls");
                        break;
                      } 
                        // all below same
                    } else if ((selected_row_2 < 0 || selected_row_2 > 5) || (mapped_column_2 < 0 || mapped_column_2 > 5))
                    {
                        if ((selected_row_2 < 0 || selected_row_2 > 5))  {
                            printf("You entered wrong row from board\n");
                        }  else if ((mapped_column_2 < 0 || mapped_column_2 > 5))  {
                            printf("You entered wrong column from board\n");
                        }
                    }
                } while ((selected_row_2 < 0 || selected_row_2 > 5) || (mapped_column_2 < 0 || mapped_column_2 > 5) || (hash_array[selected_row_2][mapped_column_2] == ' ') || ((selected_row_2 == selected_row_1) &&  (mapped_column_2 == mapped_column_1 )));
         } 
    }
    if (score_player1 > score_player2) {
        printf("Congrulations Player 1 !!! You won this game, Your score is: %d and your oppoent score is: %d\n", score_player1, score_player2);
    } else if (score_player2 > score_player1) {
        printf("Congrulations Player 2 !!! You won this game, Your score is: %d and your oppoent score is: %d\n", score_player2, score_player1);
    } else if (score_player1 == score_player2) {
        printf("Wow!!! What a game, You both played well, We have a TIE\n");
    } 
    // uoer code will tell user if they have won or macyh is tried
      printf("Hmmmm!!!!Do you want another game? (Y/N Defult N)"); // this ask user if thy want tp play again
      scanf(" %c", &user_choice);
      score_player1 = 0;
      score_player2 = 0;
      total_cards_flipped = 0;
      player_turn = rand() % TOTAL_PLAYERS;
  

    } while (user_choice == 'y' || user_choice == 'Y'  );
    return 0;
}
