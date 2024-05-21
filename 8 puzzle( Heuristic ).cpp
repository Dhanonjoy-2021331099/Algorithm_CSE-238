#include <bits/stdc++.h>
using namespace std;


// matrix print
void Disply(const array<int, 9>& matrix) {
    for (int i = 0; i < 9; ++i) {
        if (i % 3 == 0 && i > 0) {
            cout << endl;
        }
        cout << matrix[i] << " ";
    }
    cout << endl;
}

// Heuristic Value Count
int count(const array<int, 9>& s) {
    int c = 0;
    array<int, 9> ideal = {1, 2, 3, 4, 5, 6, 7, 8, 0};

    for (int i = 0; i < 9; ++i) {
        if (s[i] != 0 && s[i] != ideal[i]) {
            c++;
        }
    }
    return c;
}

pair<array<int, 9>, int>
move(const vector<int>& ar,  int p,  const array<int, 9>& st) {
    int rh = INT_MAX;
    array<int, 9> store_st = st;

    for (int i : ar) {
        array<int, 9> dupl_st = st;

        swap(dupl_st[p] , dupl_st[i]);

        int trh = count(dupl_st);

        if (trh < rh) {
            rh = trh;
            store_st = dupl_st;
        }
    }
    return make_pair(store_st, rh);
}

int main() {
    array<int, 9> state = {1, 2, 3, 0, 4, 6, 7, 5, 8};
    int h = count(state);
    int Level = 0;

    cout << "Distance : " << Level <<endl;
    Disply(state);
    cout << "Heuristic Value(Misplaced) : " << h << endl;

    while (h >0 ) {
        int pos = find(state.begin(), state.end(), 0) - state.begin();
        Level++;
        vector<int> arr;

        switch (pos) {
            case 0: arr = {1, 3}; break;
            case 1: arr = {0, 2, 4}; break;
            case 2: arr = {1, 5}; break;
            case 3: arr = {0, 4, 6}; break;
            case 4: arr = {1, 3, 5, 7}; break;
            case 5: arr = {2, 4, 8}; break;
            case 6: arr = {3, 7}; break;
            case 7: arr = {4, 6, 8}; break;
            case 8: arr = {5, 6}; break;
        }

        tie(state, h) = move(arr, pos, state);

        cout << "\n\nDistance : " << Level << endl;
        Disply(state);
        cout << "Heuristic Value(Misplaced) : " << h << endl;

        if(h==0) cout << "\nFinally Initial State = Goal State.\n";
    }

    return 0;
}

