#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<vector<int>> revadj(n);
        vector<int> indegree(n, 0);

        // Reverse the graph
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                revadj[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safeNodes;

        // Push all terminal nodes (nodes with indegree 0)
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process nodes in topological order
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (auto it : revadj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};

int main() {
    Solution sol;

    // Example input graph (Adjacency List Representation)
    vector<vector<int>> adj = {
        {1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}
    };

    // Call the function
    vector<int> safeNodes = sol.eventualSafeNodes(adj);

    // Print the result
    cout << "Eventual Safe Nodes: ";
    for (int node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
