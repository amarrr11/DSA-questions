/*735. Asteroid Collision

We are given an array asteroids of integers representing asteroids in a row.
For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right,
negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are 
the same size, both will explode. Two asteroids moving in the same direction will never meet.

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.
Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {

        int n=nums.size();
        stack<int> s;
        for(int i=0;i<n;i++){
            bool flag=false;
            while(!s.empty() and nums[i]<0 and s.top()>0){
                int sum=nums[i]+s.top();
                
                if(sum>0){
                    flag=true;
                    break;

                }else if(sum<0){
                    s.pop();
                }else{
                    s.pop();
                    
                    flag=true;
                    break;
                } 
            }
            if(!flag){
                s.push(nums[i]);
            }
        }
        int k=s.size();
        vector<int> ans;
        // for(int i=k-1;i>=0;i--){
        //     ans[i]=(s.top());
        //     s.pop();
        // }
        for(int i=k-1;i>=0;i--){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Example 1
    vector<int> asteroids1 = {5, 10, -5};
    vector<int> result1 = solution.asteroidCollision(asteroids1);
    cout << "Example 1: ";
    for (int i : result1) {
        cout << i << " ";
    }
    cout << endl;

    // Example 2
    vector<int> asteroids2 = {8, -8};
    vector<int> result2 = solution.asteroidCollision(asteroids2);
    cout << "Example 2: ";
    for (int i : result2) {
        cout << i << " ";
    }
    cout << endl;

     // Example 3
    vector<int> asteroids3 = {10, 2, -5};
    vector<int> result3 = solution.asteroidCollision(asteroids3);
    cout << "Example 3: ";
    for (int i : result3) {
        cout << i << " ";
    }
    cout << endl;

    // Example 4
    vector<int> asteroids4 = {-2, -1, 1, 2};
    vector<int> result4 = solution.asteroidCollision(asteroids4);
    cout << "Example 4: ";
    for (int i : result4) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
