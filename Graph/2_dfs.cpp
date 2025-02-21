#include <bits/stdc++.h>
using namespace std;

vector<int> ans;

void dfs(int node, vector<vector<int>>& adj, vector<int> &vis) {
    vis[node] = 1;
    ans.push_back(node);

    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj, vis);
        }
    }
}

vector<int> dfsOfGraph(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> vis(n, 0);
    ans.clear(); // Clear the result for multiple function calls
    dfs(0, adj, vis);
    return ans;
}

void printResult(vector<int>& res) {
    for (int node : res) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    // Example 1: Simple linear graph
    vector<vector<int>> adj1 = {
        {1},       // 0 -> 1
        {0, 2},    // 1 -> 0, 2
        {1, 3},    // 2 -> 1, 3
        {2}        // 3 -> 2
    };
    cout << "DFS Traversal of Graph 1: ";
    printResult(dfsOfGraph(adj1));

    // Example 2: Star-shaped graph
    vector<vector<int>> adj2 = {
        {1, 2, 3}, // 0 -> 1, 2, 3
        {0},       // 1 -> 0
        {0},       // 2 -> 0
        {0, 4, 5}, // 3 -> 0, 4, 5
        {3},       // 4 -> 3
        {3}        // 5 -> 3
    };
    cout << "DFS Traversal of Graph 2: ";
    printResult(dfsOfGraph(adj2));

    // Example 3: Disconnected graph (DFS starts from 0)
    vector<vector<int>> adj3 = {
        {1},    // 0 -> 1
        {0, 2}, // 1 -> 0, 2
        {1},    // 2 -> 1
        {},     // 3 (Disconnected)
        {5},    // 4 -> 5
        {4}     // 5 -> 4
    };
    cout << "DFS Traversal of Graph 3: ";
    printResult(dfsOfGraph(adj3));

    return 0;
}
