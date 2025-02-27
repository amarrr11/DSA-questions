#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> indegree(n, 0);
        
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return topo;
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
