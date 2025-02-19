/*77. Combinations

Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<vector<int>> ans;
        void solve(int n,int k,vector<int> &temp,int idx){
            if(temp.size()==k){
                ans.push_back(temp);
                return;
            }
            // if(temp.size()>k or idx>=n) {
            //     return;
            // }
            for(int i=idx;i<=n;i++){
                temp.push_back(i);
                solve(n,k,temp,i+1);
                temp.pop_back();
            }
        }
        vector<vector<int>> combine(int n, int k) {
            ans.clear();
            vector<int> temp;
             solve(n,k,temp,1);
             return ans;
        }
    };

    int main() {
        int n, k;
        cout << "Enter n and k: ";
        cin >> n >> k;
    
        Solution solution;
        vector<vector<int>> result = solution.combine(n, k);
    
        cout << "Combinations:\n";
        for (const auto& comb : result) {
            cout << "[";
            for (size_t i = 0; i < comb.size(); i++) {
                cout << comb[i] << (i < comb.size() - 1 ? ", " : "");
            }
            cout << "]\n";
        }
    
        return 0;
    }