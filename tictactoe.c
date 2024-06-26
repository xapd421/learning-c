#include <stdio.h>

#define true 1
#define false 0

#define LENGTH 3

int main(void) {
    int board[LENGTH][LENGTH] = {0};
    int player = 1;
    int winner = 0;
    int turns = 0;

    while (winner == 0 && turns < LENGTH * LENGTH) {
        // next turn
        printf("Player %d's Turn (%c)\n", player, player == 1 ? 'X': 'O');

        // choose square
        while (true) {
            int x, y;
            printf("Choose a square (x, y): ");
            scanf("%d ,%d", &x, &y);
            if (board[x][y] != 0) {
                printf("This square is taken. Please try again.\n");
            } else {
                board[x][y] = player == 1 ? 1 : 2;
                break;
            }
        }

        // print board
        for (int row = 0; row < LENGTH; row++) {
            for (int col = 0; col < LENGTH; col++) {
                if (board[row][col] == 0) { // print empty space
                    printf("%4c", '_');
                } else { // print X's and O's
                    char letter = board[row][col] == 1 ? 'X' : 'O'; 
                    printf("%4c", letter);
                }
            }
            printf("\n");
        }

        // win conditions
        // horizontal
        if ((board[0][0] == board[0][1]) && (board[0][1] == board[0][2])) {
            if (board[0][0] == 0) goto next;
            winner = board[0][0];
        }
        else if ((board[1][0] == board[1][1]) && (board[1][1] == board[1][2])) {
            if (board[1][0] == 0) goto next;
            winner = board[1][0];
        }
        else if ((board[2][0] == board[2][1]) && (board[2][1] == board[2][2])) {
            if (board[2][0] == 0) goto next;
            winner = board[2][0];
        }

        // vertical
        else if ((board[0][0] == board[1][0]) && (board[1][0] == board[2][0])) {
            if (board[0][0] == 0) goto next;
            winner = board[0][0];
        }
        else if ((board[0][1] == board[1][1]) && (board[1][1] == board[2][1])) {
            if (board[0][1] == 0) goto next;
            winner = board[0][1];
        }
        else if ((board[0][2] == board[1][2]) && (board[1][2] == board[2][2])) {
            if (board[0][2] == 0) goto next;
            winner = board[0][2];
        }

        // diagonal
        else if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2])) {
            if (board[0][0] == 0) goto next;
            winner = board[0][0];
        }
        else if ((board[2][0] == board[1][1]) && (board[1][1] == board[0][2])) {
            if (board[2][0] == 0) goto next;
            winner = board[2][0];
        }

        // change turns
        next:
        player = player == 1 ? 2 : 1;
        turns++;
    }

    // announce results
    if (winner != 0) {
        printf("Player %d Won!\n", winner == 1 ? 1 : 2);
    } else {
        printf("Draw\n");
    }

    return 0;
}