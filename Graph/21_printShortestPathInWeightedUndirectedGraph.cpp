/*Shortest Path in Weighted undirected graph

You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights. Find the shortest weight path between the vertex 1 and the vertex n,  if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element -1.

The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the weight of that edge.

Note: The driver code here will first check if the weight of the path returned is equal to the sum of the weights along the nodes on that path, if equal it will output the weight of the path, else -2. In case the list contains only a single element (-1) it will simply output -1. 

Examples :

Input: n = 5, m= 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
Output: 5
Explanation: Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5. 
Input: n = 2, m= 1, edges = [[1, 2, 2]]
Output: 2
Explanation: Shortest path from 1 to 2 is by the path 1 2 whose weight is 2. */

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
    if (n == 1) return {1};
    vector<vector<pair<int,int>>> adj(n+1);
    
    for(auto it:edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    vector<int>parent(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    
    vector<int> dist(n+1,INT_MAX);
    dist[1]=0;
    
    pq.push({0,1});
    
    while(!pq.empty())
    {
        auto it=pq.top();
        pq.pop();
        
        int node=it.second;
        
        for(auto it:adj[node]){
            int adjNode=it.first;
            int wt=it.second;
            
            
            if(dist[node]+wt<dist[adjNode]){
               dist[adjNode]=dist[node]+wt;
               pq.push({dist[adjNode],adjNode});
               parent[adjNode]=node;
            }
        }
    }
    
    if(dist[n]==INT_MAX) return {-1};
    
    
    vector<int> path;
    int node = n;
    
    while(parent[node]!=node) {  
        path.push_back(node);
        node = parent[node];
    }
    
    path.push_back(1);
    
    reverse(path.begin(),path.end());
    path.insert(path.begin(), dist[n]);
    return path;
    
}


int main() {
    // Example 1
    int n1 = 5, m1 = 6;
    vector<vector<int>> edges1 = {
        {1, 2, 2}, {2, 5, 5}, {2, 3, 4},
        {1, 4, 1}, {4, 3, 3}, {3, 5, 1}
    };
    
    vector<int> result1 = shortestPath(n1, m1, edges1);
    
    cout << "Shortest Path Distance: " << result1[0] << endl;
    cout << "Path: ";
    for (size_t i = 1; i < result1.size(); i++) {
        cout << result1[i] << " ";
    }
    cout << endl;

    // Example 2
    int n2 = 4, m2 = 4;
    vector<vector<int>> edges2 = {
        {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {1, 4, 5}
    };

    vector<int> result2 = shortestPath(n2, m2, edges2);

    cout << "Shortest Path Distance: " << result2[0] << endl;
    cout << "Path: ";
    for (size_t i = 1; i < result2.size(); i++) {
        cout << result2[i] << " ";
    }
    cout << endl;

    return 0;
}

