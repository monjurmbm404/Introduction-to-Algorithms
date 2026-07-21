# 📌 Day 01 — Graph Representation

Welcome to **Day 01** of the Graph Theory series.

In this lesson, we learn the three most common ways to represent graphs in C++.

- ✅ Adjacency Matrix
- ✅ Adjacency List
- ✅ Edge List

These representations are the foundation of almost every graph algorithm such as:

- Breadth First Search (BFS)
- Depth First Search (DFS)
- Topological Sort
- Dijkstra's Algorithm
- Bellman-Ford Algorithm
- Floyd Warshall
- Minimum Spanning Tree (MST)

---

# 📂 Files

| File                                       | Description                           |
| ------------------------------------------ | ------------------------------------- |
| `adjacency_matrix_of_directed_graph.cpp`   | Adjacency Matrix for Directed Graph   |
| `adjacency_matrix_of_undirected_graph.cpp` | Adjacency Matrix for Undirected Graph |
| `adjacency_list_of_directed_graph.cpp`     | Adjacency List for Directed Graph     |
| `adjacency_list_of_undirected_graph.cpp`   | Adjacency List for Undirected Graph   |
| `agde_list_.cpp`                           | Edge List Representation              |

---

# 📖 What is a Graph?

A graph is a collection of

- Vertices (Nodes)
- Edges (Connections)

Example:

```
0 ---- 1
|      |
|      |
2 ---- 3
```

Vertices

```
0 1 2 3
```

Edges

```
0-1
0-2
1-3
2-3
```

---

# 1️⃣ Adjacency Matrix

An adjacency matrix is a **2D array** where

```
matrix[i][j]
```

indicates whether there is an edge from vertex **i** to vertex **j**.

If an edge exists

```
1
```

otherwise

```
0
```

Example

```
0 ---- 1
|      |
|      |
2 ---- 3
```

Matrix

|     | 0   | 1   | 2   | 3   |
| --- | --- | --- | --- | --- |
| 0   | 1   | 1   | 1   | 0   |
| 1   | 1   | 1   | 0   | 1   |
| 2   | 1   | 0   | 1   | 1   |
| 3   | 0   | 1   | 1   | 1   |

---

## Time Complexity

Building Matrix

```
O(V²)
```

Check Edge

```
O(1)
```

Iterate Neighbours

```
O(V)
```

Space Complexity

```
O(V²)
```

---

## Files

### Directed Graph

```
adjacency_matrix_of_directed_graph.cpp
```

### Undirected Graph

```
adjacency_matrix_of_undirected_graph.cpp
```

---

# 2️⃣ Adjacency List

Each vertex stores a list of all adjacent vertices.

Example

```
0 ---- 1
|      |
|      |
2 ---- 3
```

Representation

```
0 -> 1 2

1 -> 0 3

2 -> 0 3

3 -> 1 2
```

---

## Time Complexity

Building List

```
O(V + E)
```

Check Edge

```
O(degree)
```

Traverse Neighbours

```
O(degree)
```

Space Complexity

```
O(V + E)
```

---

## Files

### Directed Graph

```
adjacency_list_of_directed_graph.cpp
```

### Undirected Graph

```
adjacency_list_of_undirected_graph.cpp
```

---

# 3️⃣ Edge List

The edge list stores every edge as a pair.

Example

```
0 1
0 2
1 3
2 3
```

Stored as

```cpp
vector<pair<int,int>> edge_list;
```

Each element

```cpp
(a,b)
```

means

```
a ------> b
```

---

## Time Complexity

Building

```
O(E)
```

Check Edge

```
O(E)
```

Space

```
O(E)
```

---

## File

```
agde_list_.cpp
```

---

# Comparison

| Representation   | Space  | Edge Query | Neighbor Traversal | Best For              |
| ---------------- | ------ | ---------- | ------------------ | --------------------- |
| Adjacency Matrix | O(V²)  | O(1)       | O(V)               | Dense Graph           |
| Adjacency List   | O(V+E) | O(degree)  | O(degree)          | Sparse Graph          |
| Edge List        | O(E)   | O(E)       | O(E)               | Edge-based Algorithms |

---

# Directed vs Undirected Graph

## Directed Graph

```
0 → 1

1 → 2

2 → 3
```

Edges have direction.

---

## Undirected Graph

```
0 ---- 1

1 ---- 2

2 ---- 3
```

Edges have no direction.

If

```
0 - 1
```

then

```
0 → 1

1 → 0
```

---

# Example Input

```
4 4
0 1
0 2
1 3
2 3
```

---

# Example Output (Adjacency List)

```
0 -> 1 2

1 -> 3

2 -> 3

3 ->
```

---

# Key Takeaways

- Graphs can be represented using **Adjacency Matrix**, **Adjacency List**, or **Edge List**.
- **Adjacency Matrix** provides constant-time edge lookup but requires more memory.
- **Adjacency List** is the most commonly used representation because it is memory-efficient for sparse graphs.
- **Edge List** is simple and useful for algorithms that process edges directly, such as Bellman-Ford and Kruskal's Algorithm.
- Choosing the right representation depends on the graph size and the algorithm being implemented.

---

## 📚 Next Day

➡️ **Day 02 Breadth First Search (BFS)**

---

# 👨‍💻 Author

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
