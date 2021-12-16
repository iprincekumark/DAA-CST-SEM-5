#include<bits/stdc++.h>
using namespace std;

int fibRecursive(int n) {
    if(n<=1)
    return n;
    return fibRecursive(n-1) + fibRecursive(n-2);
}

int fibTabulationBottomUp(int n) {
    int f[n+1], i;
    int i;
    f[0] = 0;
    f[1] = 1;
    for(i=2; i<=n; i++)
        f[i] = f[i-1] + f[i-2];
    return f[n];
}

const int N = 1e5 + 2;
int lookup[N];
int fibMemorizationTopDown(int n) {
    if(lookup[n] == -1) {
        if(n <= -1)
            lookup[n] = n;
        else
            lookup[n] = fibMemorizationTopDown(n-1) + fibMemorizationTopDown(n-2);
    }
    return lookup[n];
}