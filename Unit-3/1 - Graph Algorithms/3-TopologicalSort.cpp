#include <iostream>
#include <vector>
#include <stack>

using namespace std;
void topologicalSortUtils(vector<int> graph[], bool visited[], stack<int> &st, int i)
{
    visited[i] = true;
    int n = graph[i].size();
    for (int j = 0; j < n; j++)
    {
        if (!visited[graph[i][j]])
            topologicalSortUtils(graph, visited, st, graph[i][j]);
    }
    st.push(i);
}
void topologicalSort(vector<int> graph[], int v)
{
    bool visited[v];
    stack<int> st;
    for (int i = 0; i < v; i++)
        visited[i] = false;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            topologicalSortUtils(graph, visited, st, i);
    }
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}
int main()
{
    int v, e, s, d;
    cin >> v >> e;
    vector<int> graph[v];
    for (int i = 0; i < e; i++)
    {
        cin >> s >> d;
        graph[s].push_back(d);
    }
    topologicalSort(graph, v);
}