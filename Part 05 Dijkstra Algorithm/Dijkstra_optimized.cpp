#include <bits/stdc++.h>
using namespace std;

// Adjacency list to represent the weighted graph. 
// Each element is a pair: {neighbor_node, edge_weight}
vector<pair<int, int>> adj_list[105];

// Distance array to store the shortest distance from the source to each node
int dis[105];

// Optimized Dijkstra's algorithm function using a Min-Priority Queue
void dijkstra(int src)
{
    // Min-priority queue stores pairs of {distance_from_source, node}
    // Using 'greater' makes it a min-heap so the node with the smallest distance is always at the top
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Push the starting node with a distance of 0
    pq.push({0, src});
    
    // Distance to the source itself is always 0
    dis[src] = 0;

    // Process nodes until the priority queue is empty
    while (!pq.empty())
    {
        pair<int, int> par = pq.top();
        pq.pop();

        int par_node = par.second;
        int par_dis = par.first;

        // Optimization check: If the distance we popped is greater than the already recorded 
        // shortest distance to this node, skip processing it further
        if (par_dis > dis[par_node])
        {
            continue;
        }

        // Traverse all neighboring nodes (children) connected to the current parent node
        for (auto child : adj_list[par_node])
        {
            int child_node = child.first;
            int child_dis = child.second;

            // Relaxation step: If a shorter path to 'child_node' is found through 'par_node'
            if (par_dis + child_dis < dis[child_node])
            {
                // Update with the new shorter distance
                dis[child_node] = par_dis + child_dis;
                
                // Push the updated distance and child node into the priority queue
                pq.push({dis[child_node], child_node});
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