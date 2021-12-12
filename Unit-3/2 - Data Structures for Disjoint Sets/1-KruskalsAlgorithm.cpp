#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef vector<pair<int, pair<int, int>>> viii;

int find(int u, int *parent)
{
    if(parent[u] < 0)
        return u;
    return find(parent[u], parent);
}

void unionByWeight(int u, int v, int *parent) 
{
    int pu = find(u, parent), pv = find(v, parent);
    if(pu != pv) {
        if(parent[pu] < parent[pv]) {
            parent[pu] += parent[pv];
            parent[pv] = pu;
        }
        else {
            parent[pv] += parent[pu];
            parent[pu] = pv;
        }
    }
}

viii kruskals(viii g, int v) 
{
    viii res;
    int s,d,w, parent[v];
    for(int i=0; i<v; i++)
        parent[i]=-1;
    sort(g.begin(), g.end());
    int e = g.size();
    for(int i=0; i<e; i++) {
        s = g[i].second.first;
        d = g[i].second.second;
        w = g[i].first;
        if(find(s,parent) != find(d,parent)) {
            res.push_back(g[i]);
            unionByWeight(s,d,parent);
        }
    }
    return res;
}

int main() 
{
    viii g,res;
    int v,e,s,d,w;
    cin>>v>>e;
    for(int i=0;i<e;i++) {
        cin>>s>>d>>w;
        g.push_back(make_pair(w, make_pair(s,d)));
    }
    res = kruskals(g,v);
    int sum = 0;
    for(int i=0; i<res.size(); i++) {
        int w = res[i].first;
        cout << res[i].second.first << " " << res[i].second.second << endl;
        sum += w;
    }
    cout << "Sum of weights = " << sum << endl;
}