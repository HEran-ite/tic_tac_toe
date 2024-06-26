#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char player = 'X';
const char computer = 'O';

void reset();
void printBoard();
int freeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main() {
    char winner = ' ';

    reset();

    while (winner == ' ' && freeSpaces () != 0) {
        printBoard();

         playerMove();

        winner=checkWinner();
        if (winner != ' ' || freeSpaces () ==0) {
            break;
        };

        computerMove();

        winner=checkWinner();
        if (winner != ' ' || freeSpaces () ==0) {
            break;
    };
    };

   

    printBoard();

    printWinner(winner);
    return 0;
}

void reset() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf(" %c    |   %c   |  %c\n", board[0][0], board[0][1], board[0][2]);
    printf("- - - | - - - | - - -\n");
    printf(" %c    |   %c   |  %c\n", board[1][0], board[1][1], board[1][2]);
    printf("- - - | - - - | - - -\n");
    printf(" %c    |   %c   |  %c\n", board[2][0], board[2][1], board[2][2]);
}

int freeSpaces(){
    int freeSpaces = 9;
    for (int i =0 ; i < 3 ; i++){
        for (int j=0 ; j < 3 ; j++ ) {
            if (board[i][j]!=' '){
                freeSpaces--;
            }
            
        }
    }
    return freeSpaces;

}

void playerMove(){
    int x;
    int y ;

    do {

    printf("Enter row (1-3) :");
    scanf("%d",&x);
    x--;
    
    printf("Enter column (1-3) :");
    scanf("%d",&y);
    y--;

    if (board[x][y]!= ' '){
        printf("The space is already taken.");
    }

    else {
        board[x][y] = player ;
        break;
    }

    } while (board[x][y]!= ' ');
    
    

}

void computerMove(){
    srand(time(0));
    int x;
    int y ;

    if (freeSpaces() > 0){
        do {
            x = rand() % 3;
            y = rand() % 3; 
        } while (board[x][y] != ' ');

        board[x][y] = computer;
    }
}

char checkWinner(){
    for (int i=0 ; i < 3 ; i ++){
        if (board[i][0]== board[i][1] && board[i][1] == board[i][2] ){
            return board [i][0];
        }

    };

    for (int i=0 ; i < 3 ; i ++){
        if (board[0][i]== board[1][i] && board[1][i] == board[2][i] ){
            return board [0][i];
        }

    };

    if (board[0][0]== board[1][1] && board[1][1] == board[2][2] ) {

        return board[0][0];
    };

    if (board[0][2]== board[1][1] && board[1][1] == board[2][0] ) {

        return board[0][2];
    };
    
    return ' ';

}

void printWinner(char winner){

    if (checkWinner() == player) {
        printf("You Win!!!");
    }

    else if (checkWinner() == computer) {
        printf("You lose.");
    }

    else {
        printf("It is a draw.");
    }
}