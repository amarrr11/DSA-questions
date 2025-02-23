/*Undirected Graph Cycle

Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether the graph contains any cycle or 
not. The Graph is represented as an adjacency list, where adj[i] contains all the vertices that are directly connected to 
vertex i.

NOTE: The adjacency list represents undirected edges, meaning that if there is an edge between vertex i and vertex j, both j
 will be adj[i] and i will be in adj[j].

Examples:

Input: adj = [[1], [0,2,4], [1,3], [2,4], [1,3]] 
Output: 1
Explanation: 

1->2->3->4->1 is a cycle.
Input: adj = [[], [2], [1,3], [2]]
Output: 0
Explanation: 

No cycle in the graph.*/


#include <bits/stdc++.h>
using namespace std;

bool bfs(int src, vector<vector<int>>& adj, vector<bool>& vis) {
    queue<pair<int, int>> q;
    q.push({src, -1});
    vis[src] = 1;

    while (!q.empty()) {
        int parent = q.front().second;
        int node = q.front().first;
        q.pop();

        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push({it, node});
            } else if (it != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> vis(n, 0);

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (bfs(i, adj, vis)) {
                return true;
            }
        }
    }
    return false;
}

void runTestCase(vector<pair<int, int>> edges, int n, string testName) {
    vector<vector<int>> adj(n);
    for (auto edge : edges) {
        int u = edge.first, v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << testName << ": ";
    if (isCycle(adj)) {
        cout << "Cycle detected ✅" << endl;
    } else {
        cout << "No cycle ❌" << endl;
    }
}

int main() {
    // Example 1: Graph with a cycle (Triangle cycle)
    vector<pair<int, int>> edges1 = {{0, 1}, {1, 2}, {2, 0}};
    runTestCase(edges1, 3, "Test Case 1 (Cycle exists)");

    // Example 2: Graph without a cycle (Linear graph)
    vector<pair<int, int>> edges2 = {{0, 1}, {1, 2}, {2, 3}};
    runTestCase(edges2, 4, "Test Case 2 (No cycle)");

    // Example 3: Disconnected graph with one cycle
    vector<pair<int, int>> edges3 = {{0, 1}, {1, 2}, {2, 0}, {3, 4}};
    runTestCase(edges3, 5, "Test Case 3 (Cycle in one component)");

    return 0;
}

