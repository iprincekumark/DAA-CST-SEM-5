#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
    vector<pair<int,int>> activity;
    int n,s,e,i;
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>s>>e;
        activity.push_back(make_pair(e,s));
    }
    sort(activity.begin(), activity.end());
    int count=0, currentEnd=-1;
    for(i=0;i<n;i++)
        if(activity[i].second > currentEnd) {
            count++;
            currentEnd = activity[i].first;
        }
    cout<<count<<endl;
}