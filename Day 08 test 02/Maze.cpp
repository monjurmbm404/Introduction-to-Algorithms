// Problem Link: https://www.hackerrank.com/contests/mid-term-exam-a-introduction-to-algorithms-a-batch-08/challenges/maze-19

#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool visited[1005][1005];
// int level[1005][1005];
pair<int, int> parent[1005][1005];
int n, m, si, sj, di, dj;
// vector<pair<int, int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

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
    // level[si][sj] = 0;
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
                // level[ci][cj] = level[par_i][par_j] + 1;
                parent[ci][cj] = {par_i, par_j};
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
            if (c == 'R')
            {
                si = i;
                sj = j;
            }
            if (c == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }

    // cin >> si >> sj >> di >> dj;

    memset(visited, false, sizeof(visited));
    bfs(si, sj);
    // cout << level[di][dj];
    if (visited[di][dj])
    {
        int x = di;
        int y = dj;

        while (!(x == si && y == sj))
        {
            auto p = parent[x][y];

            if (grid[p.first][p.second] != 'R')
                grid[p.first][p.second] = 'X';

            x = p.first;
            y = p.second;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}