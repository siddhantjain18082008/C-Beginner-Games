#include <stdio.h>           // printf/scanf
#include <stdbool.h>         // true/false

// 2D ARRAY: 3x3 grid = tic-tac-toe board
// '1'-'9' = empty positions players pick
char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};

void drawBoard() {
    printf("\n");
    // LOOP prints board rows
    for(int row=0; row<3; row++) {  // row = 0,1,2
        printf(" %c | %c | %c ", board[row][0], board[row][1], board[row][2]);
        if(row != 2) printf("\n---|---|---\n");  // No line under last row
    }
    printf("\n");
}

bool checkWin(char player) {  // player = 'X' or 'O'
    // CHECK ROWS: All 3 same = win
    for(int i=0; i<3; i++) {
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player) 
            return true;
    }
    
    // CHECK COLUMNS: All 3 same vertically
    for(int i=0; i<3; i++) {
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player) 
            return true;
    }
    
    // DIAGONALS
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player) return true;
    if(board[0][2]==player && board[1][1]==player && board[2][0]==player) return true;
    
    return false;  // No win found
}

int main() {
    char current = 'X';  // X starts
    int row, col, choice;
    
    printf("TIC TAC TOE\n");
    drawBoard();
    
    // 9 MAX MOVES (3x3 board)
    for(int moves=0; moves<9; moves++) {
        printf("Player %c, pick position 1-9: ", current);
        scanf("%d", &choice);
        
        // MATH: Convert 1-9 to row/col
        // 1→row0col0, 2→row0col1, 5→row1col1
        row = (choice-1) / 3;  // Integer division
        col = (choice-1) % 3;  // Modulo remainder
        
        // VALIDATE: Position empty? (still shows '1'-'9')
        if(board[row][col] >= '1' && board[row][col] <= '9') {
            board[row][col] = current;  // Place X or O
            drawBoard();
            
            // WIN CHECK after every move
            if(checkWin(current)) {
                printf("Player %c WINS!\n", current);
                return 0;
            }
            
            // SWITCH PLAYERS
            current = (current=='X') ? 'O' : 'X';
        } else {
            printf("Invalid position!\n");
            moves--;  // Don't count bad moves
        }
    }
    printf("DRAW! Board full.\n");
    return 0;
}
