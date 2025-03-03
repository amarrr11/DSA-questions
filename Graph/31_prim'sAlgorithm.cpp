/*Minimum Spanning Tree

Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights 
of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each 
element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting
 the endpoint of the edge and the second integer denoting the weight of the edge.

Input:
3 3
0 1 5
1 2 3
0 2 1

Output: 4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.*/

#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0}); // {weight, node}
    vector<int> vis(V, 0);
    
    int sum = 0;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int node = it.second;
        int wt = it.first;

        if (!vis[node]) {
            vis[node] = 1;
            sum += wt;

            for (auto &it : adj[node]) {
                int adjNode = it[0];
                int edgeWt = it[1];

                if (!vis[adjNode]) {
                    pq.push({edgeWt, adjNode});
                }
            }
        }
    }
    return sum;
}

int main() {
    // Example graph:
    int V = 3, E = 3; // 3 vertices, 3 edges

    vector<vector<int>> adj[V];

    // Adding edges in adjacency list
    adj[0].push_back({1, 5}); // Edge 0-1 with weight 5
    adj[1].push_back({0, 5}); // Since it's undirected

    adj[1].push_back({2, 3}); // Edge 1-2 with weight 3
    adj[2].push_back({1, 3});

    adj[0].push_back({2, 1}); // Edge 0-2 with weight 1
    adj[2].push_back({0, 1});

    // Calling function and printing MST weight
    cout << "Minimum Spanning Tree Weight: " << spanningTree(V, adj) << endl;

    return 0;
}
