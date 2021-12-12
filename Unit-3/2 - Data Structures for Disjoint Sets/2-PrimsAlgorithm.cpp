#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#define INF INT_MAX
using namespace std;
int min(int key[], bool mstset[], int n)
{
    int min = INT_MAX, mini;
    for (int i = 0; i < n; i++)
    {
        if (mstset[i] == false && key[i] < min)
        {
            min = key[i];
            mini = i;
        }
    }
    return mini;
}
int main()
{
    int n, m;
    cout << "Enter number of nodes" << endl;
    cin >> n;
    cout << "Enter number of vertexes" << endl;
    cin >> m;
    vector<vector<int>> adjm(n, vector<int>(n, 0));
    cout << "From ------ to ------ weight" << endl;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        adjm[x][y] = z;
        adjm[y][x] = z;
    }

    bool mstset[n];
    int key[n];
    int parent[n];

    for (int i = 0; i < n; i++)
    {
        mstset[i] = false;
        key[i] = INF;
        parent[i] = -1;
    }
    key[0] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int h = min(key, mstset, n);
        mstset[h] = true;
        for (int j = 0; j < n; j++)
        {
            if (adjm[i][j] && mstset[j] == false && adjm[i][j] < key[j])
            {
                key[j] = adjm[i][j];
                parent[j] = h;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << parent[i] << " -> " << i << "  = " << adjm[i][parent[i]] << endl;
    }
}