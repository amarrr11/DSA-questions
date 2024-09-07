/*73. Set Matrix Zeroes

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        bool rowZero = false, colZero = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    if (i == 0) rowZero = true;
                    if (j == 0) colZero = true;
                    mat[0][j] = 0;
                    mat[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[0][j] == 0 || mat[i][0] == 0) {
                    mat[i][j] = 0;
                }
            }
        }

        if (rowZero) {
            for (int i = 0; i < m; i++) {
                mat[0][i] = 0;
            }
        }
        if (colZero) {
            for (int i = 0; i < n; i++) {
                mat[i][0] = 0;
            }
        }

        //make 2 vectors and keep the track of which ith and jth row or column has 0 in them .
        // vector<int> row(n);
        // vector<int> col(m);

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(mat[i][j]==0){ row[i]=1; col[j]=1;}
        //     }
        // }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(row[i] or col[j]) {
        //             mat[i][j]=0;
        //         }
        //     }
        // }

        //BRUTE FORCE 

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(mat[i][j]==0){
        //             for(int k=0;k<n;k++){
        //                 if(mat[k][j]!=0 ) mat[k][j]=-191;
        //             }
        //             for(int l=0;l<m;l++){
        //                 if(mat[i][l]!=0 ) mat[i][l]=-191;
        //             }
        //         }
        //     }
        // }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(mat[i][j]==-191) mat[i][j]=0;
        //     }
        // }
    }
};

int main() {
    Solution solution;
    vector<vector<int>> mat = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    solution.setZeroes(mat);

    for (const auto& row : mat) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
