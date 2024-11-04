#include <bits/stdc++.h>
using namespace std;


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
        while (top <= bottom && left <= right) {
            
            string s="";
            
            for (int j = left; j <= right; j++) {
                s+=(mat[top][j]+'0');
            }
            top++;


            for (int i = top; i <= bottom; i++) {
                s+=(mat[i][right]+'0');
            }
            right--;


            if (top <= bottom) {
                
                for (int i = right; i >= left; i--) {
                    s+=(mat[bottom][i]+'0');
                }
                bottom--;
            }

            if (left <= right) {
                
                for (int i = bottom; i >= top; i--) {
                    s+=(mat[i][left]+'0');
                }
                left++;
            }
            s += s.substr(0, 3);
            for (int i = 0; i <= int(s.size()) - 4; i++) {
                if (s.substr(i, 4) == "1543") {
                ans += 1;
                }
            }
            
        }
        

        cout << ans << endl;
    }

    return 0;
}
