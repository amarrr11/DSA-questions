/*Topological sort

Given an adjacency list for a Directed Acyclic Graph (DAG) where adj[u] contains a list of all vertices v such that there 
exists a directed edge u -> v. Return topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v,
 vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is
 correct then the output will be 1 else 0.*/


 #include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int> &vis, stack<int> &s, int node) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(adj, vis, s, it);
            }
        }
        s.push(node);
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size();
        stack<int> s;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(adj, vis, s, i);
            }
        }
        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example input graph
    vector<vector<int>> adj = {{1, 2}, {2, 3}, {3}, {}, {1, 5}, {6}, {}};
    
    // Call the function
    vector<int> topoOrder = sol.topologicalSort(adj);
    
    // Print the result
    cout << "Topological Order: ";
    for (int node : topoOrder) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}
