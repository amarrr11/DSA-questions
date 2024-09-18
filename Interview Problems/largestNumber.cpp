/*179. Largest Number

Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

Since the result may be very large, so you need to return a string instead of an integer.

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans;
        vector<string> v;
        for(int num:nums){
            v.push_back(to_string(num));
        }
        sort(v.begin(),v.end(),[](string a,string b){
            return (a+b) > (b+a);
        });
        for(auto &it:v){
            ans += it;
        }
        if(ans[0] == '0') return "0";
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 30, 34, 5, 9};
    
    string result = sol.largestNumber(nums);
    
    cout << "Largest number: " << result << endl;
    
    return 0;
}
