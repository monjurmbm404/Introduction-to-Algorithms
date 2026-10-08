#include <bits/stdc++.h>
using namespace std;

// Adjacency list to represent the undirected graph (supports up to 105 nodes)
vector<int> adj_list[105];

// 'vis' array tracks whether a node has been visited already
bool vis[105];

// 'parent' array stores the parent (the node we came from) for each node
int parent[105];

// Flag variable to indicate whether a cycle is found (true) or not (false)
bool cycle;

// Breadth-First Search (BFS) function to traverse the graph level by level
void bfs(int src)
{
    queue<int> q;
    q.push(src);       // Push the starting node into the queue
    vis[src] = true;   // Mark the starting node as visited

    while (!q.empty())
    {
        int par = q.front(); // Get the current node from the front of the queue
        q.pop();             // Remove it from the queue
        
        // Check all neighboring nodes (children) connected to the current node
        for (int child : adj_list[par])
        {
            // If the child is already visited, AND it is NOT the parent of the current node,
            // it means we found another path to an already visited node -> Cycle Detected!
            if (vis[child] && parent[par] != child)
            {
                cycle = true;
            }
            
            // If the child has not been visited yet, visit it and add it to the queue
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par; // Record that 'par' is the parent of this 'child'
            }
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
    
    // Initialize all nodes as unvisited and set parents to -1
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    
    // Assume there is no cycle initially
    cycle = false;
    
    // Run BFS for every node to handle disconnected graph components
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }
    
    // Print the final output based on whether a cycle was found
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