# 📌 Day 02 — Breadth First Search (BFS)

Welcome to **Day 02** of the Graph Theory series.

Today, we will learn one of the most important graph traversal algorithms:

- ✅ Breadth First Search (BFS)
- ✅ Graph Traversal
- ✅ Reachability (Can a node be visited?)
- ✅ Single Source Shortest Distance
- ✅ Shortest Path Printing

BFS is one of the most frequently used algorithms in:

- Competitive Programming
- Coding Interviews
- Graph Problems
- AI Path Finding
- Social Networks
- Web Crawlers

---

# 📂 Files

| File                                           | Description                                   |
| ---------------------------------------------- | --------------------------------------------- |
| `bfs.cpp`                                      | Basic Breadth First Search Traversal          |
| `checking_if_a_node_can_be_visited_or_not.cpp` | Check whether a destination node is reachable |
| `single_source_shortest_distance.cpp`          | Find the shortest distance from a source node |
| `path_printing.cpp`                            | Print the shortest path using Parent Array    |

---

# 📖 What is Breadth First Search (BFS)?

Breadth First Search (BFS) is a graph traversal algorithm that visits nodes **level by level**.

Instead of going deep into one path, BFS first visits all immediate neighbors, then their neighbors, and so on.

BFS uses a **Queue (FIFO)** data structure.

---

# BFS Visualization

```
        0
      /   \
     1     2
    / \     \
   3   4     5
```

Starting from node **0**

Traversal Order

```
0 → 1 → 2 → 3 → 4 → 5
```

Level-wise traversal

```
Level 0 : 0

Level 1 : 1 2

Level 2 : 3 4 5
```

---

# BFS Algorithm

```
Push source node into queue

Mark source as visited

While queue is not empty

    Take front node

    Process it

    Visit all unvisited neighbours

        Mark visited

        Push into queue
```

---

# Why Do We Use a Queue?

Queue follows the **First In First Out (FIFO)** principle.

```
Push

0

↓

0 1

↓

0 1 2
```

Pop

```
0

↓

1

↓

2
```

This ensures BFS always explores nodes level by level.

---

# Time Complexity

```
O(V + E)
```

Where

- **V = Number of Vertices**
- **E = Number of Edges**

Every node is visited once.

Every edge is processed once.

---

# Space Complexity

```
O(V)
```

Used for

- Queue
- Visited Array
- Level Array
- Parent Array

---

# 1️⃣ Basic BFS Traversal

File

```
bfs.cpp
```

This program performs a standard BFS traversal starting from a source node.

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

Output

```
0 1 2 3 4 5
```

---

# 2️⃣ Checking Whether a Node is Reachable

File

```
checking_if_a_node_can_be_visited_or_not.cpp
```

After BFS, we simply check

```cpp
visited[destination]
```

If

```
visited[dst] == true
```

Output

```
Yes
```

Otherwise

```
No
```

Example

Input

```
6 5
0 1
1 2
2 3
3 4
4 5

0 5
```

Output

```
Yes
```

---

# 3️⃣ Single Source Shortest Distance

File

```
single_source_shortest_distance.cpp
```

BFS naturally computes the shortest distance in an **unweighted graph**.

We maintain a **Level Array**.

```
level[source] = 0
```

Whenever we visit a child

```
level[child] = level[parent] + 1
```

Example

```
0

↓

1

↓

2

↓

3
```

Levels

```
0 -> 0

1 -> 1

2 -> 2

3 -> 3
```

---

# 4️⃣ Shortest Path Printing

File

```
path_printing.cpp
```

To reconstruct the shortest path, we store the **Parent** of every visited node.

```
parent[child] = current_node
```

After BFS

Start from destination

```
Destination

↓

Parent

↓

Parent

↓

Source
```

Reverse the collected path.

Example

```
0

↓

1

↓

4

↓

5
```

Printed Path

```
0 1 4 5
```

---

# Parent Array Example

```
Node      Parent

0         -1

1          0

2          0

3          1

4          1

5          4
```

To print the path from **0 → 5**

```
5

↓

4

↓

1

↓

0
```

Reverse

```
0 1 4 5
```

---

# BFS vs DFS

| Feature                    | BFS            | DFS               |
| -------------------------- | -------------- | ----------------- |
| Data Structure             | Queue          | Stack / Recursion |
| Traversal                  | Level by Level | Depth First       |
| Shortest Path (Unweighted) | ✅ Yes         | ❌ No             |
| Memory Usage               | Higher         | Lower             |
| Time Complexity            | O(V + E)       | O(V + E)          |

---

# Applications of BFS

- Finding the shortest path in an unweighted graph
- Finding the minimum number of edges
- Checking graph connectivity
- Finding reachable nodes
- Level-order traversal of trees
- Social networking (friend suggestions)
- GPS navigation (unweighted roads)
- Web crawlers
- Network broadcasting
- Maze solving

---

# Example Input

```
6 6
0 1
0 2
1 3
1 4
2 5
4 5
```

---

# Example BFS Traversal

```
0 1 2 3 4 5
```

---

# Example Levels

```
Node    Level

0       0

1       1

2       1

3       2

4       2

5       2
```

---

# Key Takeaways

- Breadth First Search (BFS) explores a graph **level by level**.
- BFS uses a **Queue (FIFO)** to maintain traversal order.
- Every node is visited **only once** using a `visited` array.
- BFS can determine whether a node is **reachable** from a source.
- BFS finds the **shortest distance** in an **unweighted graph**.
- Using a **parent array**, BFS can reconstruct and print the shortest path.
- The overall time complexity of BFS is **O(V + E)**.

---

## 📚 Next Day

➡️ **Day 03 Depth First Search (DFS)**

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
