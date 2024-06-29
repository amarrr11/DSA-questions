/*
Minimum Deletion Cost to Avoid Repeating Letters

Ninja has given a string 'S' of lowercase characters of size 'N'. He also has provided an array 'COST' where 'COST[i]' refers
to the Cost of deleting the ‘i’th character in the string.

Ninja doesn't like a string with the same adjacent characters, so he asked you to help him transform the given string into the
string with no adjacent repetitive characters by deleting some characters in it.

Cost of deleting some characters is the sum of costs of individual deletion of characters at every position. Your task is to 
find the minimum cost needed to transform the string with no adjacent repetitive characters.

Example:
Input: 'S' = "babbc", 'COST' = [1, 2, 3, 4, 5] 
Output: 3

By deleting the third letter 'b' with cost, 3 will transform the string into 'babc'. This is the minimum possible cost to 
transform the string.


*****************************************************************************************************************************

basically we will traverse and as we have to delete the element we cannot always check arr[i] and arr[i-1] so we will make 
arr[i] to the larger cost so as to compare it with the next element.

*/
#include <bits/stdc++.h>
using namespace std;

int minimumCost(int n, string &s, vector<int> &cost) {
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            ans += min(cost[i], cost[i - 1]);
            cost[i] = max(cost[i], cost[i - 1]); // store the maximum element to compare it later
        }
    }
    return ans;
}

int main() {
    vector<pair<string, vector<int>>> examples = {
        {"abaac", {1, 2, 3, 4, 5}},
        {"abc", {1, 2, 3}},
        {"aabaa", {1, 2, 3, 4, 1}},
        {"aaaa", {3, 4, 2, 5}},
    };

    for (auto &example : examples) {
        string s = example.first;
        vector<int> cost = example.second;
        int n = s.size();
        int result = minimumCost(n, s, cost);
        cout << "For string \"" << s << "\" with costs ";
        for (int c : cost) cout << c << " ";
        cout << ", the minimum cost is " << result << endl;
    }

    return 0;
}

