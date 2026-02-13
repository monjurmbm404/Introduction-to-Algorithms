// Problem Link: https://www.hackerrank.com/contests/a1-algorithm-b8/challenges/can-go-1

#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool visited[1005][1005];
int level[1005][1005];
int n, m;
vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int si1, sj1, di, dj;

bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    return true;
}

void bfs(int si, int sj)
{

    queue<pair<int, int>> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

        for (int i = 0; i < 4; i++)
        {
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if (valid(ci, cj) && !visited[ci][cj] && grid[ci][cj] != '#')
            {
                q.push({ci, cj});
                visited[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            grid[i][j] = c;
            if (c == 'A')
            {
                si1 = i;
                sj1 = j;
            }
            if (c == 'B')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(visited, false, sizeof(visited));
    memset(level, -1, sizeof(level));
    bfs(si1, sj1);

    if (level[di][dj] != -1)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}