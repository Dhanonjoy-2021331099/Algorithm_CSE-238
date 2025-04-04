// Job Sequencing problem

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of Jobs: ";
    cin >> n;

    // Dynamic arrays for jobs, deadlines, and profits
    int job[n];
    int dedline[n];
    int profit[n];

    // Input job details
    for (int i = 0; i < n; i++) {
        cout << "Enter Job ID, Deadline, and Profit for Job " << i + 1 << ": ";
        cin >> job[i] >> dedline[i] >> profit[i];
    }

    double total = 0;

    // Sort by profit
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (profit[i] < profit[j]) {
                swap(profit[i], profit[j]);
                swap(dedline[i], dedline[j]);
                swap(job[i], job[j]);
            }
        }
    }

    // Find maximum deadline
    int maxDeadline = dedline[0];
    for (int i = 1; i < n; i++) {
        if (dedline[i] > maxDeadline) {
            maxDeadline = dedline[i];
        }
    }

    // Result array creation
    int result[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        result[i] = 0;
    }

    // Job scheduling
    for (int i = 0; i < n; i++) {
        // Try to find a free slot for this job
        for (int j = min(maxDeadline, dedline[i]) - 1; j >= 0; j--) {
            if (result[j] == 0) {
                result[j] = job[i];
                total += profit[i];
                break; // Stop after placing the job
            }
        }
    }

    cout << "Total Profit: " << total << endl;
    cout << "Scheduled Jobs: ";
    for (int i = 0; i < maxDeadline; i++) {
        if (result[i] != 0) {
            cout << result[i] << " ";
        }
    }
    cout << endl;

    return 0;
}

// overall Time Complexity : O(n^2)
