#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> ans;
    for (int num = 0; num < 8; num++) {
        vector<int> temp;
        for (int i = 0; i < 3; i++) {
            if (num & (1 << i)) {
                temp.push_back(i); // Store the index 'i'
            }
        }
        ans.push_back(temp);
    }

    for (int i = 0; i < 8; i++) {
        cout << "Subset " << i << ": ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
