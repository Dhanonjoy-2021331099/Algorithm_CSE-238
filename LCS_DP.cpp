#include<bits/stdc++.h>
using namespace std;

int lcs[100][100];
int main(){

    string s,s1;
    cout << "Enter S and S1: ";
    cin >> s>>s1;

    int l=s.size();
    int l1=s1.size();
   
   for (int i =1; i <=l; i++)
    {
        for (int j = 1; j <= l1; j++)
        {
           if(s[i-1]==s1[j-1]) lcs[i][j] = lcs[i-1][j-1]+1;
           else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
        }
        cout<<endl;     
    }

    cout << "LCS Table: "<<endl;

    for (int i = 0; i <=l; i++)
    {
        for (int j = 0; j <=l1; j++)
        {
           cout<<lcs[i][j]<<" ";
        }
        cout<<endl;         
    }

    int i= l+1;
    int j=l1+1;
    string f;
    while (i>0 and j>0)
    {
        if(s[i-1]==s1[j-1]) {
            f= s[i-1]+f;    
            i--;
            j--;
        }
        else if(lcs[i-1][j]>lcs[i][j-1]) i--;
        else j--;
    }
    cout<< "LCS : "<< f<<endl;
    
    return 0;
}