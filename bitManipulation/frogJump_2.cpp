//recusrsion
/*B - Frog 2  


There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is hi 

There is a frog who is initially on Stone 
1. He will repeat the following action some number of times to reach Stone 
N:

If the frog is currently on Stone 
i, jump to one of the following: Stone 
i+1,i+2,…,i+K. Here, a cost of 
∣h 
i
​
 −h 
j
​
 ∣ is incurred, where 
j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches Stone 
N.

Constraints
All values in input are integers.
2≤N≤10 
5
 
1≤K≤100
1≤h 
i
​
 ≤10 
4
 
Input
Input is given from Standard Input in the following format:

N 
K
h 
1
​
  
h 
2
​
  
… 
h 
N
​
 
Output
Print the minimum possible total cost incurred.

Sample Input 1
Copy
5 3
10 30 40 50 20
Sample Output 1
Copy
30
If we follow the path 
1 → 
2 → 
5, the total cost incurred would be 
∣10−30∣+∣30−20∣=30.

Sample Input 2
Copy
3 1
10 20 10
Sample Output 2
Copy
20
If we follow the path 
1 → 
2 → 
3, the total cost incurred would be 
∣10−20∣+∣20−10∣=20.

Sample Input 3
Copy
2 100
10 10
Sample Output 3
Copy
0
If we follow the path 
1 → 
2, the total cost incurred would be 
∣10−10∣=0.

Sample Input 4
Copy
10 4
40 10 20 70 80 10 20 70 80 60
Sample Output 4
Copy
40
If we follow the path 
1 → 
4 → 
8 → 
10, the total cost incurred would be 
∣40−70∣+∣70−70∣+∣70−60∣=40.*/

    #include<bits/stdc++.h>
    using namespace std;

    // int mini(int i,int k,vector<int> &arr){
    //     int n=arr.size();
    //     if(i==n-1) return 0;
    //     int ans=INT_MAX;
    //     for(int j=i;j<=k;j++){
    //         if(i+j<n){
    //             ans=min(ans,mini(i+j,k,arr)+abs(arr[i+j]-arr[i]));
    //         }
    //     }
    //     return ans;
    // }

    int mini(int i, int k, vector<int> &a, vector<int> &dp) {
        if (i == a.size() - 1) return 0;  
        if (dp[i] != -1) return dp[i]; 
        int ans = INT_MAX;              
        for (int j = 1; j <= k; j++) {    
            if (i + j < a.size()) {
                ans = min(ans, func(i + j, k, a, dp) + abs(a[i + j] - a[i]));
            }
        }

    return dp[i]=ans;
    }
    int main(){
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> dp(n+1,-1);
        int ans=mini(0,k,arr,dp);
        cout<<ans;
    }