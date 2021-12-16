#include <bits/stdc++.h>
using namespace std;

int kanpsackRecursive(int wt[], int val[], int n, int k)
{
    if (n == 0 || k == 0)
        return 0;
    if (wt[n - 1] > k)
        return kanpsackRecursive(wt, val, n - 1, k);
    else
        return max(kanpsackRecursive(wt, val, n - 1, k), val[n - 1] + kanpsackRecursive(wt, val, n - 1, k - wt[n - 1]));
}

int knapsackTabulationBottomUp_DP(int wt[], int val[], int n, int k)
{
    int i, j, w;
    int sol[n + 1][k + 1];
    for (i = 0; i < n + 1; i++)
    {
        for (j = 0; j < k + 1; j++)
        {
            if (i == 0 || j == 0)
                sol[i][j] = 0;
            else if (wt[i - 1] > j)
                sol[i][j] = sol[i - 1][j];
            else
                sol[i][j] = max(sol[i - 1][j], val[i - 1] + sol[i - 1][j - wt[i - 1]]);
        }
    }
    return sol[n][k];
}
