// // // Online C++ compiler to run C++ program online
// // #include <bits/stdc++.h>
// // using namespace std;

// // int solve(vector<int> &v){
// //     if(v.size()<=3) return 0;
// //     int cnt=0;
// //     for(int i=0;i<v.size()-3;i++){
// //         if(v[i]==1 and v[i+1]==5 and v[i+2]==4 and v[i+3]==3){
// //             cnt++;
// //         }
// //     }
// //     return cnt;
// // }

// // int main() {
// //      ios::sync_with_stdio(0);
// // 	cin.tie(0);
// //     int t;
// //     cin>>t;
// //     while(t--){
// //         int n,m;
// //         cin>>n>>m;
// //         vector<vector<int>> mat(n,vector<int>(m));
// //         for(int i = 0; i < n; ++i) {
// //             for(int j = 0; j < m; ++j) {
// //                 cin >> mat[i][j];
// //             }
// //         }
// //         int ans=0;
// //         int total=n*m;
// //         int top=0;
// //         int bottom=n-1;
// //         int left=0;
// //         int right=m-1;
// //         while(top<=bottom and left<=right and total>=4){
// //             vector<int> v;
// //             for(int j=left;j<=right;j++){
// //                 v.push_back(mat[top][j]);
// //             }
// //             top++;
// //             for(int i=top;i<=bottom;i++){
// //                 v.push_back(mat[i][right]);
// //             }
// //             right--;
// //             for(int i=right;i>=left;i--){
// //                 v.push_back(mat[bottom][i]);
// //             }
// //             bottom--;
// //             for(int i=bottom;i>=top;i--){
                
// //                 v.push_back(mat[i][left]);
// //             }
// //             left++;
// //             ans+=solve(v);
// //             total-=(v.size());
// //         }
// //         cout<<ans<<endl;
// //     }
    
// //     return 0;
// // }
// #include <bits/stdc++.h>
// using namespace std;

// int solve(vector<int> &v) {
//     if (v.size() < 4) return 0; // Change from <= 3 to < 4
//     int cnt = 0;
//     for (int i = 0; i <= v.size() - 4; i++) { // Adjust loop condition to allow for checking 4 elements
//         if (v[i] == 1 && v[i + 1] == 5 && v[i + 2] == 4 && v[i + 3] == 3) {
//             cnt++;
//         }
//     }
//     return cnt;
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, m;
//         cin >> n >> m;
//         vector<vector<int>> mat(n, vector<int>(m));
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < m; ++j) {
//                 cin >> mat[i][j];
//             }
//         }
//         int ans = 0;
//         int total = n * m;
//         int top = 0;
//         int bottom = n - 1;
//         int left = 0;
//         int right = m - 1;
        
//         // Change the while loop condition to check if total is >= 4
//         while (top <= bottom && left <= right && total >= 4) {
//             vector<int> v;
//             for (int j = left; j <= right; j++) {
//                 v.push_back(mat[top][j]);
//             }
//             top++;
//             for (int i = top; i <= bottom; i++) {
//                 v.push_back(mat[i][right]);
//             }
//             right--;
//             if (top <= bottom) { // Check boundary
//                 for (int i = right; i >= left; i--) {
//                     v.push_back(mat[bottom][i]);
//                 }
//                 bottom--;
//             }
//             if (left <= right) { // Check boundary
//                 for (int i = bottom; i >= top; i--) {
//                     v.push_back(mat[i][left]);
//                 }
//                 left++;
//             }
//             ans += solve(v);
//             total -= v.size();
//         }
//         cout << ans << endl;
//     }
    
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &v) {
    if (v.size() < 4) return 0;
    int cnt = 0;
    for (int i = 0; i <= v.size() - 4; i++) {
        if (v[i] == 1 && v[i + 1] == 5 && v[i + 2] == 4 && v[i + 3] == 3) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> mat[i][j];
            }
        }
        int ans = 0;
        int top = 0, bottom = n - 1, left = 0, right = m - 1;

        // Process until the matrix is completely traversed
        while (top <= bottom && left <= right) {
            vector<int> v;
            // Top row
            for (int j = left; j <= right; j++) {
                v.push_back(mat[top][j]);
            }
            top++;
            // Right column
            for (int i = top; i <= bottom; i++) {
                v.push_back(mat[i][right]);
            }
            right--;
            // Bottom row
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    v.push_back(mat[bottom][j]);
                }
                bottom--;
            }
            // Left column
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    v.push_back(mat[i][left]);
                }
                left++;
            }
            // Count sequences in the collected vector
            ans += solve(v);
        }
        cout << ans << endl; // Output the result for each test case
    }
    return 0;
}
