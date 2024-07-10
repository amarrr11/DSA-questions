#include<bits/stdc++.h>
using namespace std;

//fibonacii series 
 
// int fibo(int n){ //tc=2^N
//     if(n==1 || n==0) return n;
//     int ans=fibo(n-1)+fibo(n-2);
//     return ans;
// }

//USING DP (memoization) O(n)
/*int fibo(int n,vector<int> &dp){
    if(n==1 || n==0) return n;
    if(dp[n]!=-1) return dp[n];
    dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fibo(n,dp)<<endl;
    return 0;
}
*/

//using iterative (O(n))
int fibo(int n,vector<int> &dp){
    dp[0]=0,dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}


int main(){
    int n;
    cin>>n;
    vector<int> dp(n+1); //dont initiaalize with -1
    cout<<fibo(n,dp)<<endl;
    return 0;
}