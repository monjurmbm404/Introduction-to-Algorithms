# 📌 Day 03 — Depth First Search (DFS)

Welcome to **Day 03** of the Graph Theory series.

Today, we will learn one of the most fundamental graph traversal algorithms:

- ✅ Depth First Search (DFS)
- ✅ DFS Traversal
- ✅ DFS on 2D Grid
- ✅ BFS vs DFS on 2D Grid
- ✅ Single Source Shortest Distance on Grid (BFS)
- ✅ Counting Connected Components

DFS is one of the most important algorithms in:

- Competitive Programming
- Coding Interviews
- Graph Theory
- Tree Algorithms
- Grid Problems
- Backtracking Problems

---

# 📂 Files

| File                                          | Description                           |
| --------------------------------------------- | ------------------------------------- |
| `dfs.cpp`                                     | Basic DFS Traversal                   |
| `dfs_on_2d_grid.cpp`                          | DFS Traversal on a 2D Grid            |
| `bfs_on_2d_grid.cpp`                          | BFS Traversal on a 2D Grid            |
| `bfs_on_2d_grid_source_shortest_distance.cpp` | Shortest Distance on a Grid using BFS |
| `number_of_component.cpp`                     | Count Connected Components using DFS  |

---

# 📖 What is Depth First Search (DFS)?

Depth First Search (DFS) is a graph traversal algorithm that explores as **deep as possible** before backtracking.

Instead of visiting all neighbors first (like BFS), DFS follows one path until it reaches the end, then returns to explore remaining paths.

DFS is commonly implemented using:

- **Recursion**
- **Stack**

---

# DFS Visualization

```
        0
      /   \
     1     2
    / \     \
   3   4     5
```

Starting from node **0**

Possible DFS Traversal

```
0 → 1 → 3 → 4 → 2 → 5
```

Unlike BFS, DFS does **not** visit nodes level by level.

---

# DFS Algorithm

```
Visit current node

Mark it as visited

For every neighbour

    If not visited

        DFS(neighbour)
```

---

# Why Recursion Works?

Every recursive call is stored inside the **Call Stack**.

Example

```
DFS(0)

↓

DFS(1)

↓

DFS(3)

↓

Return

↓

DFS(4)

↓

Return

↓

Return

↓

DFS(2)

↓

DFS(5)
```

---

# Time Complexity

```
O(V + E)
```

Where

- **V = Number of Vertices**
- **E = Number of Edges**

Every vertex and every edge is visited only once.

---

# Space Complexity

```
O(V)
```

Used for

- Visited Array
- Recursive Call Stack

---

# 1️⃣ Basic DFS Traversal

File

```
dfs.cpp
```

Traverses every reachable node starting from a source.

Example Input

```
6 6
0 1
0 2
1 3
1 4
2 5
4 5
```

Possible Output

```
0 1 3 4 5 2
```

> **Note:** DFS traversal order may vary depending on the order of edges in the adjacency list.

---

# 2️⃣ DFS on a 2D Grid

File

```
dfs_on_2d_grid.cpp
```

DFS can also traverse a matrix (grid).

Movement is performed in **4 directions**.

```
↑

↓

←

→
```

Direction Array

```cpp
{-1,0}
{1,0}
{0,-1}
{0,1}
```

The `valid()` function ensures that we stay inside the grid boundaries.

---

# Example Grid

```
A A A

A A A

A A A
```

Starting Position

```
0 0
```

DFS visits cells by continuously exploring one direction before backtracking.

---

# 3️⃣ BFS vs DFS on 2D Grid

File

```
bfs_on_2d_grid.cpp
```

This file demonstrates both BFS and DFS implementations for a 2D grid.

### BFS

- Uses a Queue
- Explores level by level
- Finds shortest distance

### DFS

- Uses Recursion
- Explores deeply
- Does not guarantee shortest path

---

# 4️⃣ Single Source Shortest Distance on Grid

File

```
bfs_on_2d_grid_source_shortest_distance.cpp
```

BFS is the correct algorithm for finding the shortest distance in an **unweighted grid**.

We maintain a **Level Array**.

```
level[source] = 0
```

Whenever a new cell is visited

```
level[next] = level[current] + 1
```

Example

```
S . .

. . .

. . D
```

Shortest Distance

```
4
```

---

# 5️⃣ Counting Connected Components

File

```
number_of_component.cpp
```

A **Connected Component** is a group of vertices where every vertex is reachable from every other vertex.

Example

```
0 ---- 1

2 ---- 3

4
```

There are **3 connected components**.

Algorithm

```
For every vertex

    If not visited

        DFS(vertex)

        Component++
```

Example Output

```
0 1

2 3

4

Total Component -> 3
```

---

# Connected Component Visualization

```
Component 1

0 ---- 1



Component 2

2 ---- 3



Component 3

4
```

Total Components

```
3
```

---

# DFS vs BFS

| Feature                    | DFS               | BFS         |
| -------------------------- | ----------------- | ----------- |
| Data Structure             | Recursion / Stack | Queue       |
| Traversal                  | Depth First       | Level Order |
| Shortest Path (Unweighted) | ❌ No             | ✅ Yes      |
| Memory Usage               | Lower             | Higher      |
| Time Complexity            | O(V + E)          | O(V + E)    |

---

# Applications of DFS

- Connected Components
- Cycle Detection
- Topological Sorting
- Tree Traversal
- Maze Solving
- Backtracking Problems
- Flood Fill Algorithm
- Island Counting
- Graph Connectivity
- Strongly Connected Components (SCC)

---

# Example Input

```
6 5
0 1
0 2
1 3
2 4
4 5
```

---

# Example DFS Traversal

```
0 1 3 2 4 5
```

> The traversal order may differ depending on the adjacency list.

---

# Key Takeaways

- Depth First Search (DFS) explores a graph as deeply as possible before backtracking.
- DFS is typically implemented using **recursion** or an explicit **stack**.
- A `visited` array ensures that each node is processed only once.
- DFS works efficiently on both **graphs** and **2D grids**.
- DFS can be used to count **connected components** in a graph.
- Unlike BFS, DFS **does not guarantee the shortest path** in an unweighted graph.
- The overall time complexity of DFS is **O(V + E)**.

---

## 📚 Next Day

➡️ **Day 04 Cycle Detection**

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
