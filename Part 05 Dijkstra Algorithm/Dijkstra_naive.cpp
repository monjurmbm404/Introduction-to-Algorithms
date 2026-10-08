#include <bits/stdc++.h>
using namespace std;

// Adjacency list to represent the weighted graph. 
// Each element is a pair: {neighbor_node, edge_weight}
vector<pair<int, int>> adj_list[105];

// Distance array to store the shortest distance from the source to each node
int dis[105];

// Naive Dijkstra's algorithm function using a queue (Breadth-First Search approach)
void dijkstra(int src)
{
    // Queue stores pairs of {node, current_distance_from_source}
    queue<pair<int, int>> q;
    
    // Push the starting node with a distance of 0
    q.push({src, 0});
    
    // Distance to the source itself is always 0
    dis[src] = 0;

    // Process nodes in the queue level by level (similar to BFS)
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();

        int par_node = par.first;
        int par_dis = par.second;

        // Traverse all neighboring nodes (children) connected to the parent node
        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;

            // Relaxation step: If we found a shorter path to 'child_node' through 'par_node'
            if (par_dis + child_dis < dis[child_node])
            {
                // Update with the new shorter distance
                dis[child_node] = par_dis + child_dis;
                
                // Push the updated child into the queue to explore its neighbors further
                q.push({child_node, dis[child_node]});
            }
        }
    }
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n, e;
    // Read total number of nodes (n) and edges (e)
    cin >> n >> e;

    // Take input for each edge and weight, then build the undirected weighted graph
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c; // 'a' and 'b' are connected nodes, 'c' is the weight
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    // Initialize all distances with infinity (INT_MAX) representing unreachable nodes initially
    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;

    // Run Dijkstra's algorithm starting from node 0 as the source
    dijkstra(0);

    // Print the shortest distance from the source (node 0) to every other node
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }
    return 0;
}