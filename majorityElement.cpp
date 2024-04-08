// 169. Majority Element

// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Moore's Voting Algorithm

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int el;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt==0){ //got cancelled
                el=nums[i];
                cnt++;
            }
            else if(nums[i]==el){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el){
                count++;
            }
        }
        if(count>(n/2)){
            return el;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 3, 2, 4, 2, 2}; // Example input
    cout << "Majority element: " << sol.majorityElement(nums) << endl;
    return 0;
}
