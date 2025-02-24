/*Cycle in a Directed Graph
Difficulty: MediumAccuracy: 27.88%Submissions: 447K+Points: 4
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as an adjacency list, where adj[i] contains a list of vertices that are directly reachable from 
vertex i. Specifically, adj[i][j] represents an edge from vertex i to vertex j.*/

#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis, int node) {
    vis[node] = 1;
    pathVis[node] = 1;

    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (dfs(adj, vis, pathVis, it)) return true;
        } else if (pathVis[it]) { // A cycle is detected
            return true;
        }
    }

    pathVis[node] = 0; // Backtrack before returning
    return false;
}

bool isCyclic(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> vis(n, 0);
    vector<int> pathVis(n, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (dfs(adj, vis, pathVis, i)) return true; // Return true if a cycle is found
        }
    }
    return false; // No cycle found in any component
}

int main() {
    int n = 4; // Number of nodes
    vector<vector<int>> adj(n);

    // Example graph with a cycle: 0 -> 1 -> 2 -> 3 -> 1 (Cycle)
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1); // Back edge creating a cycle

    cout << "Graph adjacency list:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << " -> ";
        for (int j : adj[i]) cout << j << " ";
        cout << endl;
    }

    if (isCyclic(adj)) {
        cout << "Cycle detected in the graph.\n";
    } else {
        cout << "No cycle in the graph.\n";
    }

    return 0;
}
