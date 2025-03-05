#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(int node, vector<bool>& vis, vector<vector<int>>& adjLs) {
        vis[node] = 1;
        for (auto it : adjLs[node]) {
            if (!vis[it]) {
                dfs(it, vis, adjLs);
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<vector<int>> adjLs(V);
        for (int i = 0; i < V; i++) { //convert adj matrix to list
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        vector<bool> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adjLs);
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    vector<vector<int>> adj = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    int V = adj.size();  // Number of vertices

    Solution sol;
    int result = sol.numProvinces(adj, V);

    cout << "Number of Provinces: " << result << endl;
    return 0;
}
