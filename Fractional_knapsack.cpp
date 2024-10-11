#include <iostream>
using namespace std;

int main() {
    int n, capacity;
    cin >> n >> capacity;

    double ratio[n];
    double profit[n];
    double weight[n];
    double total = 0;

    // Input profit and weight for each item
    for (int i = 0; i < n; i++) {
        cout << "Enter profit and weight for item " << i + 1 << ": ";
        cin >> profit[i] >> weight[i];
        ratio[i] = profit[i] / weight[i]; // Calculate ratio for each item
    }

    // Ratio print
    cout << "Value-to-weight ratios:" << endl;
    for (int i = 0; i < n; i++) {
        cout << ratio[i] << endl;
    }

    // Sort
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {   // Compare ratio[i] and ratio[j]
                swap(ratio[i], ratio[j]);
                swap(weight[i], weight[j]);
                swap(profit[i], profit[j]);
            }
        }
    }

    // Total value calculation
    for (int i = 0; i < n; i++) {
        if (weight[i] > capacity) {
            total += ratio[i] * capacity; // Calculate the fraction
            break; // Exit if the item is too heavy
        } else {
            total += profit[i];
            capacity -= weight[i];
        }
    }

    cout << "Maximum value in the knapsack: " << total << endl;

    return 0;
}
