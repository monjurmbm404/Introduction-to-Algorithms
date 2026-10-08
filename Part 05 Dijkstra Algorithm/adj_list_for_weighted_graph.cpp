#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Optimize standard input/output streams for faster execution
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, e;
    // Read total number of nodes (n) and edges (e)
    cin >> n >> e;

    // Adjacency list using an array of vectors.
    // Each element in the vector is a pair: {neighbor_node, edge_weight}
    vector<pair<int, int>> adj_list[n];

    // Take input for each edge and its weight
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c; // 'a' and 'b' are the connected nodes, 'c' is the weight
        
        // Since it's an undirected weighted graph, add the connection in both directions
        adj_list[a].push_back({b, c}); // Edge from 'a' to 'b' with weight 'c'
        adj_list[b].push_back({a, c}); // Edge from 'b' to 'a' with weight 'c'
    }

    // Print the adjacency list to visualize the graph and its edge weights
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        // Loop through each neighbor stored in the pair {neighbor_node, weight}
        for (auto p : adj_list[i])
        {
            cout << p.first << " (weight: " << p.second << "), ";
        }
        cout << endl;
    }

    return 0;
}