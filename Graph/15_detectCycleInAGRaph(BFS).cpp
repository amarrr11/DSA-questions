#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isCyclic(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        queue<int> q;
        vector<int> indegree(n, 0);
        
        for (int i = 0; i < n; i++) {
            for (int it : adj[i]) {
                indegree[it]++;
            }
        }
        
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
        
        return topo.size() != n;
    }
};

int main() {
    Solution sol;
    
    // Example input graph
    vector<vector<int>> adj = {{1, 2}, {2, 3}, {3}, {}, {1, 5}, {6}, {}};
    
    // Call the function
    bool hasCycle = sol.isCyclic(adj);
    
    // Print the result
    if (hasCycle) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }
    
    return 0;
}
