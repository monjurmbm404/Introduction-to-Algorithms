# 📌 Part 05 — Dijkstra Algorithm

Welcome to **Part 05** of the Graph Theory series.

In this lesson, we learn how to find the **shortest path from a single source vertex** to all other vertices in a weighted graph.

Topics covered:

- ✅ Weighted Graph Representation
- ✅ Adjacency List for Weighted Graph
- ✅ Priority Queue of Pairs
- ✅ Relaxation
- ✅ Queue-Based Shortest Path Approach
- ✅ Optimized Dijkstra's Algorithm
- ✅ Shortest Distance from a Source

Dijkstra's algorithm is one of the most important shortest-path algorithms in:

- Competitive Programming
- Coding Interviews
- Graph Theory
- Network Routing
- GPS and Navigation
- Transportation Systems
- Network Optimization

---

# 📂 Files

| File | Description |
|------|-------------|
| `adj_list_for_weighted_graph.cpp` | Represent a weighted graph using an adjacency list |
| `Dijkstra_naive.cpp` | Queue-based shortest path implementation using relaxation |
| `Dijkstra_optimized.cpp` | Optimized Dijkstra's Algorithm using a min-priority queue |
| `priority_queue_of_pairs.cpp` | Demonstrates a min-priority queue of pairs |

---

# 📖 What is a Weighted Graph?

A **weighted graph** is a graph where every edge has an associated value called a **weight**.

Example:

```text
      5
  0 ----- 1
  |       |
  |2      |3
  |       |
  2 ----- 3
      4
```

The graph contains edges such as:

```text
0 → 1   weight = 5
0 → 2   weight = 2
1 → 3   weight = 3
2 → 3   weight = 4
```

The weight can represent:

- Distance
- Cost
- Time
- Difficulty
- Network latency

---

# 1️⃣ Weighted Graph Using Adjacency List

File:

```text
adj_list_for_weighted_graph.cpp
```

For an unweighted graph, we commonly store:

```cpp
vector<int> adj_list[n];
```

For a weighted graph, we store:

```cpp
vector<pair<int, int>> adj_list[n];
```

Each pair contains:

```text
{neighbor, weight}
```

For example:

```cpp
adj_list[a].push_back({b, c});
```

means:

```text
a → b

weight = c
```

Because the example graph is undirected, we add the edge in both directions:

```cpp
adj_list[a].push_back({b, c});
adj_list[b].push_back({a, c});
```

---

# Example

Input:

```text
4 4
0 1 5
0 2 2
1 3 3
2 3 4
```

Adjacency List:

```text
0 -> 1 (weight: 5), 2 (weight: 2)

1 -> 0 (weight: 5), 3 (weight: 3)

2 -> 0 (weight: 2), 3 (weight: 4)

3 -> 1 (weight: 3), 2 (weight: 4)
```

---

# 2️⃣ What is Dijkstra's Algorithm?

**Dijkstra's Algorithm** finds the shortest distance from a **single source vertex** to every other reachable vertex in a weighted graph.

The standard Dijkstra algorithm works when edge weights are:

```text
Non-negative
```

That means:

```text
weight >= 0
```

Dijkstra repeatedly selects the currently known closest vertex and tries to improve the distances of its neighbours.

---

# 🧠 Shortest Path Example

Consider:

```text
      5
  0 ----- 1
  |       |
  2       3
  |       |
  2 ----- 3
      4
```

Starting from:

```text
Source = 0
```

Possible paths from `0` to `3`:

```text
0 → 1 → 3

Cost = 5 + 3 = 8
```

and:

```text
0 → 2 → 3

Cost = 2 + 4 = 6
```

Therefore:

```text
Shortest Distance from 0 to 3 = 6
```

---

# 🔑 Important Concept — Distance Array

We maintain an array:

```cpp
int dis[105];
```

It stores the shortest known distance from the source.

Initially:

```text
dis[source] = 0
```

and all other distances are:

```text
∞
```

In C++:

```cpp
for (int i = 0; i < n; i++)
    dis[i] = INT_MAX;
```

---

# 🔄 Relaxation

**Relaxation** is the most important operation in Dijkstra's algorithm.

Suppose:

```text
Current node = u
Neighbour = v
Edge weight = w
```

Then we check:

```cpp
if (dis[u] + w < dis[v])
```

If a shorter path is found:

```cpp
dis[v] = dis[u] + w;
```

This is called:

```text
Relaxing the edge
```

---

# Relaxation Example

Suppose:

```text
dis[0] = 0
```

and there is an edge:

```text
0 → 1   weight = 5
```

Then:

```text
dis[1] = min(dis[1], dis[0] + 5)
```

Initially:

```text
dis[1] = ∞
```

So:

```text
dis[1] = 5
```

---

# 3️⃣ Queue-Based Shortest Path Approach

File:

```text
Dijkstra_naive.cpp
```

This implementation uses:

```cpp
queue<pair<int, int>> q;
```

and repeatedly performs edge relaxation.

The basic idea is:

```text
Push source

↓

Take a node

↓

Check all neighbours

↓

Relax edges

↓

Push updated nodes again

↓

Continue until queue becomes empty
```

### Important Note

Despite the filename `Dijkstra_naive.cpp`, this is **not the standard Dijkstra algorithm** because classical Dijkstra selects the unprocessed vertex with the smallest tentative distance.

This code instead uses a normal queue and repeatedly relaxes vertices. It is better understood as a **queue-based shortest-path / relaxation approach**.

For the standard Dijkstra implementation, see:

```text
Dijkstra_optimized.cpp
```

---

# 4️⃣ Optimized Dijkstra's Algorithm

File:

```text
Dijkstra_optimized.cpp
```

The optimized implementation uses a:

```text
Min-Priority Queue
```

```cpp
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;
```

Each pair contains:

```text
{distance, node}
```

For example:

```cpp
pq.push({0, src});
```

means:

```text
distance = 0
node = src
```

---

# ⭐ Why Use a Priority Queue?

A normal queue does not guarantee that the smallest-distance node is processed first.

A min-priority queue always gives us the smallest pair according to the pair ordering.

Example:

```text
{10, 1}
{5, 2}
{8, 3}
```

The top element becomes:

```text
{5, 2}
```

because `5` is the smallest distance.

This is exactly what the standard Dijkstra approach needs.

---

# 5️⃣ Priority Queue of Pairs

File:

```text
priority_queue_of_pairs.cpp
```

This file demonstrates how to create a **min-priority queue of pairs**.

Code:

```cpp
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;
```

Push:

```cpp
pq.push({10, 1});
pq.push({5, 2});
```

The smallest pair comes first:

```text
5 2
```

---

# 🧩 Understanding the Priority Queue

The declaration:

```cpp
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;
```

contains three important parts.

### 1. Data Type

```cpp
pair<int, int>
```

### 2. Container

```cpp
vector<pair<int, int>>
```

### 3. Comparator

```cpp
greater<pair<int, int>>
```

`greater<>` changes the default max-heap into a:

```text
Min-Heap
```

---

# 🔍 Pair Ordering

For:

```cpp
pair<int, int>
```

C++ first compares:

```text
first
```

If the first values are equal, it compares:

```text
second
```

Example:

```text
{5, 4}
{3, 7}
{5, 2}
```

The order begins with:

```text
{3, 7}
{5, 2}
{5, 4}
```

because the first value has higher priority.

---

# 🚀 Optimized Dijkstra Workflow

Suppose:

```text
Source = 0
```

Initially:

```text
dis[0] = 0
dis[1] = ∞
dis[2] = ∞
dis[3] = ∞
```

Priority queue:

```text
{0, 0}
```

Process node `0`.

Suppose edges are:

```text
0 → 1  weight 5
0 → 2  weight 2
```

After relaxation:

```text
dis[1] = 5
dis[2] = 2
```

Priority queue:

```text
{2, 2}
{5, 1}
```

Node `2` is processed first because:

```text
2 < 5
```

This continues until all reachable shortest distances are finalized.

---

# 🛡️ Stale Entry Optimization

The optimized code contains:

```cpp
if (par_dis > dis[par_node])
{
    continue;
}
```

Why?

A node can be inserted into the priority queue multiple times with different distances.

Example:

```text
Node 3

First distance = 10

Later distance = 6
```

The queue may contain:

```text
{6, 3}
{10, 3}
```

When:

```text
{6, 3}
```

is processed, the shortest known distance becomes:

```text
6
```

Later, when:

```text
{10, 3}
```

is removed, it is outdated.

So we skip it:

```cpp
if (par_dis > dis[par_node])
    continue;
```

This is a very common Dijkstra implementation pattern.

---

# 📊 Example

Input:

```text
5 6
0 1 4
0 2 1
2 1 2
1 3 1
2 3 5
3 4 3
```

Graph:

```text
       4
   0 ------- 1
   |       / |
   |1    2   |1
   |   /     |
   2 ------- 3
       5     |
             |3
             |
             4
```

Starting from:

```text
0
```

Shortest distances:

```text
0 -> 0
1 -> 3
2 -> 1
3 -> 4
4 -> 7
```

---

# 🧮 Why is `1 -> 3` Equal to 3?

There are multiple possible paths.

Directly:

```text
0 → 1

Cost = 4
```

But:

```text
0 → 2 → 1

Cost = 1 + 2
     = 3
```

Therefore:

```text
Shortest distance to 1 = 3
```

---

# ⏱️ Time Complexity

For the standard priority-queue implementation of Dijkstra:

```text
O((V + E) log V)
```

Often written as:

```text
O(E log V)
```

for connected graphs where the number of edges is at least proportional to the number of vertices.

Where:

- `V` = Number of vertices
- `E` = Number of edges

---

# 💾 Space Complexity

The adjacency list requires:

```text
O(V + E)
```

The distance array requires:

```text
O(V)
```

The priority queue can contain multiple entries in this implementation, with worst-case space on the order of:

```text
O(E)
```

Overall:

```text
O(V + E)
```

---

# ⚠️ When Can Dijkstra Be Used?

Dijkstra's algorithm requires:

```text
Edge weights >= 0
```

Example:

```text
0 → 1   weight = 5
1 → 2   weight = 2
```

✅ Valid for Dijkstra.

But:

```text
0 → 1   weight = -5
```

❌ Standard Dijkstra should not be used with negative edge weights.

For graphs containing negative edge weights, algorithms such as **Bellman-Ford** are more appropriate.

---

# Dijkstra vs BFS

| Feature | BFS | Dijkstra |
|---------|-----|----------|
| Graph Type | Unweighted | Weighted |
| Edge Weight | Usually equal | Non-negative |
| Data Structure | Queue | Min-Priority Queue |
| Shortest Path | ✅ | ✅ |
| Time Complexity | O(V + E) | O((V + E) log V) |

### Important Idea

BFS can be thought of as a shortest-path method for graphs where every edge has the same cost.

When edge weights differ, we need a method that prioritizes the smallest known distance.

That is where Dijkstra becomes useful.

---

# Dijkstra vs Queue-Based Relaxation

| Feature | Queue-Based Approach | Standard Dijkstra |
|---------|----------------------|-------------------|
| Main Structure | Queue | Min-Priority Queue |
| Selects Minimum Distance | ❌ | ✅ |
| Standard Dijkstra | ❌ | ✅ |
| Edge Weights | Depends on implementation | Non-negative |
| Typical Complexity | Can be much worse | O((V + E) log V) |

---

# 🧠 Important Dijkstra Concepts

## 1. Source

The starting vertex.

```text
source = 0
```

---

## 2. Distance

The shortest known distance from the source.

```cpp
dis[node]
```

---

## 3. Relaxation

Update a distance when a shorter path is discovered.

```cpp
if (current_distance + weight < dis[child])
{
    dis[child] = current_distance + weight;
}
```

---

## 4. Min-Heap

Always process the smallest current distance first.

```cpp
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;
```

---

## 5. Stale Entry

Ignore an outdated priority queue entry.

```cpp
if (par_dis > dis[par_node])
{
    continue;
}
```

---

# 🌐 Applications of Dijkstra

Dijkstra's algorithm can be applied to:

- GPS Navigation
- Road Networks
- Network Routing
- Shortest Travel Time
- Minimum Transportation Cost
- Communication Networks
- Game Pathfinding
- Robot Navigation
- Geographic Information Systems
- Network Optimization

---

# 🧪 Example Input

```text
6 7
0 1 4
0 2 2
1 2 1
1 3 5
2 3 8
2 4 10
3 4 2
```

Source:

```text
0
```

---

# 🖥️ Example Output

The exact output depends on the graph, but it follows this format:

```text
0 -> 0
1 -> 3
2 -> 2
3 -> 8
4 -> 10
5 -> 2147483647
```

Here:

```text
2147483647
```

is `INT_MAX`, representing an unreachable node in the current implementation.

For production or contest code, it is often clearer to convert unreachable distances into a custom value such as:

```text
INF
```

or:

```text
-1
```

when required by the problem.

---

# 📌 Important Code Pattern

The most important part of optimized Dijkstra is:

```cpp
pq.push({0, src});
dis[src] = 0;

while (!pq.empty())
{
    auto par = pq.top();
    pq.pop();

    int par_dis = par.first;
    int par_node = par.second;

    if (par_dis > dis[par_node])
        continue;

    for (auto child : adj_list[par_node])
    {
        int child_node = child.first;
        int child_dis = child.second;

        if (par_dis + child_dis < dis[child_node])
        {
            dis[child_node] = par_dis + child_dis;
            pq.push({dis[child_node], child_node});
        }
    }
}
```

This pattern is worth memorizing for competitive programming.

---

# ✅ Common Mistakes

### Mistake 1 — Using Dijkstra with Negative Edges

```text
Negative edge
     ↓
Standard Dijkstra ❌
```

---

### Mistake 2 — Using a Max-Heap

Incorrect:

```cpp
priority_queue<pair<int, int>> pq;
```

This puts the largest distance first.

Use:

```cpp
priority_queue<
    pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>
> pq;
```

---

### Mistake 3 — Forgetting to Initialize Distances

Use:

```cpp
for (int i = 0; i < n; i++)
    dis[i] = INT_MAX;
```

and:

```cpp
dis[src] = 0;
```

---

### Mistake 4 — Forgetting Relaxation

Always check:

```cpp
if (current_distance + weight < dis[next])
```

before updating the distance.

---

# 📝 Key Takeaways

- A **weighted graph** stores both a neighbour and an edge weight.
- Dijkstra finds the **single-source shortest distance** in graphs with non-negative edge weights.
- The main operation of Dijkstra is **relaxation**.
- The optimized implementation uses a **min-priority queue**.
- Each priority queue entry stores:

```text
{distance, node}
```

- Stale priority queue entries should be skipped.
- Standard priority-queue Dijkstra runs in:

```text
O((V + E) log V)
```

- Dijkstra should **not** be used directly with negative edge weights.
- The queue-based implementation in `Dijkstra_naive.cpp` is a useful relaxation-based comparison, but it is not the classical Dijkstra algorithm.

---

# 📚 Learning Progress

```text
Day 01 → Graph Representation
           ↓
Day 02 → Breadth First Search (BFS)
           ↓
Day 03 → Depth First Search (DFS)
           ↓
Part 04 → Cycle Detection
           ↓
Part 05 → Dijkstra Algorithm ⭐
```

---


## 📚 Next Part

➡️ **Part 06 Bellman Ford Algorithm**

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
