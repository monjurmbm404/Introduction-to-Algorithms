// Problem Link: https://www.hackerrank.com/contests/a1-algorithm-b8/challenges/connected-or-not-1-1

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, e;
    cin >> n >> e;
    int adj_mat[n][n];

    // set all value 0
    memset(adj_mat, 0, sizeof(adj_mat));

    for (int i = 0; i < n; i++)
        adj_mat[i][i] = 1;

    // get input
    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        adj_mat[a][b] = 1;
    }

    int q, a, b;
    cin >> q;
    while (q--)
    {
        cin >> a >> b;
        if (a == b)
            cout << "YES\n";
        else
        {
            if (adj_mat[a][b] == 1)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}