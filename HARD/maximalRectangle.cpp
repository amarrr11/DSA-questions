/*
85. Maximal Rectangle

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

*/

#include <iostream>
#include <vector>
#include <climits>
#include <stack>
using namespace std;

class Solution {
public:
    int maxAreaHistogram(vector<int> &arr){
        stack<int> s;
        int n=arr.size();
        vector<int> leftsmall(n);
        vector<int> rightsmall(n);
        for(int i=0;i<n;i++){
            while(!s.empty() and arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                leftsmall[i]=0;
            }else{
                leftsmall[i]=s.top()+1;
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();

        for(int i=n-1;i>=0;i--){
            while(!s.empty() and arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                rightsmall[i]=n-1;
            }else{
                rightsmall[i]=s.top()-1;
            }
            s.push(i);
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]*(rightsmall[i]-leftsmall[i]+1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& mat) {
        int maxi=INT_MIN;
        int n=mat.size();
        int m=mat[0].size();
        vector<int> histogram(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]=='1'){
                    histogram[j]++;
                }else{
                    histogram[j]=0;
                }
            }
            maxi=max(maxi,maxAreaHistogram(histogram));
        }
        return maxi;
    }
};

int main() {
    Solution sol;

    // Example usage
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    int maxRectangleArea = sol.maximalRectangle(matrix);
    cout << "Maximum area of rectangle in the given matrix: " << maxRectangleArea << endl;

    return 0;
}
