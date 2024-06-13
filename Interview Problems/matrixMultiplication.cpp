#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> multiplyMatrices(vector<vector<int>> &mat1, vector<vector<int>> &mat2)
{
    int n1 = mat1.size();
    int n2 = mat2.size();
    int m1 = mat1[0].size();
    int m2 = mat2[0].size();

    vector<vector<int>> ans(n1, vector<int>(m2, 0));
    if(m1 == n2){
        for(int i = 0; i < n1; i++){
            for(int j = 0; j < m2; j++){
                ans[i][j] = 0;
                for(int k = 0; k < m1; k++){
                    ans[i][j] += mat1[i][k] * mat2[k][j];
                }   
            }
        }
    }
    return ans;
}

int main()
{
    int n1, m1, n2, m2;

    // Input dimensions and matrices
    cout << "Enter dimensions of first matrix (rows and columns): ";
    cin >> n1 >> m1;
    vector<vector<int>> mat1(n1, vector<int>(m1));

    cout << "Enter elements of the first matrix:\n";
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < m1; j++){
            cin >> mat1[i][j];
        }
    }

    cout << "Enter dimensions of second matrix (rows and columns): ";
    cin >> n2 >> m2;
    vector<vector<int>> mat2(n2, vector<int>(m2));

    cout << "Enter elements of the second matrix:\n";
    for(int i = 0; i < n2; i++){
        for(int j = 0; j < m2; j++){
            cin >> mat2[i][j];
        }
    }

    // Check if multiplication is possible
    if(m1 != n2) {
        cout << "Matrix multiplication is not possible with these dimensions.\n";
        return 1;
    }

    // Multiply matrices
    vector<vector<int>> result = multiplyMatrices(mat1, mat2);

    // Output result
    cout << "Resultant matrix:\n";
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[0].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
