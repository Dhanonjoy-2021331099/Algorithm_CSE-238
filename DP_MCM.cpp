// Matrix chain multiplication

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<< "Enter Number of Dimension: ";
    cin >> n;

    cout << "Enter dimension: ";
    int p[n] ;
    for(int i=0;i<n;i++)
    cin >> p[i];

    int m[n][n] = {0};
    int s[n][n] = {0};
    
    int j,q,min;

    for(int d=1; d<n-1;d++)
    {
        for(int i=1; i<n-d; i++)
        {
            j = i+ d;
            min = INT_MAX;
            for(int k=i; k<=j-1;k++)
            {
                q = m[i][k] + m[k+1][j]+ p[i-1]*p[k]*p[j];
                if(q < min)
                {
                    min = q;
                    s[i][j] = k;
                }
            }
           m[i][j] = min;
        }      
    }
    // Matrix Print
    cout<< "M matrix: "<<endl;
    for (int i = 1; i < n; i++)
    {
        for (int j =i; j < n; j++)
        {
           cout<<m[i][j]<<" ";
        }
        cout<<endl;      
    }

    cout << "S matrix : "<<endl;
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
           cout<<s[i][j]<<" ";
        }
        cout<<endl;       
    }

    cout << "Minimum cost/multiplication = " << m[1][n-1] <<endl;
    cout<< "K = " << s[1][n-1] <<endl;

    return 0;
}
