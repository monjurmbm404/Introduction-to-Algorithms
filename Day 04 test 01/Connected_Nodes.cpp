// Problem Link: https://www.hackerrank.com/contests/a1-algorithm-b8/challenges/connected-nodes-1

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj_lint[n];

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_lint[a].push_back(b);
        adj_lint[b].push_back(a); // undirected graph
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " -> ";
    //     for (int x : adj_lint[i])
    //     {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    int q;
    cin >> q;
    while (q--)
    {
        vector<int> v;
        int x;
        cin >> x;
        for (int a : adj_lint[x])
        {
            v.push_back(a);
        }
        sort(v.begin(), v.end(), std ::greater<int>());
        if (!v.size())
        {
            cout << "-1";
        }
        for (int a : v)
        {
            cout << a << " ";
        }
        cout << endl;
    }

    return 0;
}