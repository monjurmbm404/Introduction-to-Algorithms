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

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int x : adj_lint[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}