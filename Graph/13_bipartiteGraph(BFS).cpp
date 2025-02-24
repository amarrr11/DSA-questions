/*Bipartite Graph

Given an adjacency list of a graph adj. Check whether the graph is bipartite or not.

A bipartite graph can be colored with two colors such that no two adjacent vertices share the same color. This means we can 
divide the graph’s vertices into two distinct sets where:

All edges connect vertices from one set to vertices in the other set.
No edges exist between vertices within the same set.
Examples:

Input: adj = [[1], [0,2], [1]]
Bipartite-Graph
Output: true
Explanation: The given graph can be colored in two colors so, it is a bipartite graph.
Input: adj = [[2, 3], [2], [0, 1, 3], [0, 2]]



Output: false 
Explanation: The given graph cannot be colored in two colors such that color of adjacent vertices differs. */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool bfs(vector<vector<int>>& adj, vector<int>& col, int i) {
        queue<int> q;
        q.push(i);
        
        col[i] = 0; // Start coloring
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (auto it : adj[node]) {
                if (col[it] == -1) { // If unvisited, color it
                    col[it] = !col[node];
                    q.push(it);
                }
                else if (col[node] == col[it]) { // Conflict found
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> col(n, -1);  // -1 means unvisited
        
        for (int i = 0; i < n; i++) {
            if (col[i] == -1) {  // Run BFS for each component
                if (!bfs(adj, col, i)) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n);
    cout << "Enter " << m << " edges (0-based index):" << endl;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    Solution sol;
    if (sol.isBipartite(adj)) {
        cout << "The graph is Bipartite." << endl;
    } else {
        cout << "The graph is NOT Bipartite." << endl;
    }

    return 0;
}
