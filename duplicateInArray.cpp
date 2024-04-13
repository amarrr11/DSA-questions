// Duplicate In Array
// You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once. There is a single integer value that is present in the array twice. Your task is to find the duplicate integer value present in the array.

// For example:

// Consider ARR = [1, 2, 3, 4, 4], the duplicate integer value present in the array is 4. Hence, the answer is 4 in this case.



#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int findDuplicate(vector<int> &nums) {
    // vector<int> ans;
    int n=nums.size();
    for(int i=0;i<n;i++){
        int num=abs(nums[i]);
        int index=num-1;
        if(nums[index]<0){
            return num;
            // ans.push_back(num);
        }else{
            nums[index]*=-1;
        }
    }
        // return ans;
        return 0;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int duplicate = findDuplicate(arr);
    if (duplicate != 0) {
        cout << "Duplicate element found: " << duplicate << endl;
    } else {
        cout << "No duplicate element found." << endl;
    }

    return 0;
}
