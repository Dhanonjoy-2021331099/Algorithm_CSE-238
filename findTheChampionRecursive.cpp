#include <bits/stdc++.h>

using namespace std;


int maxKSum(vector<int>& scores, int k, int index = 0) {
    if (k == 0) return 0;  
    return scores[index] + maxKSum(scores, k - 1, index + 1);  
}

int main() {
    vector<int> scores = {5, 1, 8, 3, 7, 9}; 
    int k = 3; 

    sort(scores.rbegin(), scores.rend());

    int result = maxKSum(scores, k); 
    cout << "Largest sum of " << k << " scores: " << result << endl;

    return 0;
}
