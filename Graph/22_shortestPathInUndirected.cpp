/*Shortest Path in Undirected

You are given an adjacency list, adj of Undirected Graph having unit weight of the edges, find the shortest path from src 
to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

Examples :

Input: adj[][] = [[1, 3], [0, 2], [1, 6], [0, 4], [3, 5], [4, 6], [2, 5, 7, 8], [6, 8], [7, 6]], src=0
Output: [0, 1, 2, 1, 2, 3, 3, 4, 4]

Input: adj[][]= [[3], [3], [], [0, 1]], src=3
Output: [1, 1, -1, 0]*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();
            
            for (int adjNode : adj[node]) {
                if (dist[node] + 1 < dist[adjNode]) {
                    dist[adjNode] = dist[node] + 1;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }
        return dist;
    }
};

int main() {
    vector<vector<int>> example1 = {{1, 2}, {0, 3, 4}, {0, 4}, {1, 5}, {1, 2, 5}, {3, 4}};
    int src1 = 0;
    
    Graph g;
    vector<int> result1 = g.shortestPath(example1, src1);
    
    cout << "Example 1 - Shortest distances from source node " << src1 << ":\n";
    for (int i = 0; i < result1.size(); i++) {
        cout << "Node " << i << ": " << result1[i] << "\n";
    }
    
    vector<vector<int>> example2 = {{1, 3}, {0, 2, 3}, {1, 4}, {0, 1, 4}, {2, 3, 5}, {4}};
    int src2 = 2;
    
    vector<int> result2 = g.shortestPath(example2, src2);
    
    cout << "\nExample 2 - Shortest distances from source node " << src2 << ":\n";
    for (int i = 0; i < result2.size(); i++) {
        cout << "Node " << i << ": " << result2[i] << "\n";
    }
    
    return 0;
}

