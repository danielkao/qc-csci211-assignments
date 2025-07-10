#include <iostream>
using namespace std;

int main()
{
    int board[8][8] = {0};
    int c = 0, r = 0, solution = 1;
    
    nextCol:
        if (c == 8) goto print;
        r = -1;
    nextRow:
        r++;
        if (r == 8) goto backtrack;
        for (int i = 0; i < c; i++) { // Check if the spot is valid
            for (int j = 0; j < 8; j++) {
                if (board[j][i] == 1) { // If a queen exists at (j, i)
                    if (j == r || abs(j - r) == abs(i - c)) goto nextRow; 
                }
            }
        }

    board[r][c] = 1; // Place queen
    c++; // Move to the next column
    goto nextCol;
    backtrack:
        c--;
        if (c == -1) return 0; // If backtracked past the first column, exit
        
        for (int i = 0; i < 8; i++) { // Find the old queen and remove it
            if (board[i][c] == 1) {
                board[i][c] = 0;
                r = i;
                goto nextRow; // Go to the next row and try again.
            }
        }
        
    print:
        cout << "Solution #" << solution++ << ":\n";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << (board[i][j] == 1 ? "1 " : "0 ");
        }
        cout << endl;
    }
    cout << endl;
    
    goto backtrack; // Find next solution
}

