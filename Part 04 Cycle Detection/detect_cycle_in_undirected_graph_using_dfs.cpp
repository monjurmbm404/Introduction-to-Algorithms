#include <bits/stdc++.h>
using namespace std;

// Adjacency list to represent the undirected graph (supports up to 105 nodes)
vector<int> adj_list[105];

// 'vis' array tracks whether a node has been visited already
bool vis[105];

// 'parent' array stores the parent node (where we came from) for each node
int parent[105];

// Flag variable to indicate whether a cycle is found (true) or not (false)
bool cycle;

// Depth First Search (DFS) function to traverse the graph recursively
void dfs(int src)
{
    // Mark the current source node as visited
    vis[src] = true;
    
    // Check all neighboring nodes (children) connected to the current node
    for (int child : adj_list[src])
    {
        // If the child is already visited, AND it is NOT the parent of the current node,
        // it means we found another path back to an already visited node -> Cycle Detected!
        if (vis[child] && parent[src] != child)
        {
            cycle = true;
        }
        
        // If the child has not been visited yet, set its parent and dive deeper with DFS
        if (!vis[child])
        {
            parent[child] = src; // Record that 'src' is the parent of this 'child'
            dfs(child);
        }
    }
}

int main()
{
    int n, e;
    // Read total number of nodes (n) and edges (e)
    cin >> n >> e;
    
    // Take input for each edge and build the adjacency list (undirected graph)
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b); // Edge from 'a' to 'b'
        adj_list[b].push_back(a); // Edge from 'b' to 'a' (since it's undirected)
    }
    
    // Initialize all nodes as unvisited and set all parents to -1
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    
    // Assume there is no cycle initially
    cycle = false;
    
    // Run DFS for every node to ensure disconnected graph components are also handled
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    
    // Print the final output depending on whether a cycle was detected
    if (cycle)
    {
        cout << "cycle detected";
    }
    else
    {
        cout << "No cycle";
    }

    return 0;
}