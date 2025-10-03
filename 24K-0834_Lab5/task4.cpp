#include <iostream>
using namespace std;

#define MAX 20
int board[MAX][MAX];
int N;
int solutionCount = 0;


void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int row, int col) {
    int i, j;

    for (i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

void solveNQ(int row) {
    if (row == N) {
        solutionCount++;
        if (solutionCount == 1) {
            cout << "One valid board configuration:\n";
            printBoard();
        }
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;
            solveNQ(row + 1);
            board[row][col] = 0;
        }
    }
}

int main() {
    cout << "Enter the value of N (size of board): ";
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    solveNQ(0);

    cout << "Total number of distinct solutions for N = " << N << " is " << solutionCount << endl;

    return 0;
}
