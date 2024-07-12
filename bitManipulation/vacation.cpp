#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// int vac(int i, int j, vector<vector<int>> &arr) {
//     if (i == arr.size()) return 0;
    

//     if (j == -1) {
//         return max({vac(i+1, 0, arr) + arr[i][0], vac(i+1, 1, arr) + arr[i][1], vac(i+1, 2, arr) + arr[i][2]});
//     } else if (j == 0) {
//         return max(vac(i+1, 1, arr) + arr[i][1], vac(i+1, 2, arr) + arr[i][2]);
//     } else if (j == 1) {
//         return max(vac(i+1, 0, arr) + arr[i][0], vac(i+1, 2, arr) + arr[i][2]);
//     } else {
//         return max(vac(i+1, 0, arr) + arr[i][0], vac(i+1, 1, arr) + arr[i][1]);
//     }
// }

int vac(int i, int j, vector<vector<int>> &arr,vector<vector<int>> &dp) {
    if (i == arr.size()) return 0;
    if(dp[i][j+1] != -1) return dp[i][j+1];

    if (j == -1) {
        return dp[i][j+1] = max({vac(i+1, 0, arr,dp) + arr[i][0], vac(i+1, 1, arr,dp) + arr[i][1], vac(i+1, 2, arr,dp) + arr[i][2]});
    } else if (j == 0) {
        return dp[i][j+1] = max(vac(i+1, 1, arr,dp) + arr[i][1], vac(i+1, 2, arr,dp) + arr[i][2]);
    } else if (j == 1) {
        return dp[i][j+1]=max(vac(i+1, 0, arr,dp) + arr[i][0], vac(i+1, 2, arr,dp) + arr[i][2]);
    } else {
        return dp[i][j+1]=max(vac(i+1, 0, arr,dp) + arr[i][0], vac(i+1, 1, arr,dp) + arr[i][1]);
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(3));

    vector<vector<int>> dp(n, vector<int>(3, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }
    
    // cout << vac(0, -1, arr,dp) << endl;


    int dp[n+1][4];
    dp[n][-1],dp[n][0]=0;dp[n][2]=0;

    for(int i=n-1;i>=0;i--){
        int ans = 0;
        for(int j=-1;j<3;j++){
            if(i!=j){
                
            }
        }
    }
    return 0;
}