/*
How many binary string of length n with no consecutive 1s
*/

#include <bits/stdc++.h>
using namespace std;

// Recursive function to count binary strings of length n with no consecutive 1s
// int countBinaryStrings(int n) {
//     // Base cases
//     if (n == 0) return 1;  // There's one valid string of length 0: the empty string
//     if (n == 1) return 2;  // Two valid strings of length 1: "0" and "1"

//     // Recurrence relation: countBinaryStrings(n) = countBinaryStrings(n-1) + countBinaryStrings(n-2)
//     return countBinaryStrings(n - 1) + countBinaryStrings(n - 2);
// }

// int main() {
//     int n;
//     cout << "Enter the length of the binary string: ";
//     cin >> n;

//     cout << "Number of binary strings of length " << n << " with no consecutive 1s: "
//          << countBinaryStrings(n) << endl;

//     return 0;
// }


/*
Count binary strings of n all prefix should have more or equal 0s than 1s
*/

#include<bits/stdc++.h>
using namespace std;
vector<string> ans;
vector<string> solve(int n,string temp,int zeros,int ones){
    if(temp.size()==n){
        ans.push_back(temp);
        return {};
    }
    if(zeros==ones){
        return solve(n,temp+'0',zeros+1,ones);
    }else{
    return max(solve(n,temp+'1',zeros,ones+1),solve(n,temp+'0',zeros+1,ones));
        // return solve(n,temp+'1',zeros,ones+1);
        // return solve(n,temp+'0',zeros+1,ones);
    }
}

int main(){
 
    // int n;
    // cin>>n;
    solve(4,"",0,0);
    for(auto &s:ans){
        cout<<s<<endl;
    }
}
