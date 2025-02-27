#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<pair<int, int>>>& adj, int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        
        int n = adj.size();
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        
        while (!pq.empty()) {
            int node = pq.top().second;
            pq.pop();
            
            for (auto it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;
                
                if (dist[node] + wt < dist[adjNode]) {
                    dist[adjNode] = dist[node] + wt;
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
    vector<vector<pair<int, int>>> example1 = {
        {{1, 2}, {2, 4}}, 
        {{0, 2}, {3, 1}, {4, 7}}, 
        {{0, 4}, {4, 3}}, 
        {{1, 1}, {5, 5}}, 
        {{1, 7}, {2, 3}, {5, 2}}, 
        {{3, 5}, {4, 2}}
    };
    int src1 = 0;
    
    Graph g;
    vector<int> result1 = g.shortestPath(example1, src1);
    
    cout << "Example 1 - Shortest distances from source node " << src1 << ":\n";
    for (int i = 0; i < result1.size(); i++) {
        cout << "Node " << i << ": " << result1[i] << "\n";
    }
    
    vector<vector<pair<int, int>>> example2 = {
        {{1, 1}, {3, 3}}, 
        {{0, 1}, {2, 2}, {3, 1}}, 
        {{1, 2}, {4, 4}}, 
        {{0, 3}, {1, 1}, {4, 1}}, 
        {{2, 4}, {3, 1}, {5, 6}}, 
        {{4, 6}}
    };
    int src2 = 2;
    
    vector<int> result2 = g.shortestPath(example2, src2);
    
    cout << "\nExample 2 - Shortest distances from source node " << src2 << ":\n";
    for (int i = 0; i < result2.size(); i++) {
        cout << "Node " << i << ": " << result2[i] << "\n";
    }
    
    return 0;
}
