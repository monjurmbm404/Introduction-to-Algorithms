#include <bits/stdc++.h>
using namespace std;

// Adjacency list to represent the graph (supports up to 105 nodes)
vector<int> adj_list[105];

// 'vis' array keeps track of whether a node has been visited anywhere in the graph
bool vis[105];

// 'pathvis' array tracks nodes currently in the active recursion stack (current DFS path)
int pathvis[105];

// Flag variable to store whether a cycle is found (true) or not (false)
bool cycle;

// Depth First Search (DFS) function to traverse the graph
void dfs(int src)
{
    // Mark the current node as visited
    vis[src] = true;
    
    // Mark the current node as part of the current path/recursion stack
    pathvis[src] = true;
    
    // Check all neighboring nodes (children) connected to the current node
    for (int child : adj_list[src])
    {
        // If the child is already visited AND is currently in our active path,
        // it means we found a back-edge, which confirms a cycle!
        if (vis[child] && pathvis[child])
        {
            cycle = true;
        }
        
        // If the child has not been visited yet, explore it recursively
        if (!vis[child])
        {
            dfs(child);
        }
    }
    
    // Backtracking step: When leaving this node, remove it from the active path stack
    pathvis[src] = false;
}

int main()
{
    int n, e;
    // Read total number of nodes (n) and edges (e)
    cin >> n >> e;
    
    // Take input for each directed edge and build the adjacency list
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b); // Directed edge from node 'a' to node 'b'
    }
    
    // Initialize all nodes as unvisited and not in any path
    memset(vis, false, sizeof(vis));
    memset(pathvis, -1, sizeof(pathvis));
    
    // Assume there is no cycle initially
    cycle = false;
    
    // Run DFS for every node to ensure disconnected components are also checked
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