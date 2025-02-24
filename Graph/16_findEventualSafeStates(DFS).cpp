/*802. Find Eventual Safe States (DFS lga do jo v circle nai bna rha vo sb lelo and return krdo)

There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 

Example 1:

Illustration of graph
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
Example 2:

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool dfs(vector<vector<int>>& graph,vector<int>& vis,vector<int>& check,vector<int> &pathVis,int node){
            vis[node]=1;
            pathVis[node]=1;
    
            for(auto it:graph[node]){
                if(!vis[it]){
                    if(dfs(graph,vis,check,pathVis,it)==true)return true;
                }else if(vis[it] and pathVis[it]){
                    return true;
                }
            }
    
            pathVis[node]=0;
            check[node]=1;
    
            return false;
        }
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n=graph.size();
            
            vector<int> vis(n,0);
            vector<int> check(n,0);
            vector<int> pathVis(n,0);
    
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    dfs(graph,vis,check,pathVis,i);
                }
            }
            vector<int> ans;
            for(int i=0;i<n;i++){
                if(check[i]==1){
                    ans.push_back(i);
                }
            }
            return ans;
        }
    };

int main() {
    Solution sol;
    
    // Example input graph
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{}, {}};
    
    // Call the function
    vector<int> safeNodes = sol.eventualSafeNodes(graph);
    
    // Print the result
    cout << "Safe Nodes: ";
    for (int node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}
