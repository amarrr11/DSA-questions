#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void sortOddEven(vector<int>& nums){
    vector<int> odd;
    vector<int> even;
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] % 2 == 0){
            even.push_back(nums[i]);
        }
        else{
            odd.push_back(nums[i]);
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end(), greater<int>());
    int n = odd.size();
    int m = even.size();
    int j = 0;
    for(int i = 0; i < n; i++){
        cout << odd[i] << " ";
    }
    for(int i = 0; i < m; i++){
        cout << even[i] << " ";
    }
}

int main() {
    vector<int> nums = {5, 2, 9, 4, 7, 6, 1, 8, 3};
    sortOddEven(nums);
    return 0;
}
