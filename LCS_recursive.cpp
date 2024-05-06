#include<bits/stdc++.h>
using namespace std;

int lcs(string A, string B, int i,int j){
    if(i==0 || j==0)
    return 0;fctt                                   
    else if(A[i-1] == B[j-1])
    return 1+lcs(A,B,i-1,j-1);
    else
    return max(lcs(A,B,i-1,j), lcs(A,B,i,j-1));
}

int main(){

    string A,B;
    cin >> A >> B;
    int i= A.length();
    int j = B.length();
   
    cout << lcs(A,B,i,j);

    return 0;
}