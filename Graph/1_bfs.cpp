#include <bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(vector<vector<int>> &adj) {
    vector<int> bfs;
    int n = adj.size();
    vector<int> vis(n, 0);
    queue<int> q;
    q.push(0);
    vis[0] = 1;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

void printBFS(vector<vector<int>> &adj) {
    vector<int> bfsTraversal = bfsOfGraph(adj);
    for (int node : bfsTraversal) {
        cout << node << " ";
    }
    cout << endl;
}

int main() {
    // Example 1: Simple Graph
    vector<vector<int>> adj1 = {
        {1, 2}, 
        {0, 3, 4}, 
        {0}, 
        {1}, 
        {1}
    };
    cout << "BFS for Example 1: ";
    printBFS(adj1);

    // Example 2: Another Connected Graph
    vector<vector<int>> adj2 = {
        {1}, 
        {0, 2, 3}, 
        {1, 4}, 
        {1}, 
        {2, 5, 6}, 
        {4}, 
        {4}
    };
    cout << "BFS for Example 2: ";
    printBFS(adj2);

    // Example 3: A Graph with More Connections
    vector<vector<int>> adj3 = {
        {1, 2, 3}, 
        {0, 4}, 
        {0, 5}, 
        {0, 6}, 
        {1, 7}, 
        {2, 8}, 
        {3, 9}, 
        {4}, 
        {5}, 
        {6}
    };
    cout << "BFS for Example 3: ";
    printBFS(adj3);

    return 0;
}
