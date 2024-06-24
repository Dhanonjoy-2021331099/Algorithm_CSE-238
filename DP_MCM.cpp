// Matrix chain multiplication

#include <bits/stdc++.h>
using namespace std;

// Function to print the optimal parenthesization
void insertBracket(int s[][20], int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        insertBracket(s, i, s[i][j]);
        insertBracket(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    int n;
    cout << "Enter Number of Dimension: ";
    cin >> n;

    cout << "Enter dimension: ";
    int p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];

    int m[20][20] = {0}; // Updated to use a fixed size large enough
    int s[20][20] = {0}; // Updated to use a fixed size large enough

    int j, q, minCost;

    for (int d = 1; d < n - 1; d++) {
        for (int i = 1; i < n - d; i++) {
            j = i + d;
            minCost = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < minCost) {
                    minCost = q;
                    s[i][j] = k;
                }
            }
            m[i][j] = minCost;
        }
    }

    // Matrix Print
    cout << "M matrix: " << endl;
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    cout << "S matrix: " << endl;
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Minimum cost/multiplication = " << m[1][n - 1] << endl;
    cout << "K = " << s[1][n - 1] << endl;

    // Print the optimal parenthesization
    cout << "Optimal parenthesization: ";
    insertBracket(s, 1, n - 1);
    cout << endl;

    return 0;
}

