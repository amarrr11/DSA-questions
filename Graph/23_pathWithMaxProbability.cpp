/*1514. Path with Maximum Probability
Solved
Medium
Topics
Companies
Hint
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an
 undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its
 success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at
 most 1e-5.

 

Example 1:



Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int startNode, int endNode) {
        vector<vector<pair<int,double>>> adj(n);
        
        for(auto i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        priority_queue<pair<double, int>> pq;
        pq.push({1.0, startNode});
        
        vector<double> prob(n, 0.0);
        prob[startNode] = 1.0;
        
        while (!pq.empty()) {
            double currProb = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == endNode) return currProb;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                double edgeProb = it.second;
                
                if (prob[node] * edgeProb > prob[adjNode]) {
                    prob[adjNode] = prob[node] * edgeProb;
                    pq.push({prob[adjNode], adjNode});
                }
            }
        }

        return 0.0;
    }
};

// Driver function with test cases
int main() {
    Solution sol;

    // Test Case 1
    int n1 = 3;
    vector<vector<int>> edges1 = {{0,1}, {1,2}, {0,2}};
    vector<double> succProb1 = {0.5, 0.5, 0.2};
    int startNode1 = 0, endNode1 = 2;
    cout << "Max Probability (Test Case 1): " << sol.maxProbability(n1, edges1, succProb1, startNode1, endNode1) << endl;

    // Test Case 2
    int n2 = 3;
    vector<vector<int>> edges2 = {{0,1}, {1,2}, {2,0}};
    vector<double> succProb2 = {0.5, 0.5, 0.3};
    int startNode2 = 0, endNode2 = 2;
    cout << "Max Probability (Test Case 2): " << sol.maxProbability(n2, edges2, succProb2, startNode2, endNode2) << endl;

    return 0;
}
