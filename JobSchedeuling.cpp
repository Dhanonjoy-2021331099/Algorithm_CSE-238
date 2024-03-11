#include <bits/stdc++.h>

using namespace std;

struct Job
{
    char id;
    int deadLine;
    int profit;
};

bool comp(Job j1, Job j2)
{
    return (j1.profit > j2.profit); // compare jobs based on profit
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int main()
{
    Job jobs[] = {{'a', 9, 15},
                  {'b', 2, 2},
                  {'c', 5, 18},
                  {'d', 7, 1},
                  {'e', 4, 25},
                  {'f', 2, 20},
                  {'g', 5, 8},
                  {'h', 7, 10},
                  {'i', 4, 12},
                  {'j', 3, 5}

    };
    int n = 10;
    cout << "Following is maximum profit sequence of Jobs: "
         << "\n";

    sort(jobs, jobs + n, comp); // sort jobs on profit

    int jobSeq[n]; // To store result (Sequence of jobs)

    bool slot[n]; // To keep track of free time slots

    for (int i = 0; i < n; i++)
        slot[i] = false; // initially all slots are free
    for (int i = 0; i < n; i++)
    { // for all given jobs
        for (int j = min(n, jobs[i].deadLine) - 1; j >= 0; j--)
        { // search from last free slot
            if (slot[j] == false)
            {
                jobSeq[j] = i;  // Add this job to job sequence
                slot[j] = true; // mark this slot as occupied
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (slot[i])
        {
            cout << jobs[jobSeq[i]].id << " "; // display the sequence
        }

    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if (slot[i])
            cout << jobs[jobSeq[i]].profit << " ";
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
        if (slot[i])
            sum += jobs[jobSeq[i]].profit;
    cout << endl
         << " Total profit : " << sum;

    return 0;
}