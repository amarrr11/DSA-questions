/*781. Rabbits in Forest

There is a forest with an unknown number of rabbits. We asked n rabbits "How many rabbits have the same color as you?" and collected the answers in an integer array answers where answers[i] is the answer of the ith rabbit.

Given the array answers, return the minimum number of rabbits that could be in the forest.

 

Example 1:

Input: answers = [1,1,2]
Output: 5
Explanation:
The two rabbits that answered "1" could both be the same color, say red.
The rabbit that answered "2" can't be red or the answers would be inconsistent.
Say the rabbit that answered "2" was blue.
Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.
Example 2:

Input: answers = [10,10,10]
Output: 11*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& ans) {
        int n = ans.size();
        unordered_map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            mp[ans[i]]++;
        }
        for (auto it : mp) {
            int size = it.first + 1;
            int totalgrps = ceil((double)it.second / size);
            cnt += (totalgrps * size);
        }
        return cnt;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> ans1 = {1, 1, 2};
    cout << "Output for Test Case 1: " << sol.numRabbits(ans1) << endl;

    // Test Case 2
    vector<int> ans2 = {10, 10, 10};
    cout << "Output for Test Case 2: " << sol.numRabbits(ans2) << endl;

    // Test Case 3
    vector<int> ans3 = {0, 0, 1, 1, 1};
    cout << "Output for Test Case 3: " << sol.numRabbits(ans3) << endl;

    return 0;
}
