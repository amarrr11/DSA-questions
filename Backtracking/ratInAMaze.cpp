#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    vector<string> ans;
    
    void solve(vector<vector<int>> &mat,int i,int j,int n,int m,vector<vector<int>> &vis,string s){
        if(i==n-1 and j==m-1){
            ans.push_back(s);
            return;
        }
        
        //down
        if(i+1<n and !vis[i+1][j] and mat[i+1][j]!=0){
            vis[i][j]=1;
            solve(mat,i+1,j,n,m,vis,s+'D');
            vis[i][j]=0;
        }
        
        //up
        if(i-1>=0 and !vis[i-1][j] and mat[i-1][j]!=0){
            vis[i][j]=1;
            solve(mat,i-1,j,n,m,vis,s+'U');
            vis[i][j]=0;
        }
        
        //left
        if(j-1>=0 and !vis[i][j-1] and mat[i][j-1]!=0){
            vis[i][j]=1;
            solve(mat,i,j-1,n,m,vis,s+'L');
            vis[i][j]=0;
        }
        
        //right
        if(j+1<m and !vis[i][j+1] and mat[i][j+1]!=0){
            vis[i][j]=1;
            solve(mat,i,j+1,n,m,vis,s+'R');
            vis[i][j]=0;
        }
        
        
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        int n=mat.size();
        int m=mat[0].size();
        ans.clear();
        vector<vector<int>> vis(n,vector<int>(m,0));
        // string s="";
        solve(mat,0,0,n,m,vis,"");
        return ans;
    }
};


int main() {
    vector<vector<int>> mat = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    vector<string> paths;
    // Creating an instance of the class
    Solution obj;
    paths = obj.findPath(mat);

    if (paths.empty()) {
        cout << "No path found\n";
    } else {
        for (const string &path : paths) {
            cout << path << endl;
        }
    }

    return 0;
}