# 📌 Part 04 — Cycle Detection

Welcome to **Part 04** of the Graph Theory series.

In this lesson, we learn how to detect whether a graph contains a **cycle** using:

- ✅ DFS for Directed Graph
- ✅ BFS for Undirected Graph
- ✅ DFS for Undirected Graph
- ✅ Visited Array
- ✅ Parent Array
- ✅ Recursion Stack / Path Visited Array

Cycle detection is an important graph concept and is frequently used in:

- Competitive Programming
- Coding Interviews
- Dependency Management
- Scheduling Problems
- Topological Sorting
- Network Analysis
- Graph Validation

---

# 📂 Files

| File | Description |
|------|-------------|
| `detect_cycle_in_directed_graph_using_dfs.cpp` | Detect cycle in a directed graph using DFS |
| `detect_cycle_in_undirected_graph_using_bfs.cpp` | Detect cycle in an undirected graph using BFS |
| `detect_cycle_in_undirected_graph_using_dfs.cpp` | Detect cycle in an undirected graph using DFS |

---

# 📖 What is a Cycle?

A **cycle** exists in a graph when we can start from a vertex, follow a sequence of edges, and eventually return to the same vertex.

### Example

```text
0 → 1
↑   ↓
3 ← 2
```

The cycle is:

```text
0 → 1 → 2 → 3 → 0
```

Therefore:

```text
Cycle Detected
```

---

# 🔄 Types of Cycle Detection

The technique used for detecting a cycle depends on whether the graph is:

1. Directed
2. Undirected

We use different approaches for each type.

---

# 1️⃣ Cycle Detection in Directed Graph Using DFS

File:

```text
detect_cycle_in_directed_graph_using_dfs.cpp
```

For a **directed graph**, we use:

- `vis[]` — tracks whether a node has been visited
- `pathvis[]` — tracks whether a node is currently in the DFS recursion path

---

# 🧠 Why Do We Need `pathvis[]`?

Consider:

```text
0 → 1 → 2
    ↑   ↓
    └───┘
```

During DFS:

```text
0
 ↓
1
 ↓
2
```

If node `2` has an edge back to node `1`, then node `1` is already:

```text
visited
```

and also:

```text
currently in the DFS path
```

Therefore:

```cpp
if (vis[child] && pathvis[child])
{
    cycle = true;
}
```

This indicates a **back edge**, which means a cycle exists.

---

# 🔍 `vis[]` vs `pathvis[]`

| Array | Purpose |
|------|---------|
| `vis[]` | Node has been visited at least once |
| `pathvis[]` | Node is currently inside the active DFS path |

Example:

```text
DFS Path:

0 → 1 → 2 → 3
```

While processing node `3`:

```text
pathvis[0] = true
pathvis[1] = true
pathvis[2] = true
pathvis[3] = true
```

When DFS backtracks from `3`:

```cpp
pathvis[3] = false;
```

This removes node `3` from the current recursion path.

---

# 🔁 Directed Graph Cycle Detection Algorithm

```text
For every vertex:

    If vertex is not visited:

        DFS(vertex)

            Mark vertex visited
            Mark vertex as part of current path

            For every neighbour:

                If neighbour is visited
                AND neighbour is in current path:

                    Cycle exists

                If neighbour is not visited:

                    DFS(neighbour)

            Remove vertex from current path
```

---

# Example — Directed Graph With Cycle

```text
0 → 1
    ↓
    2
    ↓
    3
    ↓
    1
```

Cycle:

```text
1 → 2 → 3 → 1
```

Output:

```text
cycle detected
```

---

# Example — Directed Graph Without Cycle

```text
0 → 1 → 2 → 3
```

There is no path that returns to an earlier node in the active DFS path.

Output:

```text
No cycle
```

---

# 2️⃣ Cycle Detection in Undirected Graph Using BFS

File:

```text
detect_cycle_in_undirected_graph_using_bfs.cpp
```

For an **undirected graph**, we use:

- `vis[]` — visited array
- `parent[]` — stores the parent of each node
- BFS Queue

---

# 🧠 Why Do We Need a Parent Array?

Consider:

```text
0 ---- 1
```

Because the graph is undirected, the adjacency list contains:

```text
0 → 1
1 → 0
```

When we are at node `1`, we see node `0` is already visited.

But this does **not** mean there is a cycle.

Why?

Because:

```text
0
 \
  1
```

Node `0` is simply the parent of node `1`.

Therefore, we ignore the parent edge.

---

# Cycle Condition

For an undirected graph:

```cpp
if (vis[child] && parent[par] != child)
{
    cycle = true;
}
```

Meaning:

> If the neighbour is already visited and it is not the current node's parent, we found another connection to an already visited node.

That indicates a cycle.

---

# Example

```text
      0
     / \
    1---2
```

Edges:

```text
0 - 1
0 - 2
1 - 2
```

Starting BFS from `0`:

```text
0
├── 1
└── 2
```

When processing `1`, node `2` is already visited.

But:

```text
parent[1] = 0
```

and:

```text
2 != 0
```

Therefore:

```text
Cycle Detected
```

---

# 3️⃣ Cycle Detection in Undirected Graph Using DFS

File:

```text
detect_cycle_in_undirected_graph_using_dfs.cpp
```

The same parent concept can be used with DFS.

We maintain:

```cpp
parent[]
```

For every node:

```cpp
parent[child] = src;
```

When we encounter an already visited neighbour:

```cpp
if (vis[child] && parent[src] != child)
{
    cycle = true;
}
```

If the visited neighbour is **not the parent**, then a cycle exists.

---

# 🔍 Undirected DFS Example

Consider:

```text
0
| \
|  \
1---2
```

Edges:

```text
0 - 1
0 - 2
1 - 2
```

DFS starts:

```text
0
 ↓
1
 ↓
2
```

At node `2`, we find node `0`.

Node `0` is already visited.

But:

```text
parent[2] = 1
```

and:

```text
0 != 1
```

Therefore:

```text
Cycle Detected
```

---

# 🆚 Directed vs Undirected Cycle Detection

| Graph Type | Algorithm | Important Data |
|------------|-----------|----------------|
| Directed | DFS | `vis[]`, `pathvis[]` |
| Undirected | DFS | `vis[]`, `parent[]` |
| Undirected | BFS | `vis[]`, `parent[]` |

---

# 📊 Comparison

| Feature | Directed DFS | Undirected DFS | Undirected BFS |
|---------|--------------|----------------|----------------|
| `visited[]` | ✅ | ✅ | ✅ |
| `parent[]` | ❌ | ✅ | ✅ |
| `pathvis[]` | ✅ | ❌ | ❌ |
| Queue | ❌ | ❌ | ✅ |
| Recursion | ✅ | ✅ | ❌ |
| Cycle Detection | Back Edge | Visited Non-Parent | Visited Non-Parent |

---

# 🌐 Disconnected Graphs

A graph may contain multiple disconnected components.

Example:

```text
Component 1:

0 ---- 1 ---- 2


Component 2:

3 ---- 4


Component 3:

5
```

If we only run DFS/BFS from node `0`, we cannot check the other components.

Therefore, we run DFS/BFS from every unvisited node:

```cpp
for (int i = 0; i < n; i++)
{
    if (!vis[i])
    {
        dfs(i);
    }
}
```

This ensures that **every connected component** is checked.

---

# ⏱️ Time Complexity

For all three implementations:

```text
O(V + E)
```

Where:

- `V` = Number of vertices
- `E` = Number of edges

Every vertex and edge is processed at most a constant number of times.

---

# 💾 Space Complexity

### Directed DFS

```text
O(V)
```

Used by:

- `vis[]`
- `pathvis[]`
- Recursion stack

### Undirected DFS

```text
O(V)
```

Used by:

- `vis[]`
- `parent[]`
- Recursion stack

### Undirected BFS

```text
O(V)
```

Used by:

- `vis[]`
- `parent[]`
- Queue

---

# 🧪 Example Input

## Directed Graph

```text
4 4
0 1
1 2
2 3
3 1
```

Graph:

```text
0 → 1 → 2
    ↑   ↓
    └───3
```

Output:

```text
cycle detected
```

---

# 🧪 Undirected Graph With Cycle

Input:

```text
4 4
0 1
1 2
2 3
3 0
```

Graph:

```text
0 ---- 1
|      |
|      |
3 ---- 2
```

Output:

```text
cycle detected
```

---

# 🧪 Undirected Graph Without Cycle

Input:

```text
4 3
0 1
1 2
2 3
```

Graph:

```text
0 ---- 1 ---- 2 ---- 3
```

Output:

```text
No cycle
```

---

# ⚠️ Important Concepts

## 1. Back Edge

In a directed graph, an edge pointing to a node that is currently in the DFS recursion path is called a **back edge**.

```text
0 → 1 → 2
    ↑   ↓
    └───┘
```

This indicates a cycle.

---

## 2. Parent Edge

In an undirected graph, every edge appears in both directions.

For:

```text
0 ---- 1
```

we have:

```text
0 → 1
1 → 0
```

The edge from `1` back to `0` is simply the parent edge and should not be considered a cycle.

---

## 3. Disconnected Components

Always consider disconnected graphs.

Use:

```cpp
for (int i = 0; i < n; i++)
{
    if (!vis[i])
    {
        dfs(i);
    }
}
```

or the equivalent BFS approach.

---

# 🌟 Applications of Cycle Detection

Cycle detection is useful in many real-world and competitive programming problems:

- Detecting circular dependencies
- Course prerequisite validation
- Task scheduling
- Dependency resolution
- Detecting deadlocks
- Topological sorting
- Build systems
- Network analysis
- Graph validation
- Detecting infinite dependency chains

---

# 📝 Key Takeaways

- A **cycle** exists when a graph contains a path that eventually returns to an already connected vertex.
- For a **directed graph**, DFS uses both `visited[]` and `pathvis[]`.
- For an **undirected graph**, DFS/BFS uses `visited[]` and `parent[]`.
- In a directed graph, a visited node that is still in the current DFS path indicates a **back edge**.
- In an undirected graph, a visited neighbour that is **not the parent** indicates a cycle.
- Always check every unvisited vertex to handle **disconnected graphs**.
- Cycle detection can be performed in **O(V + E)** time.

---

# 🔑 Important Patterns to Remember

### Directed Graph + DFS

```cpp
if (vis[child] && pathvis[child])
{
    cycle = true;
}
```

### Undirected Graph + DFS/BFS

```cpp
if (vis[child] && parent[current] != child)
{
    cycle = true;
}
```

These two patterns are extremely important for competitive programming.

---

## 📚 Next Part

➡️ **Part 05 Dijkstra Algorithm**

---

# Author

## **Engr. Md Monjur Bakth Mazumder**

🎓 **Secondary School Certificate (SSC) from [Shah Helal High School](https://www.shahhelalhs.edu.bd/)**

🎓 **Diploma in Computer Science and Technology from [Moulvibazar Polytechnic Institute (MPI)](https://mpi.moulvibazar.gov.bd/)**

🎓 **BSc in Computer Science & Engineering (CSE)** _(Ongoing)_ **at [Sylhet International University (SIU)](https://siu.edu.bd/)**

📧 **Email:** monjurmbm404@gmail.com

---

## ⭐ Support the Project

If you found this repository helpful, please consider giving it a **⭐ Star**. It helps others discover the project and motivates future development.

---

## 🌐 Connect with Me

| Platform       | Link                                        |
| -------------- | ------------------------------------------- |
| 💻 GitHub      | https://github.com/monjurmbm404             |
| 💼 LinkedIn    | https://linkedin.com/in/monjurmbm404        |
| 🧩 LeetCode    | https://leetcode.com/u/monjurmbm404         |
| ⚔️ Codeforces  | https://codeforces.com/profile/monjurmbm404 |
| 🍽️ CodeChef    | https://www.codechef.com/users/monjurmbm404 |
| 🏆 VJudge      | https://vjudge.net/user/monjurmbm404        |
| 📘 Facebook    | https://www.facebook.com/monjurmbm404       |
| 🐦 X (Twitter) | https://x.com/monjurmbm404                  |
| ▶️ YouTube     | https://youtube.com/@monjurmbm404           |
| ✍️ Medium      | https://medium.com/@monjurmbm404            |
