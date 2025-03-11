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

int game_ender[TOTAL_ROWS][TOTAL_COLUMNS] = {0}; // THIS WILL CHECK if 3 cards are emaing and one is joker




// Fuctions prototype, that will be explained next in program when we will define that fuctions
// Since i have all prototype i will do defination of fuction below main so code is easily readile
void playerChooser();
void characterPlacerInBoard(char array_to_populated[TOTAL_ROWS][TOTAL_COLUMNS]);
int columnMapper(char column);
void hashPrinter(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS]);
void firstTurn(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS], char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int row_1, int column_1, char first_card);
void boardChecker(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS], char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int row_1, int column_1, char player_card_1, int row_2, int column_2, char player_card_2, int cards_flipped);
void revealedBoard(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS], char user_card, int selected_row, int selected_column);
 

// This function will chose player raddom
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


// will stored user card in hash array i e flip it
void revealedBoard(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS], char user_card, int selected_row, int selected_column){
    hash_array[selected_row][selected_column] = user_card;
}

 /*I have wirttrn this fuction to check eery possibilty that i can find*/
void firstTurn(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS], char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int row_1, int column_1, char first_card) {
    if (first_card == '*') { // if first card is joker
        int random_row, random_column; // 2 temp varibales

        do {
            random_row = rand() % TOTAL_ROWS;
            random_column = rand() % TOTAL_COLUMNS;
        } while (hash_array[random_row][random_column] == ' '); // will ensure their slected card is not flipped before

        char first_card_selected = main_array[random_row][random_column]; // if not then its will be tsord in an vrobale
        hashPrinter(hash_array); // and will print to user
        char second_card; // to find secnd card 

        if (first_card_selected >= 'A' && first_card_selected <= 'Q') { // if first card that is lsected aumtaiclly when we got joker will be check its case
            do {
                int row, columns;
                do {
                    row = rand() % TOTAL_ROWS;
                    columns = rand() % TOTAL_COLUMNS;
                } while (hash_array[row][columns] == ' '); // if upper then we will check if 32 minys from that seocnd card is equla to first card

                second_card = main_array[row][columns];
                if (first_card_selected == (second_card - 32)) { // if yes
                    if (player_turn == 0) { // players will be given points on their turn
                        score_player1 += 2;
                        total_cards_flipped += 3; // will track that how many cards we have flipped this wll jhelp to end program
                        hashPrinter(hash_array); // will print
                        Sleep(2000); //pause execyation
                        hash_array[row_1][column_1] = ' '; // will cgnage that card so user will se that this card have benn macthed and flipped
                        hash_array[random_row][random_column] = ' ';
                        hash_array[row][columns] = ' ';
                        system("cls"); // clear sscreen
                    } else if (player_turn == 1) { // its same i have check that which player have tuern
                        score_player2 += 2;
                        total_cards_flipped += 3;
                        hashPrinter(hash_array);
                        Sleep(2000);
                        hash_array[row_1][column_1] = ' ';
                        hash_array[random_row][random_column] = ' ';
                        hash_array[row][columns] = ' ';
                        system("cls");
                    }
                }
            } while (first_card_selected != (second_card - 32)); // this will run until both are matched
        } else if (first_card_selected >= 'a' && first_card_selected <= 'q') { // this will check if first card slcted is lower case


        /*If its loer case then we will add 32 in seind card to check if both are same if yes same logic that i havce edplaned in upper potion difernce is that first 
        one was for upper case this is for loere case*/
            do {
                int row, columns;
                do {
                    row = rand() % TOTAL_ROWS;
                    columns = rand() % TOTAL_COLUMNS;
                } while (hash_array[row][columns] == ' ');

                second_card = main_array[row][columns];
                if (first_card_selected == (second_card + 32)) {
                    if (player_turn == 0) {
                        score_player1 += 2;
                        total_cards_flipped += 3;
                        hashPrinter(hash_array);
                        Sleep(2000);
                        hash_array[row_1][column_1] = ' ';
                        hash_array[random_row][random_column] = ' ';
                        hash_array[row][columns] = ' ';
                        system("cls");
                    } else if (player_turn == 1) {
                        score_player2 += 2;
                        total_cards_flipped += 3;
                        hashPrinter(hash_array);
                        Sleep(2000);
                        hash_array[row_1][column_1] = ' ';
                        hash_array[random_row][random_column] = ' ';
                        hash_array[row][columns] = ' ';
                        system("cls");
                    }
                }
            } while (first_card_selected != (second_card + 32));
            /*This will chek if first card and ramdon card is joker this is raer if it occuers then user will get 2 points plus t boimus plus t
            pair flipped and fuctinality is same*/
        } else if (first_card_selected == '*') {
            int row_0, column_0, row_2, column_2, row_3, column_3, row_4, column_4;
            char first_card_selected, second_card_selected, third_card_selected, fourth_card_selected;

            do {
                row_0 = rand() % TOTAL_ROWS;
                column_0 = rand() % TOTAL_COLUMNS;
                row_2 = rand() % TOTAL_ROWS;
                column_2 = rand() % TOTAL_COLUMNS;
                row_3 = rand() % TOTAL_ROWS;
                column_3 = rand() % TOTAL_COLUMNS;
                row_4 = rand() % TOTAL_ROWS;
                column_4 = rand() % TOTAL_COLUMNS;
            } while (hash_array[row_0][column_0] != ' ' && hash_array[row_2][column_2] != ' ' && hash_array[row_3][column_3] != ' ' && hash_array[row_4][column_4] != ' ');

            first_card_selected = main_array[row_0][column_0];
            second_card_selected = main_array[row_2][column_2];
            third_card_selected = main_array[row_3][column_3];
            fourth_card_selected = main_array[row_4][column_4];

            if ((first_card_selected >= 'A' && first_card_selected <= 'Q') && (third_card_selected >= 'A' && third_card_selected <= 'Q')) {
                if (first_card_selected == (second_card_selected - 32) && third_card_selected == (fourth_card_selected - 32)) {
                    do {
                        if (player_turn == 0) {
                            score_player1 += 4;
                            total_cards_flipped += 6;
                            hashPrinter(hash_array);
                            Sleep(2000);
                            hash_array[row_1][column_1] = ' ';
                            hash_array[random_row][random_column] = ' ';
                            hash_array[row_0][column_0] = ' ';
                            hash_array[row_2][column_2] = ' ';
                            hash_array[row_3][column_3] = ' ';
                            hash_array[row_4][column_4] = ' ';
                        } else if (player_turn == 1) {
                            score_player2 += 4;
                            total_cards_flipped += 6;
                            hashPrinter(hash_array);
                            Sleep(2000);
                            hash_array[row_1][column_1] = ' ';
                            hash_array[random_row][random_column] = ' ';
                            hash_array[row_0][column_0] = ' ';
                            hash_array[row_2][column_2] = ' ';
                            hash_array[row_3][column_3] = ' ';
                            hash_array[row_4][column_4] = ' ';
                            system("cls");
                        }
                    } while (first_card_selected != (second_card_selected - 32) && third_card_selected != (fourth_card_selected - 32));
                }
            } else if ((first_card_selected >= 'a' && first_card_selected <= 'q') && (third_card_selected >= 'a' && third_card_selected <= 'q')) {
                if (first_card_selected == (second_card_selected + 32) && third_card_selected == (fourth_card_selected + 32)) {
                    do {
                        if (player_turn == 0) {
                            score_player1 += 4;
                            total_cards_flipped += 6;
                            hashPrinter(hash_array);
                            Sleep(2000);
                            hash_array[row_1][column_1] = ' ';
                            hash_array[random_row][random_column] = ' ';
                            hash_array[row_0][column_0] = ' ';
                            hash_array[row_2][column_2] = ' ';
                            hash_array[row_3][column_3] = ' ';
                            hash_array[row_4][column_4] = ' ';
                        } else if (player_turn == 1) {
                            score_player2 += 4;
                            total_cards_flipped += 6;
                            hashPrinter(hash_array);
                            Sleep(2000);
                            hash_array[row_1][column_1] = ' ';
                            hash_array[random_row][random_column] = ' ';
                            hash_array[row_0][column_0] = ' ';
                            hash_array[row_2][column_2] = ' ';
                            hash_array[row_3][column_3] = ' ';
                            hash_array[row_4][column_4] = ' ';
                            system("cls");
                        }
                    } while (first_card_selected != (second_card_selected + 32) && third_card_selected != (fourth_card_selected + 32));
                }
            }
        }
    }
}


void boardChecker(char hash_array[TOTAL_ROWS][TOTAL_COLUMNS], char main_array[TOTAL_ROWS][TOTAL_COLUMNS], int row_1, int column_1, char player_card_1, int row_2, int column_2, char player_card_2, int cards_flipped) {
   


   /*This will check is user secon card is joker tehn it will match first card and give user 2 points it will ehck both upper case and loer case*/
    if (player_card_2 == '*') {
    int isFound = 0;
    int i, j;
    printf("You landed on joker!! Great we will find second card for you\n");

    if (player_card_1 >= 'A' && player_card_1 <= 'Q') {
        for (i = 0; i < TOTAL_ROWS; i++) {
            for (j = 0; j < TOTAL_COLUMNS; j++) {
                if (main_array[i][j] - 32 == player_card_1) {
                    hash_array[i][j] = ' ';
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
        if (player_turn == 0) {
            score_player1 += 2;
            cards_flipped = cards_flipped + 3;
            hash_array[i][j] = main_array[i][j];
             system("cls");
            hashPrinter(hash_array);
            hash_array[i][j] = ' ';
            hash_array[row_1][column_1] = ' ';
            hash_array[row_2][column_2] = ' ';
            Sleep(2000);
        } else if (player_turn == 1) {
            score_player2 += 2;
            cards_flipped = cards_flipped + 3;
            hash_array[i][j] = main_array[i][j];
            hashPrinter(hash_array);
            Sleep(2000);
            hash_array[i][j] = ' ';
            hash_array[row_1][column_1] = ' ';
            hash_array[row_2][column_2] = ' ';
            
            system("cls");
        }
    }
}

        /*This will check if user s=first car is upper case then will check subartcting 32 to cehck if they match nad rest is same i have explaied upper*/
       else if (player_card_1 >= 'A' && player_card_1 <= 'Q') {
        if (player_card_1 == (player_card_2 - 32)) {
            if (player_turn == 0) {
                score_player1++;
                cards_flipped = cards_flipped + 2;
                hash_array[row_1][column_1] = ' ';
                hash_array[row_2][column_2] = ' ';
                hashPrinter(hash_array);
                Sleep(2000);
                system("cls");
            } else if (player_turn == 1) {
                score_player2++;
                cards_flipped = cards_flipped + 2;
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
         /*This will check if user s=first car is loer case then will check addimg 32 to cehck if they match nad rest is same i have explaied upper*/
    } else if (player_card_1 >= 'a' && player_card_1 <= 'q') {
        if (player_card_1 == (player_card_2 + 32)) {
            if (player_turn == 0) {
                score_player1++;
                cards_flipped = cards_flipped + 2;
                hash_array[row_1][column_1] = ' ';
                hash_array[row_2][column_2] = ' ';
                hashPrinter(hash_array);
                Sleep(2000);
                system("cls");
            } else if (player_turn == 1) {
                score_player2++;
                cards_flipped = cards_flipped + 2;
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
    } 
}

//MAIN fuction (execution point)
int main(void) {
    char user_choice = 'N';
    // this loop is to ask user if they want to play again
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
    
// poplated has array with hash
    for (int i = 0; i < TOTAL_ROWS; i++)  {
        for (int j = 0; j < TOTAL_ROWS; j++) {
            hash_array[i][j] = '#';
        }
    }
    //set rand time that os current time is
    srand(time(NULL));
    //will choose player
    playerChooser();
    // will store chracter in array 
    characterPlacerInBoard(board_contents);
    // first loop will run until alll cards are flipped
    hashPrinter(board_contents);
    do {
        int turn = 0;
        // this loop will run 2 times because eacher user has two tuen
        if (player_turn == 0) { // will check player tuen
            do {
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
                       
                    } else if ((selected_row_1 < 0 || selected_row_1 > 5) || (mapped_column_1 < 0 || mapped_column_1 > 5))
                    { if ((selected_row_1 < 0 || selected_row_1 > 5)) { // tis will tell user what wring they have enretd
                            printf("You entered wrong row from board\n");
                    } else if ((mapped_column_1 < 0 || mapped_column_1 > 5)) {
                            printf("You entered wrong column from board\n");
                     }
                    } 
                } while ((selected_row_1 < 0 || selected_row_1 > 5) || (mapped_column_1 < 0 || mapped_column_1 > 5) || (hash_array[selected_row_1][mapped_column_1] == ' ')); // this will ensure user dont gacve inavcalid input
                 if (first_card == '*') { // this wll ensure that if its joler this loop start and that user agaibn get chnace ie star  gain boinys turn
                            system("cls");
                            break;
                        }
                do {
                    hashPrinter(hash_array);// same
                    printf("Player %d: Enter a coordinate (e.g. B4 )\n", player_turn + 1);
                    scanf(" %c%d", &selected_column_2, &selected_row_2);
                    mapped_column_2 = columnMapper(selected_column_2); // will map clolun index
                    if (hash_array[selected_row_2][mapped_column_2] == ' ') {
                        printf("Card on selcted coordinate have been revelead before\nChoose another coordinate:\n");
                    } else if ((selected_row_2 >= 0 && selected_row_2 <= 5) && (mapped_column_2 >= 0 && mapped_column_2 <= 5)) {
                        second_card = board_contents[selected_row_2][mapped_column_2];
                        revealedBoard(hash_array, second_card, selected_row_2, mapped_column_2);

                        // this will check if user card are same then flip if not selpp for 32 sec clear screem
                        srand(time(NULL));
                        boardChecker(hash_array, board_contents, selected_row_1, mapped_column_1, first_card, selected_row_2, mapped_column_2, second_card, total_cards_flipped);
                        turn++;
                      if (second_card == '*') {
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
                } while ((selected_row_2 < 0 || selected_row_2 > 5) || (mapped_column_2 < 0 || mapped_column_2 > 5) || (hash_array[selected_row_2][mapped_column_2] == ' ') );
            } while (turn != 2);

            //everthing is same like upper just it will do that for plyer 2
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
                        srand(time(NULL));
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
                if (first_card == '*') { // this wll ensure that if its joler this loop start and that user agaibn get chnace ie star  gain boinys turn
                           system("cls");
                            break;
                        }
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
                        srand(time(NULL));
                        boardChecker(hash_array, board_contents, selected_row_1, mapped_column_1, first_card, selected_row_2, mapped_column_2, second_card, total_cards_flipped);
                        turn++;
                        if (second_card == '*') {
                            system("cls");
                        break;
                      }
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
    } while (total_cards_flipped != (TOTAL_ROWS * TOTAL_COLUMNS)); // this will cehck if all cards are flipped

    if (score_player1 > score_player2) {
        printf("Congrulations Player 1 !!! You won this game, Your score is: %d and your oppoent score is: %d\nYour have strong GUT feelings", score_player1, score_player2);
    } else if (score_player2 > score_player1) {
        printf("Congrulations Player 2 !!! You won this game, Your score is: %d and your oppoent score is: %d\nYour have strong GUT feelings", score_player2, score_player1);
    } else if (score_player1 == score_player2) {
        printf("Wow!!! What a game, You both played well, We have a TIE\n");
    } 
    // uoer code will tell user if they have won or macyh is tried
     
      printf("Hmmmm!!!!Do you want another game? (Y/N Defult N)"); // this ask user if thy want tp play again
      scanf(" %c", &user_choice);
  

    } while (user_choice == 'y' || user_choice == 'Y'  );
    return 0;
}
