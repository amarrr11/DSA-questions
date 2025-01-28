/*Given 3 strings tell stering 3 is made up of string 1 and 2*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[101][101][201];
    bool solve(string &s1,string &s2, string &s3,int i,int j,int k) {
        
        if(i==s1.size() and j==s2.size() and k==s3.size()){
            return true;
        }

        if(k>=s3.size()){
            return false;
        }

        if(dp[i][j][k]!=-1) return dp[i][j][k];

       int res=false;

       if(s1[i]==s3[k]){
            res= solve(s1,s2,s3,i+1,j,k+1);
            dp[i][j][k]=res;
       }
       if(res==true) return res;
       if(s2[j]==s3[k]){
            res= solve(s1,s2,s3,i,j+1,k+1);
            dp[i][j][k]=res;
       }

    return  dp[i][j][k]=res;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
    
        memset(dp,-1,sizeof(dp));

        if(s1.size()+s2.size()!=s3.size()) return false;

        return solve(s1,s2,s3,0,0,0);
    }
};

int main(){
    string s1="abc";
    string s2="mno";
    string s3="abmnco";
}


