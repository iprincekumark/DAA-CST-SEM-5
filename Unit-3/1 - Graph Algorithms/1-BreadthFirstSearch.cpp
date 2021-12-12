#include <bits/stdc++.h>

using namespace std;
void BFS(vector<int> adj[], int v, int s)
{
    bool visited[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (int v : adj[u])
        {
            if (visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
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
    cout << "Following is Breadth First Search: " << endl;
    cout << "Enter the starting vertex: ";
    cin >> vertex;
    BFS(adjInput, n, vertex);
    return 0;
}