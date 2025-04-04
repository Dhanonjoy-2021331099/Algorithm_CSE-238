#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> score= {5, 1, 8, 3, 7, 9}; 
    int k = 3;
    sort(score.rbegin(), score.rend());

    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += score[i];
    }

    cout << "Largest sum of " << k << " scores: " << sum << endl;

    return 0;
}
