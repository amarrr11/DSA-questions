/*Problem statement
You are given a 2D array with dimensions ‘N*M’. You need to read the array elements row-wise and return a linear 
array that stores the elements like a wave i.e the 1st-row elements are stored from left to right, 2nd-row elements
are stored from right to left, and so on.*/


#include <iostream>
#include <vector>
using namespace std;


vector<int> rowWaveForm(vector<vector<int>> &mat) {
    int n = mat.size(); 
    int m = mat[0].size(); 

    int top = 0; // Index of the top row
    int bottom = n - 1; // Index of the bottom row

    vector<int> ans; // Vector to store the wave form

    // Iterate through the rows in the matrix
    while (top <= bottom) {
        // Iterate through the columns in the current row
        for (int i = 0; i < m; i++) {
            ans.push_back(mat[top][i]); // Add elements from left to right
        }
        top++; // Move to the next row

        // Check if there are more rows to iterate through
        if (top <= bottom) {
            // Iterate through the columns in the current row in reverse order
            for (int i = m - 1; i >= 0; i--) {
                ans.push_back(mat[top][i]); // Add elements from right to left
            }
            top++; // Move to the next row
        }
    }

    return ans; 
}

int main() {
 
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};


    vector<int> result = rowWaveForm(matrix);


    cout << "Row-wise wave form: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
