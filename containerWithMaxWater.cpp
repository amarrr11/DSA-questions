// 11.Container With Most Water
// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/17/question_11.jpg

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int n = height.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int area = (right - left) * min(height[left], height[right]);
            if (area > maxArea) {
                maxArea = area;
            }
            if (height[left] < height[right]) {  
                left++;
            } else {
                right--;
            }
        }
        return maxArea;
    }
};

int main() {
    // Example usage
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution solution;
    int max_area = solution.maxArea(height);
    cout << "Maximum area: " << max_area << endl;
    return 0;
}
