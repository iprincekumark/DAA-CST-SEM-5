#include <bits/stdc++.h>
using namespace std;

int lcsRecursive(string X, string Y, int m, int n) {
    if(m==0 || n==0)
        return 0;
    if(X[m-1] == Y[n-1])
        return 1 + lcsRecursive(X,Y,m-1, n-1);
    else
        return max(lcsRecursive(X,Y,m,n-1), lcsRecursive(X,Y,m-1,n));
}

int lcsDynamicProgramming(string X, string Y, int m, int n) {
    int sol[m+1][n+1];
    int i, j;
    for(i=0; i<=m; i++) {
        for(j=0; j<=n; j++) {
            if(i==0 || j==0)
                sol[i][j] = 0;
            else if(X[i-1] == Y[j-1])
                sol[i][j] = sol[i-1][j-1] + 1;
            else
                sol[i][j] = max(sol[i-1][j], sol[i][j-1]);
        }
    }
    return sol[m][n];
}