#include<bits/stdc++.h>
using namespace std;

vector<int> x; // Global array to store positions of queens

bool Place(int k, int i) {
    for (int j = 1; j < k; ++j) {
        if (x[j] == i || abs(x[j] - i) == abs(j - k)) {
            return false;
        }
    }
    return true;
}

void printSolution(int n) {
    vector<vector<char>> board(n, vector<char>(n, '*'));
    for (int i = 1; i <= n; ++i) {
        board[i - 1][x[i] - 1] = 'Q';
    }
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void NQueens(int k, int n) {
    for (int i = 1; i <= n; ++i) {
        if (Place(k, i)) {
            x[k] = i;
            if (k == n) {
                printSolution(n);
            } else {
                NQueens(k + 1, n);
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    x.resize(n + 1); // Resize x to hold positions for n queens
    NQueens(1, n);
    return 0;
}

