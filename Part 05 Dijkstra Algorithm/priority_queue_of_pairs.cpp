#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Optimize standard input/output streams for faster execution
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Declare a Min-Priority Queue of pairs.
    // - Data type: pair<int, int>
    // - Underlying container: vector<pair<int, int>>
    // - Ordering: greater<pair<int, int>> makes it a min-heap, 
    //   meaning the pair with the smallest 'first' value will always be at the top.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Push pairs into the priority queue
    pq.push({10, 1}); // Pair with first = 10, second = 1
    pq.push({5, 2});  // Pair with first = 5, second = 2

    // Since it's a min-heap, the pair with the smallest first value ({5, 2}) stays at the top.
    // pq.top().first will access 5, and pq.top().second will access 2.
    cout << pq.top().first << " " << pq.top().second;

    return 0;
}