#include <bits/stdc++.h>
using namespace std;

int MatrixChainOrderRecursive(int p[], int i, int j)
{
    if (i == j)
        return 0;
    int k, count, min = INT_MAX;
    for (k = i; k < j; k++)
    {
        count = MatrixChainOrderRecursive(p, i, k) + MatrixChainOrderRecursive(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if (count < min)
            min = count;
    }
    return min;
}

int MCO_DynamicProgramming(int p[], int n)
{
    int m[n][n], i, j, k, L, q;
    for (i = 1; i < n; i++)
        m[i][i] = 0;
    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n - 1];
}
