#include <bits/stdc++.h>

using namespace std;
struct Item
{
    int value, weight;
};
bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int w, struct Item arr[], int n)
{
    sort(arr, arr + n, cmp);
    int curWeight = 0, i;
    double finalValue = 0.0;
    for (i = 0; i < n; i++)
    {
        if ((curWeight + arr[i].weight) <= w)
        {
            curWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            int remain = w - curWeight;
            finalValue += arr[i].value * ((double)remain / (double)arr[i].weight);
            break;
        }
    }
    return finalValue;
}
int main()
{
    int n, W, i;
    cin >> n >> W;
    Item arr[n];
    cout << "Enter array" << endl;
    for (i = 0; i < n; i++)
    {
        int value, weight;
        cin >> value;
        cin >> weight;
        arr[i].value = value;
        arr[i].weight = weight;
    }
    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, n);
    return 0;
}