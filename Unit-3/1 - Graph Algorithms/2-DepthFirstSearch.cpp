#include <bits/stdc++.h>
using namespace std;

void DFSRec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";

    for (int u : adj[s])
    {
        if (visited[u] == false)
            DFSRec(adj, u, visited);
    }
}

void DFS(vector<int> adj[], int V, int s)
{
    bool visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    DFSRec(adj, s, visited);
}

int main()
{
    const int N = 1e5 + 2;
    vector<int> adjInput[N];
    int n, m, x, y, vertex;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        adjInput[x].push_back(y);
        adjInput[y].push_back(x);
    }
    cout << "Following is Depth First Search: " << endl;
    cout << "Enter the starting vertex: ";
    cin >> vertex;
    DFS(adjInput, n, vertex);
    return 0;
}