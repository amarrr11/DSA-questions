/*Shortest path in Directed Acyclic Graph

Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where
 there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for
 that vertex.

Examples :

Input: V = 4, E = 2, edges = [[0,1,2], [0,2,1]]
Output: [0, 2, 1, -1]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. 
There is no way we can reach 3, so it's -1 for 3.
Input: V = 6, E = 7, edges = [[0,1,2], [0,4,1], [4,5,4], [4,2,2], [1,2,3], [2,3,6], [5,3,1]]
Output: [0, 2, 3, 6, 1, 5]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->4->2 with edge weight 
1+2=3. Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6. Shortest path from 0 to 4 is 0->4 with edge weight
 1.Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.*/

 #include <bits/stdc++.h>
 using namespace std;
 
 class Solution {
 public:
     vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
         vector<vector<pair<int, int>>> adj(V);
         for (auto it : edges) {
             int a = it[0];
             int b = it[1];
             int dis = it[2];
             adj[a].push_back({b, dis});
         }
 
         vector<int> dist(V, INT_MAX);
         dist[0] = 0;
 
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
         pq.push({0, 0});
 
         while (!pq.empty()) {
             int node = pq.top().second;
             pq.pop();
 
             for (auto it : adj[node]) {
                 int adjNode = it.first;
                 int wt = it.second;
 
                 if (dist[node] + wt < dist[adjNode]) {
                     dist[adjNode] = wt + dist[node];
                     pq.push({dist[adjNode], adjNode});
                 }
             }
         }
 
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }
         return dist;
     }
 };
 
 int main() {
     Solution sol;
     int V = 5, E = 6;
     vector<vector<int>> edges = {
         {0, 1, 2}, {0, 4, 1}, {1, 2, 3}, {4, 2, 2}, {4, 3, 1}, {3, 2, 1}
     };
 
     vector<int> result = sol.shortestPath(V, E, edges);
 
     cout << "Shortest distances from node 0: ";
     for (int dist : result) {
         cout << dist << " ";
     }
     cout << endl;
 
     return 0;
 }
 